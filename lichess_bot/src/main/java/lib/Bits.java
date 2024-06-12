package lib;

public class Bits {

	public static long bitwise_and(long a, long b) {
		return a & b;
	}

	public static long bitwise_not(long a) {
		return ~a;
	}

	public static long bitwise_or(long a, long b) {
		return a | b;
	}

	public static long bitwise_xor(long a, long b) {
		return a ^ b;
	}

	public static long left_shift(long a, int n) {
		return  a << n;
	}

	public static long right_shift(long a, int n) {
		return a >>> n;
	}

	public static long zero() {
		return 0l;
	}
	
	public static String to_binary_string(long a) {
		String binaryString = Long.toBinaryString(a);
		while (binaryString.length() < 64) {
			binaryString = "0" + binaryString;
		}
		return "0b" + binaryString;
	}

}
