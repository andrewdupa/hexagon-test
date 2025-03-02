# Hexagon test #

* Quick summary
Setup, build, and run hexagon tests.

### Setting it up ###

* Download and build google test framework, i.e, gtest, (optional) 
`git clone https://github.com/google/googletest.git -b v1.16.0 \
&& cd googletest \
&& mkdir build \
&& cd build \
&& cmake .. -DBUILD_GMOCK=OFF \
&& make \
&& cd ../..
`
* Build a simple test only
Run `make test-simple`
* Build a simple test, and gtest tests
Run `make`
* How to run tests
For host accesse test run `./test-simple host`
For Resource accesse test run `./test-simple host`
For google tests, which includes 4 tests, host and resource parsing only, and host and resource parsing and displaying
run `./gtest`
