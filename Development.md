# Development

## Prerequisites

Developing on this project requires NVIDIA GPU with Pascal architecture or better.

On Ubuntu 20.04, follow these steps to set up the development environment.

### Install required packages
```bash
sudo apt update
sudo apt install libreadline-dev
```

### Install NVIDIA drivers
```bash
sudo add-apt-repository ppa:graphics-drivers/ppa
sudo apt update
sudo ubuntu-drivers autoinstall
```

### Install CUDA 11.1
```bash
wget https://developer.download.nvidia.com/compute/cuda/11.1.1/local_installers/cuda_11.1.1_455.32.00_linux.run
sudo sh cuda_11.1.1_455.32.00_linux.run
# Follow the command-line prompts, but don't install the driver again.
```

### Install NCCL
```bash
sudo apt-key adv --fetch-keys http://developer.download.nvidia.com/compute/machine-learning/repos/ubuntu1804/x86_64/7fa2af80.pub
wget https://developer.download.nvidia.com/compute/machine-learning/repos/ubuntu2004/x86_64/nvidia-machine-learning-repo-ubuntu2004_1.0.0-1_amd64.deb
sudo dpkg -i nvidia-machine-learning-repo-ubuntu2004_1.0.0-1_amd64.deb
sudo apt update
sudo apt install libnccl2 libnccl-dev
```

### Install CMake
```bash
sudo snap install cmake --classic
```

## Building
```bash
git clone https://github.com/flare-project/flare.git
cd flare
mkdir build
cd build
cmake ..
make -j$(nproc)
```
