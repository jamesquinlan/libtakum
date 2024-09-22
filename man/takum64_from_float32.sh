export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export FLOAT_LONG_NAME="an IEEE 754 single-precision floating-point number"
export FLOAT_NAME="float32"
export FLOAT_TYPE="float"

$SH man/template/conversion_from_float.sh
