# Hexagon test #

### Setting it up ###
1. Download the source
 
  `andrey@T430:~$ git clone https://github.com/andrewdupa/hexagon-test.git`
  
2. Download and build google test framework (optional)

```
andrey@T430:~$ cd hexagon-test && git clone https://github.com/google/googletest.git -b v1.16.0 \
&& cd googletest \
&& mkdir build \
&& cd build \
&& cmake .. -DBUILD_GMOCK=OFF \
&& make \
&& cd ../..
```
### Build ###
1. Build a simple test only, which includes two cases for host and resource access parsing and displaying. 
```
andrey@T430:~/hexagon-test$ make test-simple
```
2 Build all test, i.e., simple test, and gtest tests  
```
andrey@T430:~/hexagon-test$ make
```
### Run the tests ###

1. test access hosts
```
andrey@T430:~/hexagon-test$ ./test-simple host
running host access test
sandy.rtptok1.epa.gov 294
e659229.boeing.com 292
wicdgserv.wic.epa.gov 266
keyhole.es.dupont.com 263
dwilson.pr.mcs.net 248
.
.
.
pam2008-mach4.cob.vt.edu 1
reggiano.cs.wisc.edu 1
130.101.13.102 1
corpgate.nt.com 1
powermac6.was.epa.gov 1
193.63.73.69 1
131.120.147.33 1
antelope.rtpndpd.epa.gov 1
156.42.76.162 1
```
1a. test access hosts with timing
```
andrey@T430:~/hexagon-test$ time ./test-simple host
```
2. test access resources
```
andrey@T430:~/hexagon-test$ ./test-simple resource
```
2b. test access resources with timing
```
andrey@T430:~/hexagon-test$ time ./test-simple resource
running resource access test
/Access/chapter1/s3-15.html 1
/305b/images/p10-1.gif 1
/docs/Fall94/metadata.txt.html 1
/305b/images/p8-1.gif 1
.
.
.
ttpd%2fhtdocs%2fEPA%2dTOX%2f1995%2fJune%2fDay%2d09%2findex%2ehtml%04%0aearth1%3a210%05%1c%2fusr1%2fcomwais%2findexes%2fHTDOCS%06%3d0%20%2d928%20%2fusr1%2fhttpd%2fhtdocs%2fEPA%2dTOX%2f1995%2fJune%2fDay%2d09%2findex%2ehtml%07%01%00&seed_words_used=acid&byte_count=928 1
/cgi-bin/waisgate?port=210&ip_address=earth1&database_name=/usr1/comwais/indexes/HTDOCS&headline=Mining%20Waste%20%2d%20Bevill%20Amendment&type=HTML&docid=%01%0aearth1%3a210%02%1c%2fusr1%2fcomwais%2findexes%2fHTDOCS%03%3a0%20%2d5200%20%2fusr1%2fhttpd%2fhtdocs%2fOSWRCRA%2fother%2fmining%2findex%2ehtml%04%0aearth1%3a210%05%1c%2fusr1%2fcomwais%2findexes%2fHTDOCS%06%3a0%20%2d5200%20%2fusr1%2fhttpd%2fhtdocs%2fOSWRCRA%2fother%2fmining%2findex%2ehtml%07%01%00&seed_words_used=mining+silver+waste&byte_count=5200 1
/Access/chapter5/s1-7.html 1


real    0m0.215s
user    0m0.039s
sys     0m0.027s
```
3. run all google tests, which includes 4 cases, host and resource parsing only, and host and resource parsing and displaying
```
andrey@T430:~/hexagon-test$ ./gtest
.
.
.
/cgi-bin/waisgate?port=210&ip_address=earth1&database_name=/usr1/comwais/indexes/HTDOCS&headline=Mining%20Waste%20%2d%20Bevill%20Amendment&type=HTML&docid=%01%0aearth1%3a210%02%1c%2fusr1%2fcomwais%2findexes%2fHTDOCS%03%3a0%20%2d5200%20%2fusr1%2fhttpd%2fhtdocs%2fOSWRCRA%2fother%2fmining%2findex%2ehtml%04%0aearth1%3a210%05%1c%2fusr1%2fcomwais%2findexes%2fHTDOCS%06%3a0%20%2d5200%20%2fusr1%2fhttpd%2fhtdocs%2fOSWRCRA%2fother%2fmining%2findex%2ehtml%07%01%00&seed_words_used=mining+silver+waste&byte_count=5200 1
/Access/chapter5/s1-7.html 1
[       OK ] Hexagon.ResourceAccessParseWithLog (244 ms)
[ RUN      ] Hexagon.HostAccessParseNoLog
[       OK ] Hexagon.HostAccessParseNoLog (24 ms)
[ RUN      ] Hexagon.ResourceAccessParseNoLog
[       OK ] Hexagon.ResourceAccessParseNoLog (37 ms)
[----------] 4 tests from Hexagon (369 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 1 test suite ran. (369 ms total)
[  PASSED  ] 4 tests.
```
