# Development Environment

Developing on flare requires an NVIDIA GPU with Pascal architecture or better.

On a fresh Ubuntu 18.04 installation, follow these steps to set up the development environment.

## Install NVIDIA drivers
```bash
sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt update
sudo ubuntu-drivers autoinstall
```

## Install CUDA 10.1
```bash
wget -O cuda_10.1.105_418.39_linux.run https://developer.nvidia.com/compute/cuda/10.1/Prod/local_installers/cuda_10.1.105_418.39_linux.run
sudo sh cuda_10.1.105_418.39_linux.run
# Follow the command-line prompts, but don't install the driver again.
```

## Install NCCL
```bash
sudo apt-key adv --fetch-keys http://developer.download.nvidia.com/compute/machine-learning/repos/ubuntu1804/x86_64/7fa2af80.pub
wget https://developer.download.nvidia.com/compute/machine-learning/repos/ubuntu1804/x86_64/nvidia-machine-learning-repo-ubuntu1804_1.0.0-1_amd64.deb
sudo dpkg -i nvidia-machine-learning-repo-ubuntu1804_1.0.0-1_amd64.deb
sudo apt update
sudo apt install libnccl2 libnccl-dev
```

## Install CMake 3.14.0
```bash
wget https://github.com/Kitware/CMake/releases/download/v3.14.0/cmake-3.14.0-Linux-x86_64.tar.gz
sudo tar --strip-components=1 -xzf cmake-3.14.0-Linux-x86_64.tar.gz -C /usr/local
```

## Install Protocol Buffers 3.7.0
```bash
sudo apt update
sudo apt install autoconf automake libtool curl make g++ unzip
wget https://github.com/protocolbuffers/protobuf/releases/download/v3.7.0/protobuf-cpp-3.7.0.tar.gz
tar xzvf protobuf-cpp-3.7.0.tar.gz
cd protobuf-3.7.0
./configure
make -j 12
make check -j 12
sudo make install
sudo ldconfig
```

## Install additional packages
```bash
sudo apt update
sudo apt install libreadline-dev
```
