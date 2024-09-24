export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export FLOAT_LONG_NAME="an IEEE 754 extended precision floating-point number"
export FLOAT_NAME="extended_float"
export FLOAT_TYPE="long double"

$SH man/template/conversion_to_float.sh
