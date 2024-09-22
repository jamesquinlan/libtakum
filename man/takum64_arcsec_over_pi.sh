export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the arcsecant of a takum, divided by π"
export COMPUTE_LONG_DESCRIPTION="the arcsecant of\n.Va a ,\ndivided by π"
export FUNCTION_NAME="arcsec_over_pi"
export NAN_CONDITION="\n.Va a\nis outside [-1, 1]"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="arcsec"

$SH man/template/math_function.sh
