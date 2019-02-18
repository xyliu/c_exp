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
	return b_hyper;

}

void get_hypervisor()
{
	CPUID cpuID(0x40000000); // Get CPU vendor
	string hyper("");
	hyper += string((const char *)&cpuID.EBX(), 4);
	hyper += string((const char *)&cpuID.ECX(), 4);
	hyper += string((const char *)&cpuID.EDX(), 4);
	cout << "hypervisor = " << hyper << endl;
}


int main(int argc, char *argv[]) {
	get_vendor();
	if (is_hypervisor())
		get_hypervisor();
	return 0;
}
