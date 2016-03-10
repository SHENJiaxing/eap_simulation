
# eap_simulation
Use hostapd and freeradius server to simulate 802.1x
=======
# how to start
cd hostapd-2.3/hostapd/
make
./hostapd hostapd_eap.conf &&
cd ..
gcc simple_receive.c -o receiver 
./receiver

