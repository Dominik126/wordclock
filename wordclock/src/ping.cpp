#include "ping.h"

//Returns if a smartphone is in the network = somebody is at home
void Devices::isAvailable(){
  const IPAddress ips1(192,168,178,12);
  const IPAddress ips2(192,168,178,13);
  //Check if first smartphone is in the network 
  if(Ping.ping(ips1,2)){
	  Devices::available = true;
	  return;
  }
  //If first phone is not in the network check if second phone is there
  Devices::available = Ping.ping(ips2,2);
}

bool Devices::available = true;

