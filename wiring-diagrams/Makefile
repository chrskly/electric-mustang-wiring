.PHONY: all

all: common drive charge lights full

common:
	python3 merge-yaml.py common.*.yaml > output/common.yaml
	wireviz -o output/common output/common.yaml

drive:
	python3 merge-yaml.py common.*.yaml drive.*.yaml > output/drive.yaml
	wireviz -o output/drive output/drive.yaml

charge:
	python3 merge-yaml.py common.*.yaml charge.*.yaml > output/charge.yaml
	wireviz -o output/charge output/charge.yaml

lights:
	python3 merge-yaml.py common.*.yaml lights.*.yaml > output/lights.yaml
	wireviz -o output/lights output/lights.yaml

full:
	python3 merge-yaml.py common.*.yaml charge.*.yaml drive.*.yaml lights.*.yaml > output/full.yaml
	wireviz -o output/full output/full.yaml

clean:
	rm -rf output/*
