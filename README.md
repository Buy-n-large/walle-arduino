# walle-arduino

Code Arduino du projet WALL-E + scripts de compilation et d'upload.

## Prérequis

```bash
brew install arduino-cli        # Mac
arduino-cli core install arduino:avr
arduino-cli lib install "Servo" "Stepper" "Adafruit PWM Servo Driver Library"
```

## Upload vers l'Arduino

```bash
make upload
```

## Contenu

- `walle/` — sketch Arduino principal (écoute commandes série)
- `walle_calibration/` — sketch de calibration des servos
- `Makefile` — compile + upload en une commande
