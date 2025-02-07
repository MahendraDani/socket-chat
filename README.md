# Client-Server Message Transmission Application over TCP/IP

A minimal implementation of a TCP/IP protocol using socket programming in C to create a message transmission application.

It's surreal that, if two machines are connected over same LAN (mobile hotspot/wifi), a communication can be established between the two machines using sockets without the need of connecting the machines physically with any wire.

## Features
- Uses IPv4 and TCP sockets
- Server listens for connections on port 2000
- Client connects to the server and sends messages
- Supports bidirectional message transmission

## Prerequisites
Ensure you have the following installed on your system:
- GCC compiler
- A Linux or macOS system (Windows users can use WSL or MinGW)

## Setup Instructions

### 1. Clone the Repository
```sh
$ git clone <repository_url>
$ cd <repository_name>
```

### 2. Compile the Server and Client
You can compile manually using `gcc`:
```sh
$ gcc -o server server.c
$ gcc -o client client.c
```

### 3. Run the Server
Start the server first to listen for incoming connections:
```sh
$ ./server
```
The server will bind to port `2000` and wait for connections.

### 4. Run the Client on the Same Machine
Open another terminal and run the client to connect to the server:
```sh
$ ./client
```
You should see a message indicating a successful connection.

### 5. Run the Client on a Different Machine
If you want to run the client on a different machine:
1. Find the server machine's IP address:
   ```sh
   $ ifconfig a | grep inet
   ```
   Look for the appropriate network interface (e.g., `192.168.x.x` on a Wi-Fi network).
2. Modify the `client.c` file to replace `127.0.0.1` with the server's IP address:
   ```c
   char* ip = "192.168.x.x"; // Replace with the server's IP
   ```
3. Recompile the client:
   ```sh
   $ gcc -o client client.c
   ```
4. Run the client on the second machine:
   ```sh
   $ ./client
   ```
5. Ensure both machines are connected to the same network.

### 6. Send Messages
Once the client is connected, you can start sending messages from the client terminal. The server will receive and print them.
To exit, type `exit` and press Enter in the client terminal.

### 7. Close the Server
Once communication is done, stop the server with `Ctrl + C`.

## Troubleshooting
- Ensure both server and client are running on the same network.
- If the server is running on another machine, update the client's IP address accordingly in `client.c`.
- Check if server is bound on port `2000`:
  ```sh
  $ lsof -i :2000
  ```
- If you get permission issues, try running the server with:
  ```sh
  $ sudo ./server
  ```


