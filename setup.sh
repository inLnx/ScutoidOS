echo building cross compiler...
mkdir gcc-build
cd gcc-build
wget https://ftp.gnu.org/gnu/gcc/gcc-14.2.0/gcc-14.2.0.tar.xz
sudo apt install xz-utils
tar -xf gcc-14.2.0.tar.xz
cd ..
wget https://ftp.gnu.org/gnu/binutils/binutils-2.43.tar.xz
tar -xf binutils-2.43.tar.xz
cd binutils-2.43
../binutils-x.y.z/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install
cd gcc-build

