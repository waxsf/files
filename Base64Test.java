import java.util.*;
import java.io.*;
import java.nio.ByteBuffer;
import java.nio.charset.Charset;
import java.util.concurrent.ArrayBlockingQueue;
import org.apache.commons.codec.binary.Base64;

	
public class Base64Test {
	public static void main(String[] args){ 
		String string = "base64 encoded string";
		byte[] b = string.getBytes(Charset.forName("UTF-8"));
		byte[]  bytesEncoded = Base64.encodeBase64(b);
		System.out.print(new String(bytesEncoded));
			 

	} 
	
}
