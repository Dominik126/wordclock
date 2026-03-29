#include "ping.h"

//Returns if a smartphone is in the network = somebody is at home
void Devices::isAvailable(){
  const IPAddress ips1(192,168,178,10);
  const IPAddress ips2(192,168,178,11);
  //Check if first smartphone is in the network 
  if(Ping.ping(ips1,2)){
	  Devices::available = true;
	  Devices::notAvailableCnt = 0;
  }
  else if(Ping.ping(ips2,2)){
	  Devices::available = true;
	  Devices::notAvailableCnt = 0;
  }
  else{
	Devices::notAvailableCnt ++;
	if (Devices::notAvailableCnt > 3){
		Devices::available = false;
	}
  }

}

bool Devices::available = true;
int Devices::notAvailableCnt = 0;

