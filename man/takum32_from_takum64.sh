export BIT_COUNT=$(if [ -n "$BIT_COUNT" ]; then printf "$BIT_COUNT"; else printf "32"; fi)
export BIT_COUNT_INPUT="64"

$SH man/template/conversion.sh
