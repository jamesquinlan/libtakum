export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="exponential function minus 1 of a takum"
export COMPUTE_LONG_DESCRIPTION="e raised to \n.Va a ,\nminus one"
export FUNCTION_NAME="exp_minus_1"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="exp"

$SH man/template/math_function.sh
