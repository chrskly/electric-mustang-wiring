
#include <stdio.h>
#include "pico/stdlib.h"

#include "comms.h"
#include "structs.h"

/*
CRC8 crc8;
uint8_t checksum;
const uint8_t finalxor [12] = {0xCF, 0xF5, 0xBB, 0x81, 0x27, 0x1D, 0x53, 0x69, 0x02, 0x38, 0x76, 0x4C};

uint8_t getcheck(CAN_message_t &msg, int id)
{
  unsigned char canmes [11];
  int meslen = msg.len + 1; //remove one for crc and add two for id bytes
  canmes [1] = msg.id;
  canmes [0] = msg.id >> 8;

  for (int i = 0; i < (msg.len - 1); i++)
  {
    canmes[i + 2] = msg.buf[i];
  }
  return (crc8.get_crc8(canmes, meslen, finalxor[id]));
}
*/

// Polling the modules for voltage and temperature readings

void requestModuleData(BatteryModule *module) {
	struct can_frame pollMsg;

	if (module->msgcycle == 0xF) {
		module->msgcycle = 0;
	}

	if (module->nextmsg == 8) {
      module->nextmsg = 0;
      if (module->testcycle < 4)
      {
        module->testcycle++;
      }
    }

    pollMsg.can_id = 0x080 | (module->nextmsg);
    //pollMsg.dlc = 8;
    pollMsg.data[0] = 0x68;
    pollMsg.data[1] = 0x10;
    pollMsg.data[2] = 0x00;

    if (module->testcycle < 3) {
	    pollMsg.data[3] = 0x00;
	    pollMsg.data[4] = 0x00;
	}
	else {
	    pollMsg.data[3] = 0x50; // request voltage and temperature
	    pollMsg.data[4] = 0x00;
	}

	pollMsg.data[5] = 0x00;
	pollMsg.data[6] = module->msgcycle << 4;

	if (module->testcycle == 2) {
	    pollMsg.data[6] = pollMsg.data[6] + 0x04;
	}

	//msg.buf[7] = getcheck(msg, module->nextmsg);

	module->msgcycle ++;
	module->nextmsg ++;

	module->pack->CAN.sendMessage(&pollMsg);

}

bool pollAllModulesForData(struct repeating_timer *t) {
	//requestModuleData(battery->packs);
	return true;
}


void startModulePolling() {
    add_repeating_timer_ms(1000, pollAllModulesForData, NULL, &timer);
}
