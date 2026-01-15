import os
import sys

pid = os.fork()

if pid < 0:
    print("fork failed")
    sys.exit(1)

elif pid == 0:
    os.execlp("whoami", "1s")
    sys.exit(0)  # runs only if execlp fails

else:
    print(f"\nProcess ID is: {os.getpid()}")
    os.wait()
    sys.exit(0)



