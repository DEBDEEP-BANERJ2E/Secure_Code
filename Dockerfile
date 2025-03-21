# Use an official C++ image
FROM ubuntu:22.04

# Set the working directory
WORKDIR /app

# Install required dependencies
RUN apt update && apt install -y cmake g++ make

# Copy the entire project to the container
COPY . .

# Create a build directory
RUN mkdir -p build

# Move to build directory and compile the project
WORKDIR /app/build
RUN cmake .. && make

# Set the default command to run the executable
CMD ["./bin/Secure_Code"]
