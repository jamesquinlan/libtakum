export TAKUM_TYPE_SUFFIX=$(if [ -n "$TAKUM_TYPE_SUFFIX" ]; then printf "$TAKUM_TYPE_SUFFIX"; else printf "_linear64"; fi)
export COMPUTE_DESCRIPTION="exponential function minus 1 of a linear takum"
export COMPUTE_LONG_DESCRIPTION="e raised to \n.Va a ,\nminus one"
export FUNCTION_NAME="exp_minus_1"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="exp"

$SH man/template/math_function.sh
