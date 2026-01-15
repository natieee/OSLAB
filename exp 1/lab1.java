import java.io.IOException;

class Program
{
	public static void main(String[] args)
	{
		int pid;
		Process process = null;
		
		try
		{
			ProcessBuilder pb = new ProcessBuilder("whoami");
			//process = pb.start();
            process = pb.inheritIO().start();
			pid = (int) process.pid();
		}
		catch (IOException e)
		{
			pid = -1;
		}
		
		if (pid < 0)
		{
			System.out.println("fork failed");
			System.exit(1);
		}
		else if (pid == 0)
		{
			if (process != null)
			{
				try
				{
					process.waitFor();
				}
				catch (InterruptedException e)
				{
				}
			}
			System.exit(0);
		}
		else
		{
			System.out.println("\n Process ID is: " + ProcessHandle.current().pid() + "\n");
			if (process != null)
			{
				try
				{
					process.waitFor();
				}
				catch (InterruptedException e)
				{
				}
			}
			System.exit(0);
		}
	}
}