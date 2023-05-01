#!/usr/bin/env sh

set -o xtrace

SVG_DIR='./SVG/'
PNG_DIR='./PNG/'

SVGS=$(cd "${SVG_DIR}" && echo *.svg)

RESOLUTION=1024

for SVG in ${SVGS}; do
	OUTPUT_FILENAME=$(echo "${SVG}" | sed -e 's/svg/png/g')
	inkscape -w "${RESOLUTION}" "${SVG_DIR}${SVG}" -o "${PNG_DIR}${OUTPUT_FILENAME}"
done
