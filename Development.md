# Development

## Prerequisites

Developing on this project requires NVIDIA GPU with Pascal architecture or better.

On Ubuntu 18.04, follow these steps to set up the development environment.

### Install required packages
```bash
sudo apt update
sudo apt install \
  autoconf \
  build-essential \
  git \
  libreadline-dev \
  libtool \
  pkg-config \
  software-properties-common \
  ubuntu-drivers-common \
  wget
```

### Install NVIDIA drivers
```bash
sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt update
sudo ubuntu-drivers autoinstall
```

### Install CUDA 10.1
```bash
wget https://developer.nvidia.com/compute/cuda/10.1/Prod/local_installers/cuda_10.1.105_418.39_linux.run
sudo sh cuda_10.1.105_418.39_linux.run
# Follow the command-line prompts, but don't install the driver again.
```

### Install NCCL
```bash
sudo apt-key adv --fetch-keys http://developer.download.nvidia.com/compute/machine-learning/repos/ubuntu1804/x86_64/7fa2af80.pub
wget https://developer.download.nvidia.com/compute/machine-learning/repos/ubuntu1804/x86_64/nvidia-machine-learning-repo-ubuntu1804_1.0.0-1_amd64.deb
sudo dpkg -i nvidia-machine-learning-repo-ubuntu1804_1.0.0-1_amd64.deb
sudo apt update
sudo apt install libnccl2 libnccl-dev
```

### Install gRPC 1.19.1
```bash
git clone -b v1.19.1 https://github.com/grpc/grpc
cd grpc
git submodule update --init
make -j `nproc`
sudo make install
cd third_party/protobuf
sudo make install
```

### Install CMake 3.14.1
```bash
export CMAKE_VERSION="3.14.1"
wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-Linux-x86_64.tar.gz
sudo tar --strip-components=1 -xzvf cmake-${CMAKE_VERSION}-Linux-x86_64.tar.gz -C /usr/local
```

## Building
```bash
git clone https://github.com/flare-project/flare.git
cd flare
mkdir build
cd build
cmake ..
make -j `nproc`
```
