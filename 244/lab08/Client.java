import java.net.*;

public class Client {
    public static void main(String [] args){
	try{
	    int port = Integer.parseInt(args[0]);
	    Socket socket = new Socket(args[1],port);
	    System.err.println("Connected to " + args[1] + " on port " + port);
	    new ReadWriteThread(socket.getInputStream(),System.out).start();
	    new ReadWriteThread(System.in,socket.getOutputStream()).start();
	    // ServerSocket serverSocket = new ServerSocket(port);
	    // System.err.println("Waiting for client to connect");
	    // Socket socket = serverSocket.accept();
	    // System.err.println("Accepted connection on port " + port);

	} catch (Exception e) {
	    e.printStackTrace();
	    System.err.println("\nUsage: java Client <host> <port>");
	}
    }

}
	
