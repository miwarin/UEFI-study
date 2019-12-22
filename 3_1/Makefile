all: fs/EFI/BOOT/BOOTX64.EFI

fs/EFI/BOOT/BOOTX64.EFI: efi.c common.c shell.c main.c graphics.c
	mkdir -p fs/EFI/BOOT
	x86_64-w64-mingw32-gcc -Wall -Wextra -e efi_main -nostdinc -nostdlib \
	-fno-builtin -Wl,--subsystem,10 -o $@ $+

run: fs/EFI/BOOT/BOOTX64.EFI
	# error in debian 10.2 : qemu-system-x86_64: Initialization of device ide-hd failed: Block node is read-only
	#qemu-system-x86_64 -bios /usr/share/ovmf/OVMF.fd -hda fat:fs

	# workaround
	# https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=918950
	qemu-system-x86_64 -bios /usr/share/ovmf/OVMF.fd -hda fat:rw:fs

clean:
	rm -rf *~ fs

.PHONY: clean



