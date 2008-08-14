#!/bin/sh

mkdir /opt/mobile_int
cp  /home/rtnpro/summer_project/* /opt/mobile_int/
wvdialconf > /etc/wvdial.conf
cp /etc/wvdial.conf /opt/mobile_int/wvdial.conf.bak

gcc -o /opt/mobile_int/mdialler /opt/mobile_int/sp.c
/opt/mobile_int/mdialler

cp /opt/mobile_int/wvdial.conf /etc/wvdial.conf
