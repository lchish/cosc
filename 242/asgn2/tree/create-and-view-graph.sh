#!/usr/bin/env bash

FILENAME=${1:-dot-tree}
dot -Tfig < ${FILENAME} >| ${FILENAME}.fig && \
   fig2dev -L pdf ${FILENAME}.fig ${FILENAME}.pdf && \
   open ${FILENAME}.pdf
