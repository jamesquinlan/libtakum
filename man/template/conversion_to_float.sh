FULL_FUNCTION_NAME=$(printf "takum%s_to_%s" $BIT_COUNT $FLOAT_NAME)

cat << EOF
.Dd ${MAN_DATE}
.Dt $(printf "%s" "$FULL_FUNCTION_NAME" | tr [:lower:] [:upper:]) 3
.Os "libtakum"
.Sh NAME
.Nm ${FULL_FUNCTION_NAME}
.Nd convert a takum${BIT_COUNT} to ${FLOAT_LONG_NAME}
.Sh SYNOPSIS
.In takum.h
.Ft ${FLOAT_TYPE}
.Fn ${FULL_FUNCTION_NAME} "takum${BIT_COUNT} t"
.Sh DESCRIPTION
The
.Fn ${FULL_FUNCTION_NAME}
converts a takum${BIT_COUNT} to ${FLOAT_LONG_NAME}.
.Sh RETURN VALUES
The
.Fn ${FULL_FUNCTION_NAME}
function returns a ${FLOAT_TYPE}, the C type representing ${FLOAT_LONG_NAME},
and in particular
.Dv NAN
if
.Va t
is
.Dv TAKUM${BIT_COUNT}_NAR .
.Sh SEE ALSO
.Xr libtakum 7
.Sh AUTHORS
.An Laslo Hunhold Aq Mt laslo@hunhold.de
EOF
