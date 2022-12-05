#!/usr/bin/env python

import sys
import yaml

final = { 'connectors' : {}, 'cables': {}, 'connections': [] }

if __name__ == "__main__":
    output_file = sys.argv[0]
    for input_file in sys.argv[1:]:
        with open(input_file) as fp:
            #data = yaml.load(fp)
            data = yaml.safe_load(fp)
            if 'connectors' in data.keys():
                for key, val in data['connectors'].items():
                    final['connectors'][key] = val
            if 'cables' in data.keys():
                for key, val in data['cables'].items():
                    final['cables'][key] = val
            if 'connections' in data.keys():
                for item in data['connections']:
                    final['connections'].append(item)
    yaml.dump(final, sys.stdout)
