export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the binary logarithm of a takum"
export COMPUTE_LONG_DESCRIPTION="the binary, i.e. base 2, logarithm of\n.Va a "
export FUNCTION_NAME="lb"
export NAN_CONDITION="\n.Va a\nis smaller than or equal to zero"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="lb_1_plus"

$SH man/template/math_function.sh
