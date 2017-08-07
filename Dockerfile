FROM ubuntu
RUN apt-get update
RUN apt-get install \
            build-essential \
            software-properties-common \
            git \
            libblas-dev \
            liblapack-dev \
            emacs \
            -y
