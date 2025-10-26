
package Congty;
import java.time.LocalDate;
import java.util.Scanner;
public class CongtyABC {
    protected String ma;
    protected String ten;
    protected int namlam;
    protected int hsl;
    protected int ngaynghi;
    protected static int luongcoban = 1150;
    int year = LocalDate.now().getYear();
    
    
    public CongtyABC(){}
    
    public String getTen()
    {
     return this.ten;  
    }
    
    public void setTen(String ten)
    {
     this.ten=ten;   
    }
    
    public int getHsl()
    {
     return this.hsl;  
    }
    
    public void setHsl(int hsl)
    {
     this.hsl=hsl;   
    }
    public int getNgaynghi()
    {
     return this.ngaynghi;  
    }
    
    public void setNgaynghi(int ngaynghi)
    {
     this.hsl=ngaynghi;   
    }
    public CongtyABC(String ma, String ten, int hsl){
        this.ma =ma;
        this.ten =ten;
        this.hsl=hsl;
    }
    public CongtyABC(String ma, String ten, int hsl, int namlam,int ngaynghi)
    {
        this.ma="001";
        this.ten ="linh";
        this.hsl=2;
        this.namlam=year;
        this.ngaynghi=0;
    }
    
    public float phucap()
    {
     if(year-namlam>5) return ((year-namlam)*luongcoban)/100;   
     return 0;
    }
    
    public String thidua()
    {
     if(ngaynghi<=1) return "A"   ;
     else if(ngaynghi<=3) return "B"   ;
     return "C"   ;
    }
    
    public float hslthidua()
    {
      if(thidua().equals("A"))    return 1;
      else if(thidua().equals("B"))    return (float) 0.75;
      return (float) 0.5;
    }
    public float luong()
    {
        return luongcoban*hsl*hslthidua()+phucap();
    }
    
    public void nhap()
    {
     Scanner sc = new Scanner(System.in)   ;
     this.setTen(sc.nextLine());
     this.setHsl(sc.nextInt());
     this.setNgaynghi(sc.nextInt());
    }
    public void xuat()
    {
      System.out.println("ten"+ ten+"hsl"+hsl+" ngaynghi"+ngaynghi+" luong"+luong())   ;
    }
}
