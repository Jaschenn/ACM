// ---------------------------------------------------------------------------- 大数阶乘
import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Main {
    public static void main( String[] args )
    {
        Scanner     cin = new Scanner( System.in );
        int     n   = cin.nextint();
        BigInteger  ans = BigInteger.ONE;
        for ( int i = 1; i <= n; i++ )
            ans = ans.multiply( BigInteger.valueOf( i ) );
        System.out.println( ans );
    }
}

