export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export COMPUTE_DESCRIPTION="the integral root of a takum"
export COMPUTE_LONG_DESCRIPTION="the\n.Va b\nth root of\n.Va a "
export FUNCTION_NAME="integer_root"
export NAN_CONDITION="\n.Va a\nand\n.Va b\nare zero, or\n.Va a\nis smaller than zero and\n.Va b\nis even"
export RETURN_TYPE_OVERRIDE=""
export SECOND_ARGUMENT_TYPE="int64_t"
export SEE_ALSO="square_root"

$SH man/template/math_function.sh
