FULL_FUNCTION_NAME=$(printf "takum%s_from_takum%s" $BIT_COUNT $BIT_COUNT_INPUT)

cat << EOF
.Dd ${MAN_DATE}
.Dt $(printf "%s" "$FULL_FUNCTION_NAME" | tr [:lower:] [:upper:]) 3
.Os "libtakum"
.Sh NAME
.Nm ${FULL_FUNCTION_NAME}
.Nd convert a takum${BIT_COUNT_INPUT} to a takum${BIT_COUNT}
.Sh SYNOPSIS
.In takum.h
.Ft takum${BIT_COUNT}
.Fn ${FULL_FUNCTION_NAME} "takum${BIT_COUNT_INPUT} t"
.Sh DESCRIPTION
The
.Fn ${FULL_FUNCTION_NAME}
converts a takum${BIT_COUNT_INPUT} to a takum${BIT_COUNT}, properly
rounding and adhering to saturation arithmetic.
.Sh RETURN VALUES
The
.Fn ${FULL_FUNCTION_NAME}
function returns a takum${BIT_COUNT}, and in particular
.Dv TAKUM${BIT_COUNT}_NAR
if
.Va t
is
.Dv TAKUM${BIT_COUNT_INPUT}_NAR .
.Sh SEE ALSO
.Xr libtakum 7
.Sh AUTHORS
.An Laslo Hunhold Aq Mt laslo@hunhold.de
EOF
