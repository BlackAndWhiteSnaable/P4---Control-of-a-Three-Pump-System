function [fitresult, gof] = createFits(Flow, Pres)
%CREATEFITS(FLOW,PRES)
%  Create fits.
%
%  Data for 'WP2 100%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Data for 'WP2 90%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Data for 'WP2 80%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Data for 'WP2 70%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Data for 'WP2 60%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Data for 'WP2 50%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Data for 'WP2 40%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Data for 'WP2 30%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Data for 'WP2 20%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Data for 'WP2 10%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Data for 'WP2 0%' fit:
%      X Input : Flow
%      Y Output: Pres
%  Output:
%      fitresult : a cell-array of fit objects representing the fits.
%      gof : structure array with goodness-of fit info.
%
%  See also FIT, CFIT, SFIT.

%  Auto-generated by MATLAB on 16-Apr-2018 11:29:37

%% Initialization.

% Initialize arrays to store fits and goodness-of-fit.
fitresult = cell( 11, 1 );
gof = struct( 'sse', cell( 11, 1 ), ...
    'rsquare', [], 'dfe', [], 'adjrsquare', [], 'rmse', [] );

%% Fit: 'WP2 100%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly2' );
excludedPoints = excludedata( xData, yData, 'Indices', [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{1}, gof(1)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 100%' );
h = plot( fitresult{1}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 100%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

%% Fit: 'WP2 90%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly2' );
excludedPoints = excludedata( xData, yData, 'Indices', [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 101 102 103 104 105 106 107 108 109 110] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{2}, gof(2)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 90%' );
h = plot( fitresult{2}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 90%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

%% Fit: 'WP2 80%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly2' );
excludedPoints = excludedata( xData, yData, 'Indices', [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{3}, gof(3)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 80%' );
h = plot( fitresult{3}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 80%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

%% Fit: 'WP2 70%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly2' );
excludedPoints = excludedata( xData, yData, 'Indices', [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{4}, gof(4)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 70%' );
h = plot( fitresult{4}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 70%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

%% Fit: 'WP2 60%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly2' );
excludedPoints = excludedata( xData, yData, 'Indices', [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{5}, gof(5)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 60%' );
h = plot( fitresult{5}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 60%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

%% Fit: 'WP2 50%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly2' );
excludedPoints = excludedata( xData, yData, 'Indices', [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{6}, gof(6)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 50%' );
h = plot( fitresult{6}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 50%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

%% Fit: 'WP2 40%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly2' );
excludedPoints = excludedata( xData, yData, 'Indices', [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{7}, gof(7)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 40%' );
h = plot( fitresult{7}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 40%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

%% Fit: 'WP2 30%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly2' );
excludedPoints = excludedata( xData, yData, 'Indices', [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{8}, gof(8)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 30%' );
h = plot( fitresult{8}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 30%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

%% Fit: 'WP2 20%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly2' );
excludedPoints = excludedata( xData, yData, 'Indices', [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{9}, gof(9)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 20%' );
h = plot( fitresult{9}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 20%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

%% Fit: 'WP2 10%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly2' );
excludedPoints = excludedata( xData, yData, 'Indices', [1 2 3 4 5 6 7 8 9 10 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{10}, gof(10)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 10%' );
h = plot( fitresult{10}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 10%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

%% Fit: 'WP2 0%'.
[xData, yData] = prepareCurveData( Flow, Pres );

% Set up fittype and options.
ft = fittype( 'poly1' );
excludedPoints = excludedata( xData, yData, 'Indices', [11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 103 104 105 106 107 108 109 110] );
opts = fitoptions( 'Method', 'LinearLeastSquares' );
opts.Exclude = excludedPoints;

% Fit model to data.
[fitresult{11}, gof(11)] = fit( xData, yData, ft, opts );

% Plot fit with data.
figure( 'Name', 'WP2 0%' );
h = plot( fitresult{11}, xData, yData, excludedPoints );
legend( h, 'Pres vs. Flow', 'Excluded Pres vs. Flow', 'WP2 0%', 'Location', 'NorthEast' );
% Label axes
xlabel Flow
ylabel Pres
grid on

