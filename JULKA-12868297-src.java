
public class Main {
public static void main(String[] args){
	java.io.BufferedReader br= new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
	for(int i=0;i<10;i++){
		
	try{
	String s=br.readLine();
	java.math.BigInteger t=new java.math.BigInteger(s);
	s=br.readLine();
	java.math.BigInteger d=new java.math.BigInteger(s);
	java.math.BigInteger k=(t.add(d)).divide(new java.math.BigInteger("2"));
	System.out.println(k);
	System.out.println(t.subtract(k));
	}
	catch(java.io.IOException e){
		
	}
	}
}
}
