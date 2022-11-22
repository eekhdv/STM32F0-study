#!/bin/sh
ST-LINK_gdbserver -p 61234 -l 1 -d -s -cp $CUBE_DL -m 0 -k
# /home/khadiev/st/stm32cubeide_1.10.1/plugins/com.st.stm32cube.ide.mcu.externaltools.stlink-gdb-server.linux64_2.0.300.202203231527/tools/bin/ST-LINK_gdbserver -p 61234 -l 1 -d -s -cp /home/khadiev/st/stm32cubeide_1.10.1/plugins/com.st.stm32cube.ide.mcu.externaltools.cubeprogrammer.linux64_2.0.301.202207041506/tools/bin -m 0 -g
