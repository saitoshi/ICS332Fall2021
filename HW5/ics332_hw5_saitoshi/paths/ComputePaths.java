package paths;

public class ComputePaths {


//inserted code for homework 5 begins
public class Worker implements Runnable {
  //variable declaration
  //integer variable for size
  int size;
  //integer variable to hold start
	int start;
  //integer variable to hold end
	int end;
//public Worker constructor
public Worker(int start, int end, int size) {
		this.start = start;
		this.end = end;
		this.size = size;
	}

	@Override
  //create public run
	public void run() {
    //begin the for loop to do FloydWarshall
		for (int i = start; i < end; i++) {
			new FloydWarshall(size, i).floydWarshall();
		}
	}
    }

    public void compute(int graph_size, int num_threads) {
  // declare the array of threads
	Thread theThread[] = new Thread[num_threads];
  //if the num_threads is not 1  then
	if (num_threads !=1) {
    //set count into 0
		int count = 0;
    //sent rangeTemp into 0
		int rangeTemp = 0;
    //set an integer of array called range with num_threads
		int[] range = new int[num_threads];
    //create the int called temp and set it with 2520/ num_threads
		int temp = 2520/num_threads;
    // create int i with 0
		int i = 0;
    //create the array of range[0] with temp
		range[0] = temp;
    //while the count is not equal to num_threads - 1
		while (count != num_threads - 1) {
      //update rangeTemp with temp
			rangeTemp = temp + rangeTemp;
      //set the range[count] with rangeTemp
			range[count] = rangeTemp;
      //increment count
			count ++;
		}
    //initiate a for loop
		for (i = 0; i < num_threads; i++) {
      //update Thread array
			theThread[i] = new Thread(new Worker(range[i], range[i] + temp, graph_size));
			theThread[i].start();
		}
    //set i into 0
		i = 0;
    //while i is less than num_threads
		while (i < num_threads) {
      //begin try and catch
			try {
				theThread[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
      //increment i
			i++;
		}
	} else {

	// this is where the code created for homework 5 ends 

        	for (long i = 0; i < 2520; i++) {
            		new FloydWarshall(graph_size, i).floydWarshall();
        	}
	}

    }

    public static void main(String[] args) {

        if (args.length != 2) {
            System.err.println("Usage: java ComputePaths <graph size> <# threads>");
            System.exit(1);
        }

        int graph_size = 0;
        int num_threads = 0;
        try {
            graph_size = Integer.parseInt(args[0]);
            num_threads = Integer.parseInt(args[1]);
            if ((graph_size <= 0) || (num_threads < 1)) {
                throw new NumberFormatException();
            }
        } catch (NumberFormatException e) {
            System.err.println("Invalid command-line arguments");
            System.exit(1);
        }

        double now = System.currentTimeMillis();

        new ComputePaths().compute(graph_size, num_threads);

        System.out.println("All graphs computed in " + (System.currentTimeMillis() - now) / 1000 + " seconds");

    }

}
