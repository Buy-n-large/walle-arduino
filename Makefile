FQBN   = arduino:avr:uno
PORT  ?= /dev/cu.usbmodem14501
SKETCH = walle

compile:
	arduino-cli compile --fqbn $(FQBN) $(SKETCH)

upload: compile
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(SKETCH)

monitor:
	arduino-cli monitor -p $(PORT) --config baudrate=9600

.PHONY: compile upload monitor
