# eap_simulation
It is intended to collect [**imsi**](http://www.telecomabc.com/i/imsi.html) from CMCC users who have enabled **eap-sim** authentication.

It seems only iPhone users can connect CMCC via eap-sim. You may install [this](http://easy.g3quay.net/upload/CMCC-AUTO.mobileconfig) on your iPhone to validate.

As freeradius server is not included in this project, the authentication always fails. But it is enough for getting imsi.

When in Hong Kong, it also works to change the ssid from CMCC to PCCW1x.

# how to start
cd hostapd-2.3/hostapd/  
make  
./hostapd hostapd_eap.conf &&  
cd ..  
gcc simple_receive.c -o receiver  
./receiver  
