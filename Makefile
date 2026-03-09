FQBN   = arduino:avr:uno
SKETCH = walle

# Port auto-détecté selon l'OS
ifeq ($(shell uname),Darwin)
  PORT ?= /dev/cu.usbmodem14501
else
  PORT ?= /dev/ttyACM0
endif

install-cli:
	curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
	arduino-cli core update-index
	arduino-cli core install arduino:avr
	arduino-cli lib install "Servo" "Stepper" "Adafruit PWM Servo Driver Library"

compile:
	arduino-cli compile --fqbn $(FQBN) $(SKETCH)

upload: compile
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(SKETCH)

monitor:
	arduino-cli monitor -p $(PORT) --config baudrate=9600

.PHONY: install-cli compile upload monitor
