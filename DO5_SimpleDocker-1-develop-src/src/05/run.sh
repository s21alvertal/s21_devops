#!/bin/bash

gcc server.c -lfcgi
spawn-fcgi -p 8080 ./a.out
service nginx start
nginx -s reload
while true; do
    sleep 1
done
/bin/bash
