export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the hyperbolic tangent of a takum"
export COMPUTE_LONG_DESCRIPTION="the hyperbolic tangent of\n.Va a "
export FUNCTION_NAME="tanh"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO=""

$SH man/template/math_function.sh
