using System;
using System.Diagnostics;

class Program
{
	static void Main(string[] args)
	{
		int pid;
		Process process = new Process();
		process.StartInfo.FileName = "whoami";
		process.StartInfo.UseShellExecute = false;
		
		try
		{
			process.Start();
			pid = process.Id;
		}
		catch
		{
			pid = -1;
		}
		
		if (pid < 0)
		{
			Console.WriteLine("fork failed");
			Environment.Exit(1);
		}
		else if (pid == 0)
		{
			process.WaitForExit();
			Environment.Exit(0);
		}
		else
		{
			Console.WriteLine("\n Process ID is: {0}\n", Process.GetCurrentProcess().Id);
			process.WaitForExit();
			Environment.Exit(0);
		}
	}
}



