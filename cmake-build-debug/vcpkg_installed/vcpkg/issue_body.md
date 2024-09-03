Package: libpq[core,lz4,openssl,zlib]:x64-linux@16.4

**Host Environment**

- Host: x64-linux
- Compiler: GNU 13.2.0
-    vcpkg-tool version: 2024-08-01-fd884a0d390d12783076341bd43d77c3a6a15658
    vcpkg-scripts version: f5ec6f30f 2024-08-28 (5 hours ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Using cached postgresql-16.4.tar.bz2.
-- Cleaning sources at /home/omer/.vcpkg-clion/vcpkg/buildtrees/libpq/src/tgresql-16-0b2040c781.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source /home/omer/.vcpkg-clion/vcpkg/downloads/postgresql-16.4.tar.bz2
-- Applying patch unix/installdirs.patch
-- Applying patch unix/fix-configure.patch
-- Applying patch unix/single-linkage.patch
-- Applying patch unix/no-server-tools.patch
-- Applying patch unix/mingw-install.patch
-- Applying patch unix/python.patch
-- Applying patch windows/macro-def.patch
-- Applying patch windows/win_bison_flex.patch
-- Applying patch windows/msbuild.patch
-- Applying patch windows/spin_delay.patch
-- Applying patch android/unversioned_so.patch
-- Using source at /home/omer/.vcpkg-clion/vcpkg/buildtrees/libpq/src/tgresql-16-0b2040c781.clean
-- Found external ninja('1.12.0').
-- Getting CMake variables for x64-linux
CMake Error at scripts/cmake/vcpkg_find_acquire_program.cmake:166 (message):
  Could not find flex.  Please install it via your package manager:

      sudo apt-get install flex
Call Stack (most recent call first):
  buildtrees/versioning_/versions/libpq/dcaa1ec8552b8ef987d6d80f708b8828bcd795eb/portfile.cmake:43 (vcpkg_find_acquire_program)
  scripts/ports.cmake:192 (include)



```

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "name": "cppphonedirection",
  "version-string": "1.0.0",
  "builtin-baseline": "f5ec6f30ff70f04f841436a0f36600bdbabfcfbf",
  "dependencies": [
    {
      "name": "libpqxx",
      "version>=": "7.9.2"
    }
  ]
}

```
</details>
