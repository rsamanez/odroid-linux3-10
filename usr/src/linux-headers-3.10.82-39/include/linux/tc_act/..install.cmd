cmd_/home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/tc_act/.install := /bin/bash scripts/headers_install.sh /home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/tc_act /home/jenkins/workspace/deb_kernel_5422/include/uapi/linux/tc_act tc_csum.h tc_gact.h tc_ipt.h tc_mirred.h tc_nat.h tc_pedit.h tc_skbedit.h; /bin/bash scripts/headers_install.sh /home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/tc_act /home/jenkins/workspace/deb_kernel_5422/include/linux/tc_act ; /bin/bash scripts/headers_install.sh /home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/tc_act /home/jenkins/workspace/deb_kernel_5422/include/generated/uapi/linux/tc_act ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/tc_act/$$F; done; touch /home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/tc_act/.install