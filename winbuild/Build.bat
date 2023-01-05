:: switch to build dir
cd ../build
:: run cmake
cmake ..
:: run msbuild
msbuild Gameboy.sln
:: switch to original dir
cd ../winbuild