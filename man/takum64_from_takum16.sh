export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "64"; fi)
export BIT_COUNT_INPUT="16"

$SH man/template/conversion.sh
