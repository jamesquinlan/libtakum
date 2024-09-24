export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the base 2 exponential function of a takum"
export COMPUTE_LONG_DESCRIPTION="2 raised to \n.Va a "
export FUNCTION_NAME="2_raised"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="2_raised_minus_1"

$SH man/template/math_function.sh