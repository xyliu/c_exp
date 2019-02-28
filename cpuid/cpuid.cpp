#include "cpuid.h"

#include <iostream>
#include <string>

using namespace std;

void get_vendor()
{
	CPUID cpuID(0); // Get CPU vendor

	string vendor;
	vendor += string((const char *)&cpuID.EBX(), 4);
	vendor += string((const char *)&cpuID.EDX(), 4);
	vendor += string((const char *)&cpuID.ECX(), 4);

	cout << "CPU vendor = " << vendor << endl;
}

int is_hypervisor()
{
	CPUID cpuID(1); // Get CPU vendor

	int b_hyper = cpuID.ECX() >> 31 & 0x1;

	printf("in hypervisor: %c\n", b_hyper? 'Y':'N');
	printf("raw: (EAX,EBX,ECX,EDX)=(%08x,%08x,%08x,%08x)\n",
			cpuID.EAX(),
			cpuID.EBX(),
			cpuID.ECX(),
			cpuID.EDX());
	return b_hyper;

}

void get_hypervisor()
{
	CPUID cpuID(0x40000000); // Get CPU hypervisor
	string hyper("");
	hyper += string((const char *)&cpuID.EBX(), 4);
	hyper += string((const char *)&cpuID.ECX(), 4);
	hyper += string((const char *)&cpuID.EDX(), 4);
	cout << "hypervisor = " << hyper << endl;
}

void get_hypervisor2()
{
	unsigned int base = 0x40000000;

	string old("");

	for (base=0x40000000; base < 0x40010000; base+=0x100) {
		CPUID cpuID(base); // Get CPU hypervisor
		string hyper("");
		hyper += string((const char *)&cpuID.EBX(), 4);
		hyper += string((const char *)&cpuID.ECX(), 4);
		hyper += string((const char *)&cpuID.EDX(), 4);
		if (old.compare(hyper)!=0) {
		   cout << std::hex << base << " hypervisor = " << hyper << endl;
		   old = hyper;
		}
	}
}

int main(int argc, char *argv[]) {
	get_vendor();
	if (is_hypervisor())
		get_hypervisor();
	get_hypervisor2();
	return 0;
}
