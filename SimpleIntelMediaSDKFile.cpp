#include"mfxvideo++.h"
#include<stdio.h>

//Please refer the mediasdk-man.pdf provided under *\IntelSWTools\Intel(R)_Media_SDK_2016.0.2\doc
//The program is meant for educational purposes. At the time it was written the author was learning the...
//used API. The author also asks fellow coders using **Intel Media SDK** to upload their codes...
//which would help the community of developers using this API.
//First written on 31 DEC 2016 at 8:25AM GMT


int main() {
	//Here the version of the API used is defined for the software and hardware version
	mfxVersion SWversion = { 0,1 }, HWversion = { 0,1 }, version;

	//Initializing a session. This should be done for all the programs written using this API
	mfxSession SWsession, HWsession;

	//mfxStatus is used to monitor the progress of program and analyse errors, if any arise.
	//Based on the progress we decide the optimal path for progressing our code(With practice...
	//...this will become clearer)
	mfxStatus sts;

	//Setting the value for 'sts' using MFXInit we initialize the SDK session
	//MFXInit takes following arguments (desired implementation[here we have chosen software]...
	//... , pointer for desired version, pointer for desired session)
	sts = MFXInit(MFX_IMPL_SOFTWARE, &SWversion, &SWsession);

	//Now using the 'sts; we check for errors. As mentioned earlier based on the value of sts...
	//... we allow our program to choose the optimal path for proceeding

	//MFX_ERROR_NONE signifies that there are no error observed by the variable 'sts'
	if (MFX_ERR_NONE == sts)
	{
		//MFXQueryVersion finds out the implementation version of the SDK for a given session
		MFXQueryVersion(SWsession, &version);
		printf("For Software implementation\nSW version: %d.%d \n API level: %d.%d\n\n\n",
			SWversion.Major, SWversion.Minor, version.Major, version.Minor);
	}

	//Repeating the above procedure for hardware based implpementation
	sts = MFXInit(MFX_IMPL_HARDWARE, &HWversion, &HWsession);

	if (MFX_ERR_NONE == sts)
	{
		MFXQueryVersion(HWsession, &version);
		printf("For Hardware implementation\nSW version: %d.%d \n API level: %d.%d\n\n\n",
			HWversion.Major, HWversion.Minor, version.Major, version.Minor);
	}

	//Closing the sessions after they are finished
	MFXClose(SWsession);
	MFXClose(HWsession);
}
