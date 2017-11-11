#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#define DEVICE_FILENAME  "/dev/LED"
int main()
{
	int dev;
	int loop;
	char buf[128];
	dev = open(DEVICE_FILENAME, O_RDWR|O_NDELAY);  // open device
	if (dev >= 0)
	{
		printf("write the 0xf5 to the port J2!\n");
		buf[0]=0xf5;
		write (dev,buf, 1);		// write data in buf into device
		sleep(2);
		printf("write the 0xfa to the port J2!\n");
		buf[0]=0xfa;
		write(dev,buf,1);
		sleep(1);
	} else
	{
		printf("open failure!\n");
	}
	     close(dev);
	     return 0;
}




