FULL_FUNCTION_NAME=$(printf "takum%s_%s" $BIT_COUNT $FUNCTION_NAME)

cat << EOF
.Dd ${MAN_DATE}
.Dt $(printf "%s" "$FULL_FUNCTION_NAME" | tr [:lower:] [:upper:]) 3
.Os "libtakum"
.Sh NAME
.Nm ${FULL_FUNCTION_NAME}
.Nd compute ${COMPUTE_DESCRIPTION}
.Sh SYNOPSIS
.In takum.h
.Ft $(if [ -n "$RETURN_TYPE_OVERRIDE" ]; then printf "$RETURN_TYPE_OVERRIDE"; else printf "takum${BIT_COUNT}"; fi)
.Fn ${FULL_FUNCTION_NAME} "takum${BIT_COUNT} a" $(if [ -n "$SECOND_ARGUMENT_TYPE" ]; then printf "\"%s b\"" "$SECOND_ARGUMENT_TYPE"; fi)
.Sh DESCRIPTION
The
.Fn ${FULL_FUNCTION_NAME}
function computes $(printf "${COMPUTE_LONG_DESCRIPTION}").
.Sh RETURN VALUES
The
.Fn ${FULL_FUNCTION_NAME}
function returns $(printf "${COMPUTE_LONG_DESCRIPTION}")
as a takum${BIT_COUNT}.$(if [ -n "$NAN_CONDITION" ]; then printf " If $NAN_CONDITION, the function returns\n.Dv TAKUM${BIT_COUNT}_NAR ."; fi)
.Sh SEE ALSO$(if [ -n "$SEE_ALSO" ]; then printf "\n.Xr takum%s_%s 3 ," "$BIT_COUNT" "$SEE_ALSO"; fi)
.Xr libtakum 7
.Sh AUTHORS
.An Laslo Hunhold Aq Mt laslo@hunhold.de
EOF
