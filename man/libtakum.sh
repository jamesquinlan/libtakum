cat << EOF
.Dd ${MAN_DATE}
.Dt LIBTAKUM 7
.Os libtakum
.Sh NAME
.Nm libtakum
.Nd takum arithmetic library
.Sh SYNOPSIS
.In takum.h

.Fd #typedef takum8
.Fd #typedef takum16
.Fd #typedef takum32
.Fd #typedef takum64

.Fd #define TAKUM8_NAR
.Fd #define TAKUM16_NAR
.Fd #define TAKUM32_NAR
.Fd #define TAKUM64_NAR

.Fd #define TAKUM8_POSITIVE_MINIMUM
.Fd #define TAKUM16_POSITIVE_MINIMUM
.Fd #define TAKUM32_POSITIVE_MINIMUM
.Fd #define TAKUM64_POSITIVE_MINIMUM

.Fd #define TAKUM8_POSITIVE_MAXIMUM
.Fd #define TAKUM16_POSITIVE_MAXIMUM
.Fd #define TAKUM32_POSITIVE_MAXIMUM
.Fd #define TAKUM64_POSITIVE_MAXIMUM
.Sh DESCRIPTION
The
.Nm
library is an ISO C99 implementation of takum arithmetic, an alternative machine number format to IEEE 754 floating-point numbers. The functions contained in this library allow proper conversion from and to IEEE 754 floating-point types and facilitate the computation with takums.
.Pp
The library defines the four types
.Vt takum8 , takum16 , takum32
and
.Vt takum64
for the respective 8-, 16-, 32- and 64-bit takums. Negation negates the represented number. Comparisons (==, <, <=, >=, >) are also well-defined for two takums of the same type. The literal 0 represents zero and can be directly used for assignments and comparisons.
.Pp
Also defined are the positive minimum and maximum representable numbers
for each type, for instance as
.Dv TAKUM8_POSITIVE_MINIMUM
and
.Dv TAKUM8_POSITIVE_MAXIMUM
for
.Vt takum8 .
Given the set of takums is symmetric under negation, the smallest and largest
representable negative numbers are obtained via negation, e.g. for
.Vt takum8
as
.Dv -TAKUM8_POSITIVE_MAXIMUM
and
.Dv -TAKUM8_POSITIVE_MINIMUM .
.Sh SEE ALSO
EOF

# list all manual pages, using a phase-shift to omit a comma for the last entry
LAST_MAN3=""
for man3 in $MAN3_LIST; do
	if [ ! -z $LAST_MAN3 ]; then
		printf ".Xr $man3 3 ,\n"
	fi
	LAST_MAN3=$man3
done
if [ ! -z $LAST_MAN3 ]; then
	printf ".Xr $LAST_MAN3 3\n"
fi

cat << EOF
.Sh AUTHORS
.An Laslo Hunhold Aq Mt laslo@hunhold.de
EOF
