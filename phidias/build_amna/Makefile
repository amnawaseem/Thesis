LN_CORE=$(wildcard .src-core)
ifeq ($(LN_CORE),)
$(error No symlink to Phidias core repository. Please reinitialize build system.)
endif

LN_XML=$(wildcard .src-xml)
ifeq ($(LN_XML),)
$(error No symlink to Phidias xml repository. Please reinitialize build system.)
endif

SRC_CORE=$(shell readlink .src-core)
ifeq ($(SRC_CORE),)
$(error Symlink to Phidias core repository is broken. Please reinitialize build system.)
endif

SRC_XML=$(shell readlink .src-xml)
ifeq ($(SRC_XML),)
$(error Symlink to Phidias xml repository is broken. Please reinitialize build system.)
endif

OUTDIR=$(shell pwd)

all:
	$(MAKE) -C $(SRC_XML)
	$(MAKE) -C $(SRC_XML) O=$(OUTDIR) $(OUTDIR)/.makeconf_checked
	$(MAKE) -C $(SRC_CORE) O=$(OUTDIR)
	$(MAKE) -C $(SRC_XML) O=$(OUTDIR)

clean:
	$(MAKE) -C $(SRC_CORE) O=$(OUTDIR) clean

distclean:
	$(MAKE) -C $(SRC_CORE) O=$(OUTDIR) distclean
	$(MAKE) -C $(XML_CORE) O=$(OUTDIR) distclean

.PHONY: all clean distclean
