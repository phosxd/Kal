FROM archlinux:latest

WORKDIR /root/Kal
COPY . .

RUN echo 'alias grep="grep --color"' >> /root/.bashrc
RUN echo 'alias ls="ls --color=auto"' >> /root/.bashrc
RUN echo 'PS2="\[\e[01;35m\]~> \[\e[00;39m\]"' >> /root/.bashrc
RUN echo 'PS1="\n\[\e[01;39m\]Kal\[\e[01;31m\] :: \[\e[01;34m\]\w\n\[\e[01;32m\]~>\[\e[00;39m\] "' >> /root/.bashrc

RUN pacman -Syu gcc sudo which neovim --noconfirm
RUN ./build.sh install
RUN ln -s $(which nvim) /usr/local/bin/vi 
RUN ln -s $(which nvim) /usr/local/bin/vim
