public class Main {
public static void main(String[] args){
	java.io.BufferedReader reader = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
	String line;
	try{
	while((line=reader.readLine())!=null){
		java.math.BigInteger i = new java.math.BigInteger(line);
		if(i.equals(new java.math.BigInteger("1")))
			System.out.println(1);
		else
		System.out.println(i.add(i.subtract(new java.math.BigInteger("2"))));
	}
	}
	catch(java.io.IOException e){}
}
}
