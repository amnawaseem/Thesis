#!/bin/bash

cd /usr/local/bin/
chmod +x *

./xenstore-chmod -r /local rw
./xenstore-write /local/domain/0/domid 0
./xenstore-write /local/domain/0/name Domain-0
./xenstore-write /local/domain/0/control/shutdown ""
./xenstore-write /local/domain/0/control/feature-poweroff 0
./xenstore-write /local/domain/0/control/feature-halt 0
./xenstore-write /local/domain/0/control/feature-suspend 0
./xenstore-write /local/domain/0/control/feature-reboot 0
./xenstore-write /local/domain/1/device ""
./xenstore-chmod -r /local/domain/1/device rw
./xenstore-write /local/domain/1/device/vif ""
./xenstore-chmod -r /local/domain/1/device/vif rw
./xenstore-write /local/domain/1/device/vif/0 ""
./xenstore-chmod -r /local/domain/1/device/vif/0 rw
./xenstore-write /local/domain/1/device/vif/0/backend-id 0
./xenstore-chmod -r /local/domain/1/device/vif/0/backend-id rw
./xenstore-write /local/domain/1/device/vif/0/mac "D2:A3:CD:27:4A:53"
./xenstore-chmod -r /local/domain/1/device/vif/0/mac rw
./xenstore-write /local/domain/1/device/vif/0/backend "/local/domain/0/backend/vif/1/0"
./xenstore-chmod -r /local/domain/1/device/vif/0/backend rw
./xenstore-write /local/domain/0/backend/vif/1/0/frontend-id 1
./xenstore-write /local/domain/0/backend/vif/1/0/frontend "/local/domain/1/device/vif/0"
./xenstore-write /local/domain/0/backend/vif/1/0/script "/etc/xen/scripts/vif-route"
./xenstore-write /local/domain/0/backend/vif/1/0/handle 0
./xenstore-chmod -r /local/domain/0/backend/vif/1/0 rw
./xenstore-write /local/domain/1/device/vif/0/state 1
./xenstore-write /local/domain/0/backend/vif/1/0/state 1
