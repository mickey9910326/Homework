function y = I_f(x)
    f = @(x) x.*exp(2*x);
    a=0;
    b=3;
    y=0;
    d = (b-a)/x;
    for i=1:x
        y=y+( f(a+(i-1)*d)+f(a+(i)*d) )/2 *d;
    end
end
