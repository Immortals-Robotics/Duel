# ImmortalsDuel
A program which helps to navigate the immortals robots using the XBox360 remote controller.

Due to the limits of the XBox360 wireless receiver, maximum 4 controllers can navigate the robots simultaneously.

# Setup & Run

## requirements
Install the requirements by issuing the below command:
```
sudo apt-get install cmake g++ git libgtkmm-2.4-dev libprotobuf-dev protobuf-compiler libncurses5-dev libudev-dev

```


## Clone
Navigate to a directory which the source files are going to be downloaded to.
Then clone the files using the below command:
```
git clone https://github.com/Immortals-Robotics/ImmortalsDuel
```

## Build
```
cd ImmortalsDuel
mkdir build
cd build
cmake ..
make
```

## Run
Connect the XBox360 wireless receiver and run the built program:
```
./immortalsDuel
```


