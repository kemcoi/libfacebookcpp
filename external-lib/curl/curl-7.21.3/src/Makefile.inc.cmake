# ./src/Makefile.inc
# Using the backslash as line continuation character might be problematic
# with some make flavours, as Watcom's wmake showed us already. If we
# ever want to change this in a portable manner then we should consider
# this idea (posted to the libcurl list by Adam Kellas):
# SET(CSRC1 file1.c file2.c file3.c)
# SET(CSRC2 file4.c file5.c file6.c)
# SET(CSOURCES ${CSRC1} ${CSRC2})

# libcurl has sources that provide functions named curlx_* that aren't part of
# the official API, but we re-use the code here to avoid duplication.
SET(CURLX_ONES ${CURL_SOURCE_DIR}/lib/strtoofft.c 
	${CURL_SOURCE_DIR}/lib/strdup.c 
	${CURL_SOURCE_DIR}/lib/rawstr.c 
	${CURL_SOURCE_DIR}/lib/nonblock.c)

SET(CURL_CFILES main.c hugehelp.c urlglob.c writeout.c writeenv.c 
	getpass.c homedir.c curlutil.c os-specific.c xattr.c)

SET(CURL_HFILES hugehelp.h setup.h config-win32.h config-mac.h 
	config-riscos.h urlglob.h version.h os-specific.h 
	writeout.h writeenv.h getpass.h homedir.h curlutil.h 
	xattr.h)

SET(curl_SOURCES ${CURL_CFILES} ${CURLX_ONES} ${CURL_HFILES})

