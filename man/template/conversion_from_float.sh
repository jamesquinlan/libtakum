FULL_FUNCTION_NAME=$(printf "takum%s_from_%s" $BIT_COUNT $FLOAT_NAME)

cat << EOF
.Dd ${MAN_DATE}
.Dt $(printf "%s" "$FULL_FUNCTION_NAME" | tr [:lower:] [:upper:]) 3
.Os "libtakum"
.Sh NAME
.Nm ${FULL_FUNCTION_NAME}
.Nd convert ${FLOAT_LONG_NAME} to a takum${BIT_COUNT}
.Sh SYNOPSIS
.In takum.h
.Ft takum${BIT_COUNT}
.Fn ${FULL_FUNCTION_NAME} "${FLOAT_TYPE} f"
.Sh DESCRIPTION
The
.Fn ${FULL_FUNCTION_NAME}
converts ${FLOAT_LONG_NAME} to a takum${BIT_COUNT}.
.Sh RETURN VALUES
The
.Fn ${FULL_FUNCTION_NAME}
function returns a takum${BIT_COUNT}, and in particular
.Dv TAKUM${BIT_COUNT}_NAR
if
.Va f
is
.Dv NAN .
.Sh SEE ALSO
.Xr libtakum 7
.Sh AUTHORS
.An Laslo Hunhold Aq Mt laslo@hunhold.de
EOF
