export TAKUM_TYPE_SUFFIX=$(if [ -n "$TAKUM_TYPE_SUFFIX" ]; then printf "$TAKUM_TYPE_SUFFIX"; else printf "64"; fi)
export TAKUM_TYPE_SUFFIX_INPUT="_linear64"

$SH man/template/conversion.sh
