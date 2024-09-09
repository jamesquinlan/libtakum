# See LICENSE file for copyright and license details
# libtakum - takum arithmetic C99 reference implementation
.POSIX:
.SUFFIXES:

VERSION_MAJOR = 0
VERSION_MINOR = 2
VERSION_PATCH = 2
MAN_DATE = 2024-07-11

include config.mk

VERSION = $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)

BENCHMARK =\
	benchmark/float_to_takum\

EXAMPLE =\
	example/calculator\

GEN =\
	gen/addition\

SRC =\
	src/10_raised\
	src/2_raised\
	src/addition\
	src/arccos\
	src/arccot\
	src/arccsc\
	src/arcosh\
	src/arcoth\
	src/arcsch\
	src/arcsec\
	src/arcsin\
	src/arctan\
	src/arctan2\
	src/arsech\
	src/arsinh\
	src/artanh\
	src/codec\
	src/conversion\
	src/cos\
	src/cot\
	src/cosh\
	src/coth\
	src/csc\
	src/csch\
	src/integer_power\
	src/integer_root\
	src/division\
	src/exp\
	src/hypotenuse\
	src/lb\
	src/lg\
	src/ln\
	src/multiplication\
	src/power\
	src/precision\
	src/sec\
	src/sech\
	src/sin\
	src/sinh\
	src/square_root\
	src/subtraction\
	src/tan\
	src/tanh\

TEST =\
	test/roundtrip\

MAN_TEMPLATE =

MAN3 =

MAN7 =

all: $(MAN3:=.3) $(MAN7:=.7) $(ANAME) $(SONAME)

benchmark/float_to_takum.o: benchmark/float_to_takum.c Makefile config.mk takum.h benchmark/util.h
benchmark/util.o: benchmark/util.c Makefile config.mk takum.h benchmark/util.h
example/calculator.o: example/calculator.c Makefile config.mk takum.h example/util.h
example/util.o: example/util.c Makefile config.mk takum.h example/util.h
gen/addition.o: gen/addition.c Makefile config.mk gen/util.h
gen/util.o: gen/util.c Makefile config.mk gen/util.h
src/addition.o: src/addition.c Makefile config.mk takum.h src/util.h
src/arccos.o: src/arccos.c Makefile config.mk takum.h src/util.h
src/arccot.o: src/arccot.c Makefile config.mk takum.h src/util.h
src/arccsc.o: src/arccsc.c Makefile config.mk takum.h src/util.h
src/arcosh.o: src/arcosh.c Makefile config.mk takum.h src/util.h
src/arcoth.o: src/arcoth.c Makefile config.mk takum.h src/util.h
src/arcsch.o: src/arcsch.c Makefile config.mk takum.h src/util.h
src/arcsec.o: src/arcsec.c Makefile config.mk takum.h src/util.h
src/arcsin.o: src/arcsin.c Makefile config.mk takum.h src/util.h
src/arctan.o: src/arctan.c Makefile config.mk takum.h src/util.h
src/arctan2.o: src/arctan2.c Makefile config.mk takum.h src/util.h
src/arsech.o: src/arsech.c Makefile config.mk takum.h src/util.h
src/arsinh.o: src/arsinh.c Makefile config.mk takum.h src/util.h
src/artanh.o: src/artanh.c Makefile config.mk takum.h src/util.h
src/codec.o: src/codec.c Makefile config.mk takum.h src/util.h
src/conversion.o: src/conversion.c Makefile config.mk takum.h src/util.h
src/cos.o: src/cos.c Makefile config.mk takum.h src/util.h
src/cot.o: src/cot.c Makefile config.mk takum.h src/util.h
src/cosh.o: src/cosh.c Makefile config.mk takum.h src/util.h
src/coth.o: src/coth.c Makefile config.mk takum.h src/util.h
src/csc.o: src/csc.c Makefile config.mk takum.h src/util.h
src/csch.o: src/csch.c Makefile config.mk takum.h src/util.h
src/division.o: src/division.c Makefile config.mk takum.h src/util.h
src/exp.o: src/exp.c Makefile config.mk takum.h src/util.h
src/exp2.o: src/exp2.c Makefile config.mk takum.h src/util.h
src/exp10.o: src/exp10.c Makefile config.mk takum.h src/util.h
src/hypotenuse.o: src/hypotenuse.c Makefile config.mk takum.h src/util.h
src/lb.o: src/lb.c Makefile config.mk takum.h src/util.h
src/lg.o: src/lg.c Makefile config.mk takum.h src/util.h
src/ln.o: src/ln.c Makefile config.mk takum.h src/util.h
src/multiplication.o: src/multiplication.c Makefile config.mk takum.h src/util.h
src/power.o: src/power.c Makefile config.mk takum.h src/util.h
src/sec.o: src/sec.c Makefile config.mk takum.h src/util.h
src/sech.o: src/sech.c Makefile config.mk takum.h src/util.h
src/sin.o: src/sin.c Makefile config.mk takum.h src/util.h
src/sinh.o: src/sinh.c Makefile config.mk takum.h src/util.h
src/square_root.o: src/square_root.c Makefile config.mk takum.h src/util.h
src/subtraction.o: src/subtraction.c Makefile config.mk takum.h src/util.h
src/tan.o: src/tan.c Makefile config.mk takum.h src/util.h
src/tanh.o: src/tanh.c Makefile config.mk takum.h src/util.h
src/util.o: src/util.c Makefile config.mk takum.h src/util.h
test/roundtrip.o: test/roundtrip.c Makefile config.mk takum.h test/util.h
test/util.o: test/util.c Makefile config.mk takum.h test/util.h

