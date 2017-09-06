CC := $(CROSS_COMPILE)gcc
OBJCOPY := $(CROSS_COMPILE)objcopy

CMDLINE_CFLAGS := $(CFLAGS)
override CFLAGS := -Wall -Wextra -marm -g3 -O0 $(CMDLINE_CFLAGS)

HDR := exploit.h
SRC := cache.c exploit.c mem_write.c tty.c vecpage_locator.c
OBJ := $(patsubst %.c,%.o,$(SRC))

PAYLOAD_SRC := payload/nopsled.S payload/svc_code.S
PAYLOAD_OBJ := $(patsubst %.S,%.o,$(PAYLOAD_SRC))
PAYLOAD_BIN := $(patsubst %.o,%,$(PAYLOAD_OBJ))

PATCHES := SOLUTION_mem_write.c.patch
PATCHES += SOLUTION_vecpage_locator.c.patch
PATCHES += payload/SOLUTION_svc_code.S.patch

# Phony Rules

.PHONY: all patch_apply patch_unapply patch_test clean

all: exploit test $(PAYLOAD_BIN)

clean:
	rm -f $(OBJ) $(PAYLOAD_OBJ) $(PAYLOAD_BIN) exploit exploit_template.zip test

patch_apply:
	@if ! test -s .patches.applied; then \
		rm -f $(OBJ) $(PAYLOAD_OBJ) test; \
		for P in $(PATCHES); do \
			PF=$${P//SOLUTION_}; PF=$${PF%%.patch}; \
			patch -p0 "$$PF" < "$$P"; \
		done; \
		echo > .patches.applied; \
	else echo "Already applied."; \
	fi

patch_test:
	@if ! test -s .patches.applied; then \
		for P in $(PATCHES); do \
			PF=$${P//SOLUTION_}; PF=$${PF%%.patch}; \
			patch --dry-run -p0 "$$PF" < "$$P"; \
		done; \
	else echo "Cannot test, already applied."; \
	fi

patch_unapply:
	@if test -s .patches.applied; then \
		rm -f $(OBJ) $(PAYLOAD_OBJ) test; \
		for P in $(PATCHES); do \
			PF=$${P//SOLUTION_}; PF=$${PF%%.patch}; \
			patch -R -p0 "$$PF" < "$$P"; \
		done; \
		rm .patches.applied; \
	else echo "Already unapplied."; \
	fi

# Common Targets

$(OBJ): %.o: %.c $(HDR)
	$(CC) $(CFLAGS) $< -c -o $@

$(PAYLOAD_OBJ): %.o: %.S
	$(CC) $(CFLAGS) -c $^ -o $@

$(PAYLOAD_BIN): %: %.o
	$(OBJCOPY) -Obinary $^ $@

# Regular Targets

exploit: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

test: test.c $(HDR)
	$(CC) $(CFLAGS) $< -o $@

# Staff-Only Targets (@students: ignore these)

exploit_template.zip: $(SRC) Makefile $(PAYLOAD_SRC) $(HDR) test.c
	@if test -s .patches.applied; then \
		echo "ERROR: not zipping solution!"; \
		exit 1; \
	fi
	zip -e $@ $^
