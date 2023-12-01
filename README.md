# Assignment2_Bankers_Algorithm
<details>
  <summary>What is it about?</summary>
  <p>This program is to understand how deadlock works and how to pervent it.</p>
  <p>It runs though the processes and calculates the needed resources by taking the max resources it requires and subtract it from the allocated resources for each processes.</p>
  <p>If the needed resources is less than the available, it adds the allocated resources to the available resources.
  <p>This program works best on Linux.</p>
</details>
<details>
  <summary>How to run the program</summary>
  <ol>
    <li>Download the "Bankers_Algorithm.c".</li>
    <li>In terminal, set your directory to the location of "Banker's_Algorithm.c".</li>
    <li>Use gcc to complie the source code.</li>
      <ul>
        <li><code>$ gcc Bankers_Algorithm.c -o Bankers_Algorithm</code></li>
      </ul>
    <li>Run the program in terminal by entering the following command. If you closed the terminal or moved the object file, you must set or reset the directory to the location of the object file you just created.</li>
    <ul>
      <li><code>$ ./Bankers_Algorithm</code></li>
    </ul>
  </ol>
</details>
<details>
  <summary>What did I learn?</summary>
  <p>Once I saw how the program was working from the example from geeksforgeeks.org, it made a lot more sense to me.</p>
  <p>It helped me understand how to use flags to keep the system in a safe state and how to determain if the process was in a safe state or not.</p>
  <p>If all the values of <code>f[i]</code> were 1, then the system is in a safe state. If any value in the array was 0 then it was not.</p>
</details>
