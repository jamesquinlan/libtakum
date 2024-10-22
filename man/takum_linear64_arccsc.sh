export TAKUM_TYPE_SUFFIX=$(if [ -n "$TAKUM_TYPE_SUFFIX" ]; then printf "$TAKUM_TYPE_SUFFIX"; else printf "_linear64"; fi)
export COMPUTE_DESCRIPTION="the arccosecant of a linear takum"
export COMPUTE_LONG_DESCRIPTION="the arccosecant of\n.Va a "
export FUNCTION_NAME="arccsc"
export NAN_CONDITION="\n.Va a\nis in (-1, 1)"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE=""
export SEE_ALSO="arccsc_over_pi"

$SH man/template/math_function.sh
