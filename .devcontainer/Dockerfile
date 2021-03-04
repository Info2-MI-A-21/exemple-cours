FROM ubuntu:18.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends apt-utils && \
    apt-get install -y git \
                       make \
                       bash \
                       gcc \
                       gdb \
                       build-essential \
                       python3 \
                       wget \
                       python3-pip \
                       clang-format 

ENV LC_ALL=C.UTF-8
ENV LANG=C.UTF-8

RUN pip3 install baygon==0.2.1

ADD .bashrc /root/.bashrc