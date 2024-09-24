export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the area hyperbolic secant of a takum"
export COMPUTE_LONG_DESCRIPTION="the area hyperbolic secant of\n.Va a "
export FUNCTION_NAME="arsech"
export NAN_CONDITION="\n.Va a\nis outside (0,1]"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO=""

$SH man/template/math_function.sh
