import java.util.*;
import java.io.*;
class QuickSort
{
ArrayList&lt;String&gt; names = new ArrayList&lt;String&gt;();
void inserttoList()
{
Scanner in = new Scanner(System.in);
System.out.println(&quot;Storing Names\n&quot;);
do
{
System.out.println(&quot;Enter name&quot;);
names.add(in.nextLine());
System.out.println(&quot;Continue entry ? (y/n)&quot;);
}
while(Character.toLowerCase(in.nextLine().charAt(0))==&#39;y&#39;);
}
void printList()
{
System.out.println(&quot;Printing Stored Names&quot;);
for (String s:names)
{
System.out.print(s+&quot;\t&quot;);
}
System.out.println();
}
void sort(int left,int right)
{
String pivot;
int i,j;
if (left&gt;=right)
return;
pivot = names.get(right);
i = left;
j = right;
while (i&lt;j)
{
while(names.get(i).compareTo(pivot) &lt; 0)
i++;
while(names.get(j).compareTo(pivot) &gt; 0)
j--;
if (i&lt;j);
{
Collections.swap(names, i, j);
}
}
sort(left, j-1);
sort(i+1, right);
}

void startSort()
{
sort(0,(names.size()-1));
System.out.println(&quot;\nSORTING\n&quot;);
}
public static void main(String[] args)
{
Scanner in = new Scanner(System.in);
QuickSort ob = new QuickSort();
ob.inserttoList();
ob.printList();
ob.startSort();
ob.printList();
}
}
