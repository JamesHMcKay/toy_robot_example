FROM ubuntu:20.04
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    # libboost-all-dev \
    g++ \
    cmake \
    build-essential

WORKDIR /usr/src/app/

COPY . .

RUN mkdir -p docker_build/
WORKDIR /usr/src/app/docker_build/

RUN set -ex;\
    cmake ..; \
    make; \
    make test;


# CMD ["./robot", "-f", "../test_data/commands_1"]
CMD ["make", "test"]