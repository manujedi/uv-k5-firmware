FROM archlinux:latest
WORKDIR /app
COPY . .
RUN pacman -Syyu base-devel arm-none-eabi-gcc git arm-none-eabi-newlib cmake python python-pip python-crcmod --noconfirm
