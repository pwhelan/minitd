#include <stdio.h>
#include <stdlib.h>

void mount_system()
{
	system("/bin/mount -t proc proc /proc");
	system("/bin/mount -o remount,ro /");
	system("/bin/mkdir -p /dev/pts");
	system("/bin/mkdir -p /dev/shm");
	system("/bin/mount -a");
}

void set_hostname()
{
	system("/bin/hostname -F /etc/hostname");
}

void init_system()
{
	mount_system();
	set_hostname();
	system("/bin/mount /dev/mmcblk0p3 /mnt -t vfat -o rw,utf8");
	system("/etc/init.d/rcS");
}

int main(int argc, char **argv)
{
	init_system();
}
