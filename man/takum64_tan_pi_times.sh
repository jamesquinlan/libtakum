export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the tangent of π times a takum"
export COMPUTE_LONG_DESCRIPTION="the tangent of π times\n.Va a "
export FUNCTION_NAME="tan_pi_times"
export NAN_CONDITION="" # (n+0.5) is not exactly representable
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="tan"

$SH man/template/math_function.sh
