cmd_/home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/caif/.install := /bin/bash scripts/headers_install.sh /home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/caif /home/jenkins/workspace/deb_kernel_5422/include/uapi/linux/caif caif_socket.h if_caif.h; /bin/bash scripts/headers_install.sh /home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/caif /home/jenkins/workspace/deb_kernel_5422/include/linux/caif ; /bin/bash scripts/headers_install.sh /home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/caif /home/jenkins/workspace/deb_kernel_5422/include/generated/uapi/linux/caif ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/caif/$$F; done; touch /home/jenkins/workspace/deb_kernel_5422/debian/linux-headers-3.10.82-39/usr/src/linux-headers-3.10.82-39/include/linux/caif/.install