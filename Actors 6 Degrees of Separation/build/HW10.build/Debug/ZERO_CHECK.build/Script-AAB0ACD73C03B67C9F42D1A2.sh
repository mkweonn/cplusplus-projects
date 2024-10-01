#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/michellekweon/Documents/GitHub/hw10-michellekweonn
  make -f /Users/michellekweon/Documents/GitHub/hw10-michellekweonn/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/michellekweon/Documents/GitHub/hw10-michellekweonn
  make -f /Users/michellekweon/Documents/GitHub/hw10-michellekweonn/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/michellekweon/Documents/GitHub/hw10-michellekweonn
  make -f /Users/michellekweon/Documents/GitHub/hw10-michellekweonn/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/michellekweon/Documents/GitHub/hw10-michellekweonn
  make -f /Users/michellekweon/Documents/GitHub/hw10-michellekweonn/CMakeScripts/ReRunCMake.make
fi

