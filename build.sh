git clone https://github.com/limine-bootloader/limine.git --branch=v8.x-binary --depth=1
make -C limine
mkdir -p iso_root
mkdir -p iso_root/boot
cp bin/myos iso_root/boot/
mkdir -p iso_root/boot/limine
cp limine/limine-bios.sys limine/limine-bios-cd.bin limine/limine-uefi-cd.bin iso_root/boot/limine/
cp limine.cfg iso_root/
mkdir -p iso_root/EFI/BOOT
cp limine/BOOTX64.EFI iso_root/EFI/BOOT/
cp limine/BOOTIA32.EFI iso_root/EFI/BOOT/
xorriso -as mkisofs -b boot/limine/limine-bios-cd.bin -no-emul-boot -boot-load-size 4 -boot-info-table --efi-boot boot/limine/limine-uefi-cd.bin -efi-boot-part --efi-boot-image --protective-msdos-label iso_root -o image.iso
