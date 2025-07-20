#!/bin/bash
set -e

# Install dependencies
sudo apt-get update
sudo apt-get install -y build-essential wget python3-pip
pip3 install matplotlib pandas numpy jupyter seaborn

# Install Pin
cd /tmp
wget -q https://software.intel.com/sites/landingpage/pintool/downloads/pin-3.13-98189-g60a6ef199-gcc-linux.tar.gz
tar -xzf pin-3.13-98189-g60a6ef199-gcc-linux.tar.gz
sudo mv pin-3.13-98189-g60a6ef199-gcc-linux /opt/pin
echo 'export PIN_ROOT=/opt/pin' >> ~/.bashrc

# Clone and build Sniper (lightweight version for demo)
git clone --depth 1 https://github.com/snipersim/snipersim.git /tmp/snipersim
cd /tmp/snipersim
make -j2
sudo cp -r . /opt/sniper
echo 'export SNIPER_ROOT=/opt/sniper' >> ~/.bashrc
echo 'export PATH=$SNIPER_ROOT/bin:$PATH' >> ~/.bashrc

echo "Setup complete! Restart terminal to use Sniper commands."