.PHONY: all

all: common drive charge full

common:
	python3 merge-yaml.py common.*.yaml > output/common.yaml
	wireviz -o output/common output/common.yaml

drive:
	python3 merge-yaml.py common.*.yaml drive.*.yaml > output/drive.yaml
	wireviz -o output/drive output/drive.yaml

charge:
	python3 merge-yaml.py common.*.yaml charge.*.yaml > output/charge.yaml
	wireviz -o output/charge output/charge.yaml

full:
	python3 merge-yaml.py common.*.yaml charge.*.yaml drive.*.yaml > output/full.yaml
	wireviz -o output/full output/full.yaml

clean:
	rm -rf output/*
