export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the difference of two takums"
export COMPUTE_LONG_DESCRIPTION="\n.Va a\nminus\n.Va b "
export FUNCTION_NAME="subtraction"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=$(if [ -n "$SECOND_ARGUMENT_TYPE" ]; then printf "$SECOND_ARGUMENT_TYPE"; else printf "takum64"; fi)
export SEE_ALSO=""

$SH man/template/math_function.sh
