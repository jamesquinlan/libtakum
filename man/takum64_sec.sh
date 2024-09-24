export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the secant of a takum"
export COMPUTE_LONG_DESCRIPTION="the secant of\n.Va a "
export FUNCTION_NAME="sec"
export NAN_CONDITION="" # 1/2 + multiples of π are not exactly representable in any takum type
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="sec_pi_times"

$SH man/template/math_function.sh
