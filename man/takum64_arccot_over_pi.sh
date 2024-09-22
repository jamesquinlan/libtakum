export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the arccotangent of a takum, divided by π"
export COMPUTE_LONG_DESCRIPTION="the arccotangent of\n.Va a ,\ndivided by π"
export FUNCTION_NAME="arccot_over_pi"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="arccot"

$SH man/template/math_function.sh
