# vbak

### Usage:
```sh
$ vbak      ; output: current backlight percentage
$ vbak 20   ; sets backlight to 20%
$ vbak +10  ; adds 10% to backlight
$ vbak -10  ; subtracts 10% from backlight
```

### Installation:
(warning: I'm lazy - this makefile just builds the thing and moves it to /bin/)

1. You'll need to manually modify the config.h
If You don't know how, You can use this sed command and it SHOULD work 😳:
```sh
sed -i -e "s/intel_backlight/$(ls /sys/class/backlight)/g" ./config.h
```
2.
```sh
make install
```