benchmark/float_to_takum$(BINSUFFIX): benchmark/float_to_takum.o benchmark/util.o $(ANAME)
example/calculator$(BINSUFFIX): example/calculator.o example/util.o $(ANAME)
gen/addition$(BINSUFFIX): gen/addition.o gen/util.o $(ANAME)
test/roundtrip$(BINSUFFIX): test/roundtrip.o test/util.o $(ANAME)

gen/addition.h: gen/addition$(BINSUFFIX)

man/x.3: man/x.sh Makefile config.mk

man/x.7: man/x.sh Makefile config.mk

$(GEN:=.o) gen/util.o:
	$(BUILD_CC) -c -o $@ $(BUILD_CPPFLAGS) $(BUILD_CFLAGS) $(@:.o=.c)

$(BENCHMARK:=.o) benchmark/util.o $(EXAMPLE:=.o) example/util.o $(TEST:=.o) test/util.o:
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $(@:.o=.c)

$(SRC:=.o) src/util.o:
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $(SHFLAGS) $(@:.o=.c)

$(BENCHMARK:=$(BINSUFFIX)):
	$(CC) -o $@ $(LDFLAGS) $(@:$(BINSUFFIX)=.o) benchmark/util.o $(ANAME) $(LDLIBS)

$(EXAMPLE:=$(BINSUFFIX)):
	$(CC) -o $@ $(LDFLAGS) $(@:$(BINSUFFIX)=.o) example/util.o $(ANAME) $(LDLIBS)

$(GEN:=$(BINSUFFIX)):
	$(BUILD_CC) -o $@ $(BUILD_LDFLAGS) $(@:$(BINSUFFIX)=.o) gen/util.o $(BUILD_LDLIBS)

$(TEST:=$(BINSUFFIX)):
	$(CC) -o $@ $(LDFLAGS) $(@:$(BINSUFFIX)=.o) test/util.o $(ANAME) $(LDLIBS)

$(GEN:=.h):
	$(@:.h=$(BINSUFFIX)) > $@

$(ANAME): $(SRC:=.o) src/util.o
	$(AR) -rc $@ $?
	$(RANLIB) $@

$(SONAME): $(SRC:=.o) src/util.o
	$(CC) -o $@ $(SOFLAGS) $(LDFLAGS) $(SRC:=.o) src/util.o $(LDLIBS)

$(MAN3:=.3):
	SH="$(SH)" MAN_DATE="$(MAN_DATE)" $(SH) $(@:.3=.sh) > $@

$(MAN7:=.7):
	SH="$(SH)" MAN_DATE="$(MAN_DATE)" $(SH) $(@:.7=.sh) > $@

benchmark: $(BENCHMARK:=$(BINSUFFIX))
	for m in $(BENCHMARK:=$(BINSUFFIX)); do ./$$m; done

example: $(EXAMPLE:=$(BINSUFFIX))

check: test

test: $(TEST:=$(BINSUFFIX))
	for m in $(TEST:=$(BINSUFFIX)); do ./$$m; done

install: all
	mkdir -p "$(DESTDIR)$(LIBPREFIX)"
	mkdir -p "$(DESTDIR)$(LICPREFIX)/libtakum"
	mkdir -p "$(DESTDIR)$(INCPREFIX)"
	mkdir -p "$(DESTDIR)$(MANPREFIX)/man3"
	mkdir -p "$(DESTDIR)$(MANPREFIX)/man7"
	cp -f LICENSE "$(DESTDIR)$(LICPREFIX)/libtakum"
	#cp -f $(MAN3:=.3) "$(DESTDIR)$(MANPREFIX)/man3"
	#cp -f $(MAN7:=.7) "$(DESTDIR)$(MANPREFIX)/man7"
	cp -f $(ANAME) "$(DESTDIR)$(LIBPREFIX)"
	cp -f $(SONAME) "$(DESTDIR)$(LIBPREFIX)/$(SONAME)"
	if [ "$(SOSYMLINK)" = "true" ]; then i=0; while [ "$$i" -le $(VERSION_MINOR) ]; do ln -sf "$(SONAME)" "$(DESTDIR)$(LIBPREFIX)/libtakum.so.$(VERSION_MAJOR).$$i"; i=$$((i+1)); done; fi
	if [ "$(SOSYMLINK)" = "true" ]; then ln -sf "$(SONAME)" "$(DESTDIR)$(LIBPREFIX)/libtakum.so.$(VERSION_MAJOR)"; fi
	if [ "$(SOSYMLINK)" = "true" ]; then ln -sf "$(SONAME)" "$(DESTDIR)$(LIBPREFIX)/libtakum.so"; fi
	cp -f takum.h "$(DESTDIR)$(INCPREFIX)"
	if ! [ -z "$(LDCONFIG)" ]; then $(SHELL) -c "$(LDCONFIG)"; fi
	if ! [ -z "$(PCPREFIX)" ]; then mkdir -p "$(DESTDIR)$(PCPREFIX)"; printf "Name: libtakum\nDescription: Takum arithmetic reference implementation\nURL: https://takum.org/\nVersion: $(VERSION)\nCflags: -I$(INCPREFIX)\nLibs: -L$(LIBPREFIX) -ltakum -lm\n" > "$(DESTDIR)$(PCPREFIX)/libtakum.pc"; fi

