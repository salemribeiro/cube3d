FROM ubuntu:20.04

RUN apt update -y && apt upgrade -y && apt install make clang git ruby ruby-bundler ruby-dev build-essential -y
RUN git clone https://github.com/42Paris/norminette.git ~/.norminette/
RUN cd ~/.norminette/ && bundle
RUN echo 'alias norminette="~/.norminette/norminette.rb"' >> ~/.bashrc && echo 'gcc=clang' >> ~/.bashrc