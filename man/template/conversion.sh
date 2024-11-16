FULL_FUNCTION_NAME=$(printf "takum%s_from_takum%s" $TAKUM_TYPE_SUFFIX $TAKUM_TYPE_SUFFIX_INPUT)

cat << EOF
.Dd ${MAN_DATE}
.Dt $(printf "%s" "$FULL_FUNCTION_NAME" | tr [:lower:] [:upper:]) 3
.Os "libtakum"
.Sh NAME
.Nm ${FULL_FUNCTION_NAME}
.Nd convert a takum${TAKUM_TYPE_SUFFIX_INPUT} to a takum${TAKUM_TYPE_SUFFIX}
.Sh SYNOPSIS
.In takum.h
.Ft takum${TAKUM_TYPE_SUFFIX}
.Fn ${FULL_FUNCTION_NAME} "takum${TAKUM_TYPE_SUFFIX_INPUT} t"
.Sh DESCRIPTION
The
.Fn ${FULL_FUNCTION_NAME}
converts a takum${TAKUM_TYPE_SUFFIX_INPUT} to a takum${TAKUM_TYPE_SUFFIX}, properly
rounding and adhering to saturation arithmetic.
.Sh RETURN VALUES
The
.Fn ${FULL_FUNCTION_NAME}
function returns a takum${TAKUM_TYPE_SUFFIX}, and in particular
.Dv TAKUM$(printf "%s" "$TAKUM_TYPE_SUFFIX" | tr [:lower:] [:upper:])_NAR
if
.Va t
is
.Dv TAKUM$(printf "%s" "$TAKUM_TYPE_SUFFIX_INPUT" | tr [:lower:] [:upper:])_NAR .
.Sh SEE ALSO
.Xr libtakum 7
.Sh AUTHORS
.An Laslo Hunhold Aq Mt laslo@hunhold.de
EOF
