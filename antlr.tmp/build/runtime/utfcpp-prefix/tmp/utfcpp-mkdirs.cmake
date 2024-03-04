# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp"
  "/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build"
  "/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix"
  "/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/tmp"
  "/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-stamp"
  "/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src"
  "/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-stamp${cfgdir}") # cfgdir has leading slash
endif()
