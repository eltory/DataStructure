
import java.util.ArrayList;

public class Stack_Array {

	private int size = 100;
	// private ArrayList stack = new ArrayList();
	private Object[] stack_limit = new Object[size];
	private int top = -1;
	private static Stack_Array demon = new Stack_Array();

	private Stack_Array() {
	};

	public static Stack_Array getInstance() {
		return demon;
	}

	public boolean isFull() {
		return (top == size - 1);
	}

	public boolean isEmpty() {
		return (top == -1);
	}

	public void push(Object data) {
		if (isFull()) {
			System.out.println("\n The stack is already full. \n");
			return;
		}
		stack_limit[++top] = data;
	}

	public void pop() {
		top--;
	}

	public void reset() {
		top = -1;
	}

	public void display() {
		if (isEmpty()) {
			System.out.println("\n The stack is empty. \n");
			return;
		}
		System.out.println("\n [ Stack ] ");
		System.out.println("\n --------- ");
		for (int i = 0; i <= top; ++i) {
			System.out.println("\n | " + stack_limit[i].toString());
		}
	}
}
