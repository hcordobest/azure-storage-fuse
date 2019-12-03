#!/bin/bash
#build/blobfuse $1 --tmp-path=/tmp/testblob -o attr_timeout=0 -o entry_timeout=0 -o negative_timeout=0 --config-file=connection.cfg --log-level=LOG_DEBUG --use-https=false

build/blobfuse $1 --tmp-path=/tmp/testblob -o attr_timeout=0 -o entry_timeout=0 -o negative_timeout=0 --config-file=connection.cfg --log-level=LOG_DEBUG --use-https=true

