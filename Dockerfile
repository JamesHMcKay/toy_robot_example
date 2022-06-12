FROM ubuntu:20.04
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    # libboost-all-dev \
    g++ \
    cmake \
    build-essential
WORKDIR /usr/src/app
COPY . .
RUN rm -rf build/
RUN mkdir build

# RUN cd build/
# RUN cmake ..
# RUN make
# RUN make test


CMD ["./robot", "-f", "../test_data/commands_1"]