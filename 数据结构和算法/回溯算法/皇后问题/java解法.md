```java
public class BootApp {

    public static void main(String[] args) {
        solve();
    }

    public static void solve() {
        long start = System.currentTimeMillis();
        // 输入问题规模
        int n = new Scanner(System.in).nextInt();
        // 全局数组 从1开始 下标为行号，值为列号
        int[] arr = new int[n+1];
        // 记录解的个数
        int count =0;
        // 初始化全局数组
        for(int i =0;i<arr.length;i++){
            arr[i]=0;
        }
        // 从第一行开始
        int x =1;
        // 当行数为0代表结束
        while (x>0){
//            System.out.println(x);
            // 为每一行选皇后位置
            arr[x]++;
            while (arr[x]<=n&&(!check(arr,x))){
                arr[x]++;
            }
            // 如果选定皇后位置的的话，则进行下一步
            // 如果选定不了，之前的选择不正确，需要回溯
            // 如果选择到最后一行，行号不加，等自行回退，另外也可以直接--
            if(arr[x]<=n){
                if(x==n){
                   count++;
                   print(arr);
                   //arr[x]=0;
                   //x--;
                }else{
                    x++;
                }
            }else{
                arr[x]=0;
                x--;
            }
        }
        System.out.println(count);
        long end = System.currentTimeMillis();
        System.out.println("program 运行时间：" + (end - start));
    }

    private static void print(int[] arr){
        for(int i =1;i<arr.length;i++){
            for(int j=1;j<arr.length;j++){
                if(j==arr[i]){
                    System.out.print("x");
                }else{
                    System.out.print("0");
                }
            }
            System.out.println();
        }
        System.out.println();
    }
    private static boolean check(int[] arr,int j){
        for(int i=1;i<j;i++){
            if(Math.abs(i-j)==Math.abs(arr[i]-arr[j])||arr[i]==arr[j]){
                return false;
            }
        }
        return true;
    }
}
```
