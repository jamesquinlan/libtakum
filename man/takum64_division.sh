export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the quotient of two takums"
export COMPUTE_LONG_DESCRIPTION="\n.Va a\ndivided by\n.Va b "
export FUNCTION_NAME="division"
export NAN_CONDITION="\n.Va b\nis zero"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=$(if [ -n "$SECOND_ARGUMENT_TYPE" ]; then printf "$SECOND_ARGUMENT_TYPE"; else printf "takum64"; fi)
export SEE_ALSO=""

$SH man/template/math_function.sh
