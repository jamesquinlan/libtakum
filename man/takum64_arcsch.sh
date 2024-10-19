export TAKUM_TYPE_SUFFIX=$(if [ -n "$TAKUM_TYPE_SUFFIX" ]; then printf "$TAKUM_TYPE_SUFFIX"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the area hyperbolic cosecant of a takum"
export COMPUTE_LONG_DESCRIPTION="the area hyperbolic cosecant of\n.Va a "
export FUNCTION_NAME="arcsch"
export NAN_CONDITION="\n.Va a\nis in zero"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO=""

$SH man/template/math_function.sh
