export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the arccosecant of a takum"
export COMPUTE_LONG_DESCRIPTION="the arccosecant of\n.Va a "
export FUNCTION_NAME="arccsc"
export NAN_CONDITION="\n.Va a\nis in (-1, 1)"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="arccsc_over_pi"

$SH man/template/math_function.sh
