 
import java.util.Scanner;
 
public class Main {
	static boolean visited[];
	static boolean good[];
	static model arr[];
	static int D, E, F, Dp, Ep, res;
	static int prune[][][];
	// static int modelcount[];
	// static String s = "";
 
	Main(int size) {
		visited = new boolean[size];
		good = new boolean[size];
		arr = new model[size];
		prune = new int[D + 1][E + 1][F + 1];
		// modelcount = new int[size];
	}
 
	void manufacturing_util(int profit, int count) {
		int k = profit + D * Dp + E * Ep;
 
		if (k > res) {
			res = k;
		}
		prune[D][E][F] = k;
		boolean done = true;
		for (int i = 0; i < arr.length; i++) {
			model m = arr[i];
			if (possible(D - m.nD, E - m.nE, F - m.nF) && good[i]
					&& prune[D - m.nD][E - m.nE][F - m.nF] < profit + (D - m.nD) * Dp + (E - m.nE) * Ep + m.price) {
 
				if (visited[i] == true) {
					D = D - m.nD;
					E = E - m.nE;
					F = F - m.nF;
					done = false;
					manufacturing_util(profit + m.price, count);
					D = D + m.nD;
					E = E + m.nE;
					F = F + m.nF;
				} else if (count < 3) {
					visited[i] = true;
					D = D - m.nD;
					E = E - m.nE;
					F = F - m.nF;
					done = false;
					manufacturing_util(profit + m.price, count + 1);
					D = D + m.nD;
					E = E + m.nE;
					F = F + m.nF;
					visited[i] = false;
 
				}
			}
		}
	}
 
	boolean possible(int a, int b, int c) {
		if (a < 0 || b < 0 || c < 0)
			return false;
		return true;
	}
 
	public static void main(String args[]) {
 
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			long time = System.currentTimeMillis();
			D = sc.nextInt();
			E = sc.nextInt();
			F = sc.nextInt();
			Dp = sc.nextInt();
			Ep = sc.nextInt();
			int n = sc.nextInt();
			Main t1 = new Main(n);
			for (int i = 0; i < n; i++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				int z = sc.nextInt();
				int price = sc.nextInt();
				if (x * Dp + y * Ep < price)
					good[i] = true;
				arr[i] = new model(x, y, z, price);
			}
			res = 0;
			for (int i = 0; i <= D; i++)
				for (int j = 0; j <= E; j++)
					for (int k = 0; k <= F; k++)
						prune[i][j][k] = -1;
 
			t1.manufacturing_util(0, 0);
			System.out.println("#" + (t + 1) + " " + res);
			System.out.println("#time = " + (double) (System.currentTimeMillis() - time) / 1000);
		}
	}
}
 
class model {
	int nD;
	int nE;
	int nF;
	int price;
 
	model(int nD, int nE, int nF, int price) {
		this.nD = nD;
		this.nE = nE;
		this.nF = nF;
		this.price = price;
	}
 
}