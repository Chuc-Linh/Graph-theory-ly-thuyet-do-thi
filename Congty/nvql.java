
package Congty;

public class nvql extends CongtyABC{
    protected String chucvu;
    protected String phongban;
    protected int phucapcv;
    
    public nvql()
    {
        this.chucvu ="truongphong";
        this.phongban="hanhchinh";
        this.phucapcv=5;
    }
    public nvql(String ma, String ten, String chucvu,int hsl, int phucapcv)
    {
      super(ma,ten,hsl)  ;
      this.ngaynghi=1;
      this.namlam = year;
      this.chucvu=chucvu;
      this.phucapcv =phucapcv;
    }
    
    @Override 
    public String thidua()
    {
      return "A"   ;
    }
    
    public int phucaplanhdao()
    {
     return phucapcv*luongcoban;   
    }
}
