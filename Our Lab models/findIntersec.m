function [ outx, outy, outz ] = findIntersec( f1, f2,range, xres, yres, guess_amount)
%findIntersec finds the intersection between two given sfit objects
%   stepping through a given range of x and y values, all intersection
%   points: -1 < [f1(x,y) - f2(x,y)] < 1
%   this function takes a very long time, the bigger the ranges and the
%   smaller the resolution the worse
%   guessing an amount close to the intersection points makes the process
%   faster
if nargin < 3
    guess_amount = 25;
end

ctr = 0;
outx = zeros(1,guess_amount);
outy = zeros(1,guess_amount);
outz = zeros(1,guess_amount);
for x = range(1):xres:range(2)
    for y = range(3):yres:range(4)
        model1=f1(x,y);
        model2=f2(x,y);
        if model1 - model2 < 1
            if model1 - model2 > -1
                ctr = ctr + 1;
                outx(ctr)=x;
                outy(ctr)=y;
                outz(ctr)=model1;
            end
        end
    end
end

end

