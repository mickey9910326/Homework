
function [a,r2,Syx]=PolyReg(x,y,m)
Z = ones(size(x));
for i=1:m
    Z(:,i+1) = x.^(i);
end
a = (Z'*Z)\(Z'*y);
Sr = sum((y-Z*a).^2);
r2 = 1-Sr/sum((y-mean(y)).^2);
Syx =sqrt(Sr/(length(x)-length(a)) );
