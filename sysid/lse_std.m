function [theda,Yh,E,E_std,theda_std,theda_cov,E_corrcoef]=lse_std(Y,A,idx)
%function [theda,Yh,E,E_std,theda_std,theda_cov,E_corrcoef]=lse_std(Y,A,idx)   rev tly 97610 712 98113 20120403
% calculate Least Square Estimate of parameter vector theda, 
%  also predition-Yh residualE std_of_error_inY std_of_theda cov_of_theda corrcoef_E
% optionally idx is used as plot index (i.e. x-axis corresponding to each Y)
% Each row of [A Y] is one set of independent observation variables and its outcome with lumped random error
% y = a * x + b + e => Y = A * [a;b] + E, i.e. Y = A*theda + E 
%  => theda=[a;b] =LSE=> inv(A'*A)*A'*Y => Yh= A*theda, E = Y - Yh, stdE_Y=E_std= std(E),
%   => theda_cov = (inv(A'*A) * A' ) * (E*E') * (A*(A'*A)inv), theda_std = sqrt(diag(theda_cov)),
% however, numerically ->0 by LSE making E orthogonal to the observation cov inv(A'*A)*A',
%    therefore, apply assumption that E is independent random, E*E' = E_std*I*E_std,
%   thus, instead, use cov_theda = E_std*E_std* inv(A'*A), theda_std= inv(A'*A)*A'*E_std*I_E;
% (independent randomness of E needs be verified by E_corrcoef)
%
% LSE最小平方差估算法 .m函式
%  http://www.cc.ncu.edu.tw/~ncume_ee/mymatlib/lse_std.m
%  應用範例 02_計畫相關資料\060401_NSPO_台俄衛星\nspotr\nspotr97616\sensrept.m
% p.s. http://www.cc.ncu.edu.tw/~ncume_ee/mymatlib/lse_std97712.m
%  這裡面 算 估算參數的 變異量 (標準差 std) 的 公式是錯的, 為什麼?
% 瞭解這些意義嗎?... 觀測值的 變異量 ? 估算參數 的 變異量 ? 各是什麼意思 ?
%  variance, standard deviation,

 % 1st order regression:  A=[X ones(size(X))];
 ndata=size(Y,1);
 mat_theda = inv(A'*A)*(A'); theda=mat_theda * Y ,
  'Yh=A*theda;', Yh=A*theda; E= Y - Yh; E_std=std(E),
   'theda_cov = E_std*E_std* inv(A''*A),', theda_cov = E_std*E_std* inv(A'*A),
 '這個不對:  theda_std = inv(A''*A)*A''* E_std* ones(size(E)),',
   theda_std = inv(A'*A)*A'* E_std* ones(size(E)),
 '這個對: theda_std = sqrt(diag(theda_cov)),',
  theda_std = sqrt(diag(theda_cov)),
['Numerically mat_theda should be orthogonal to E: mat_theda * E*(E'') * mat_theda ='],
  mat_theda * E*(E') * mat_theda',
['check independence of E by correlation coefficient E_corrcoef ='],
['  constructing shifted segments for at most 10 segments ... E_corrcoef(1:min(ndata,10))'], 
 ncorrseg=min(ndata/2,10); nlengthseg=ndata-ncorrseg+1; Eext=ones([nlengthseg,ncorrseg]);
  % the following cannot handle nlengthseg=1 -> will result in error
  for kcorrseg=1:ncorrseg,Eext(:,kcorrseg)=E(kcorrseg:(kcorrseg+nlengthseg-1),:);end;
  E_corrcoef=corrcoef(Eext); E_corrcoef=E_corrcoef(:,1); E_corrcoef(1:min(ndata/2,10))',
  % ndata, Eext, E_corrcoef=corrcoef(Eext), 

if( exist('idx') ), % idx is provided
 if (size(idx) == size(Y)), % valid idx is provided, plot with idx as x axis
 plot(idx, Y,'xk'), hold on, plot(idx, Yh,'b'); plot(idx, E,'go');
 plot(idx, Yh + E_std*ones(size(Yh)),'b-'); plot(idx, Yh- E_std*ones(size(Yh)),'b-');
 else ['invalid idx size'], size(idx), 
 plot(Y,'xk'), hold on, plot(Yh,'b'); plot(E,'go');
 plot(Yh + E_std*ones(size(Yh)),'b-'); plot(Yh- E_std*ones(size(Yh)),'b-');
  end
else
 plot(Y,'xk'), hold on, plot(Yh,'b'); plot(E,'go');
 plot(Yh + E_std*ones(size(Yh)),'b-'); plot(Yh- E_std*ones(size(Yh)),'b-');
end

 grid; hold off; ylabel('xK:Y, b:Yh, go:E')


return