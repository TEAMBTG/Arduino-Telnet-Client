#include <TelnetClient.h>
#include <SPI.h>
#include <Ethernet.h>


EthernetClient client;                                   
telnetClient tc(client); 

byte clientMAC[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; 
IPAddress clientIp (192, 168, 1, 177); 

//put here your raspberry's ip address
IPAddress raspberryIp (192, 168, 1, 229);    

void setup () { 
                                       
  Serial.begin (115200);                                 
  Ethernet.begin (clientMAC, clientIp);   
  //PUT HERE YOUR USERNAME/PASSWORD
  if(tc.login(raspberryIp, "pi", "raspberry")){        //tc.login(raspberryIp, "pi", "raspberry", 1234) if you want to specify a port different than 23
    tc.sendCommand("ls -l");
    tc.sendCommand("ifconfig");
         
  }
  else{
    Serial.println("login failed");
  }
  tc.disconnect();
}

void loop () {                                         //  run your loop routine
}