uninstall:
	for m in $(MAN3:=.3); do rm -f "$(DESTDIR)$(MANPREFIX)/man3/`basename $$m`"; done
	for m in $(MAN7:=.7); do rm -f "$(DESTDIR)$(MANPREFIX)/man7/`basename $$m`"; done
	rm -f "$(DESTDIR)$(LICPREFIX)/libtakum/LICENSE"
	rmdir "$(DESTDIR)$(LICPREFIX)/libtakum"
	rm -f "$(DESTDIR)$(LIBPREFIX)/$(ANAME)"
	rm -f "$(DESTDIR)$(LIBPREFIX)/$(SONAME)"
	if [ "$(SOSYMLINK)" = "true" ]; then i=0; while [ "$$i" -le $(VERSION_MINOR) ]; do rm -f "$(DESTDIR)$(LIBPREFIX)/libtakum.so.$(VERSION_MAJOR).$$i"; i=$$((i+1)); done; fi
	if [ "$(SOSYMLINK)" = "true" ]; then rm -f "$(DESTDIR)$(LIBPREFIX)/libtakum.so.$(VERSION_MAJOR)"; fi
	if [ "$(SOSYMLINK)" = "true" ]; then rm -f "$(DESTDIR)$(LIBPREFIX)/libtakum.so"; fi
	rm -f "$(DESTDIR)$(INCPREFIX)/takum.h"
	if ! [ -z "$(LDCONFIG)" ]; then $(SHELL) -c "$(LDCONFIG)"; fi
	if ! [ -z "$(PCPREFIX)" ]; then rm -f "$(DESTDIR)$(PCPREFIX)/libtakum.pc"; fi

clean:
	rm -f $(BENCHMARK:=.o) benchmark/util.o $(BENCHMARK:=$(BINSUFFIX)) $(EXAMPLE:=.o) example/util.o $(EXAMPLE:=$(BINSUFFIX)) $(GEN:=.h) $(GEN:=.o) gen/util.o $(GEN:=$(BINSUFFIX)) $(SRC:=.o) src/util.o $(TEST:=.o) test/util.o $(TEST:=$(BINSUFFIX)) $(ANAME) $(SONAME) $(MAN3:=.3) $(MAN7:=.7)

dist:
	rm -rf "libtakum-$(VERSION)"
	mkdir "libtakum-$(VERSION)"
	for m in benchmark example gen man man/template src test; do mkdir "libtakum-$(VERSION)/$$m"; done
	cp config.mk configure takum.h LICENSE Makefile README "libtakum-$(VERSION)"
	cp $(BENCHMARK:=.c) benchmark/util.c benchmark/util.h "libtakum-$(VERSION)/benchmark"
	cp $(DATA) "libtakum-$(VERSION)/data"
	cp $(EXAMPLE:=.c) example/util.c example/util.h "libtakum-$(VERSION)/example"
	cp $(GEN:=.c) gen/util.c gen/types.h gen/util.h "libtakum-$(VERSION)/gen"
	cp $(MAN3:=.sh) $(MAN7:=.sh) "libtakum-$(VERSION)/man"
	cp $(MAN_TEMPLATE) "libtakum-$(VERSION)/man/template"
	cp $(SRC:=.c) src/util.h "libtakum-$(VERSION)/src"
	cp $(TEST:=.c) test/util.c test/util.h "libtakum-$(VERSION)/test"
	tar -cf - "libtakum-$(VERSION)" | gzip -c > "libtakum-$(VERSION).tar.gz"
	rm -rf "libtakum-$(VERSION)"

format:
	clang-format -i takum.h $(BENCHMARK:=.c) benchmark/util.c benchmark/util.h $(EXAMPLE:=.c) example/util.c example/util.h $(GEN:=.c) gen/util.c gen/util.h $(SRC:=.c) src/util.h $(TEST:=.c) test/util.c test/util.h

.PHONY: all benchmark check clean dist example format install test uninstall
