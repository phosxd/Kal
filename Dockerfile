FROM archlinux:latest

WORKDIR /root/Kal
COPY . .

RUN echo 'set number' >> /root/.vimrc
RUN echo 'set tabstop=4' >> /root/.vimrc
RUN echo 'set noswapfile' >> /root/.vimrc
RUN echo 'set shiftwidth=4' >> /root/.vimrc

RUN echo 'alias grep="grep --color"' >> /root/.bashrc
RUN echo 'alias ls="ls --color=auto"' >> /root/.bashrc
RUN echo 'PS2="\[\e[01;35m\]~> \[\e[00;39m\]"' >> /root/.bashrc
RUN echo 'PS1="\n\[\e[01;39m\]Kal\[\e[01;31m\] :: \[\e[01;34m\]\w\n\[\e[01;32m\]~>\[\e[00;39m\] "' >> /root/.bashrc

RUN pacman -Sy gcc vim nano sudo --noconfirm
RUN ./build.sh install
