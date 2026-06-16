Single Robogami module mc_rtc FSM controller
================

## Build
```
mkdir -p build
cd build
cmake ../ -DCMAKE_BUILD_TYPE=RelWithDebInfo
make
sudo make install
```

## Configure
Modify the mc_rtc configuration file `$INSTALL_PREFIX/etc/mc_rtc.yaml` so that is uses the Robogami robot and newly installed RobogamiController:
```
MainRobot: robogami
Enabled: RobogamiController
```

## Run
```
ros2 launch mc_rtc_ticker display.launch
mc_rtc_ticker
```

