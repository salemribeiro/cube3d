FROM ubuntu:20.04

RUN apt update -y && apt upgrade -y && apt install make clang git ruby ruby-bundler ruby-dev build-essential -y

RUN git clone https://github.com/42Paris/norminette.git ~/.norminette/

RUN cd ~/.norminette/ && bundle

RUN rm ~/.norminette/Gemfile.lock

RUN echo 'alias norminette="~/.norminette/norminette.rb"' >> ~/.bashrc && echo 'gcc=clang' >> ~/.bashrc

RUN ln ~/.norminette/norminette.rb /bin/norminette.rb

COPY ./scripts/norme.sh /bin/norme.sh
COPY ./scripts/maps.sh /bin/maps.sh

