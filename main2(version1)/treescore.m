function [F] = treescore()
clear all

objective = @(x) myObjective(x);
x0 = ones(1,9);
lb = [zeros(1,6),ones(1,3)*-10];
ub = [ones(1,6),ones(1,3)*10];

options = optimoptions('fmincon', 'Display', 'off','MaxFunctionEvaluations',50000,'MaxIterations',10000);
[x_optimal,fval,exitflag] = fmincon(objective, x0, [], [], [], [], lb, ub, [], options);

disp('Optimal solution t:');
disp(-log(x_optimal(1:6)));
disp('Optimal solution c:');
disp(exp(x_optimal(7:9)));
disp('Optimal objective function value:');
disp(exp(vpa(-fval)));
F= -fval;

end

function result = myObjective(x)
	variables
	lambda_formula
	lambda_formula_trivial
	suml=1-exp(c1)*log(t1)-exp(c2)*log(t2)-exp(c3)*log(t3)-sum(la);
	F = sum(log(l))-length(l)*log(suml);
	result = -F;
end
