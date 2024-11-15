export TAKUM_TYPE_SUFFIX=$(if [ -n "$TAKUM_TYPE_SUFFIX" ]; then printf "$TAKUM_TYPE_SUFFIX"; else printf "_linear64"; fi)
export COMPUTE_DESCRIPTION="the 2-argument arctangent of two linear takums, divided by π"
export COMPUTE_LONG_DESCRIPTION="the 2-argument arctangent of\n.Va a\n and\n.Va b ,\n divided by π"
export FUNCTION_NAME="arctan2_over_pi"
export NAN_CONDITION=""
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=$(if [ -n "$SECOND_ARGUMENT_TYPE" ]; then printf "$SECOND_ARGUMENT_TYPE"; else printf "takum_linear64"; fi)
export SEE_ALSO="arctan2"

$SH man/template/math_function.sh
