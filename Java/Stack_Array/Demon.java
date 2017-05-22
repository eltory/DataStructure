import java.util.Scanner;

public class Demon {

	public static void main(String[] args) {
		Scanner selNum = new Scanner(System.in);
		Scanner data = new Scanner(System.in);

		while (true) {
			System.out.println("\n Select number ");
			System.out.println("\n ------------- ");
			System.out.println("\n 1. push");
			System.out.println("\n 2. pop");
			System.out.println("\n 3. display");
			System.out.println("\n 4. reset");
			System.out.println("\n 5. exit\n");

			switch (selNum.nextInt()) {
			case 1:
				if (Stack_Array.getInstance().isFull()) {
					System.out.println("\n The stack is already full.\n");
				} else {
					System.out.println("\n Enter the data you want to push into stack : ");
					Stack_Array.getInstance().push(data.nextLine());
				}
				break;
			case 2:
				if (Stack_Array.getInstance().isEmpty()) {
					System.out.println("\n The stack is already empty.\n");
				} else {
					Stack_Array.getInstance().pop();
				}
				break;
			case 3:
				Stack_Array.getInstance().display();
				break;
			case 4:
				Stack_Array.getInstance().reset();
				break;
			case 5:
				System.exit(0);
				break;
			default:
				System.out.println("\n select between number 1 to 5 \n");
				break;
			}
		}
	}
}
