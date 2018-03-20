function bio=Pump2Testbio
bio = [];
bio(1).blkName='%2WP02';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&Pump2Test_B.uWP02';
bio(1).ndims=2;
bio(1).size=[];
bio(1).isStruct=false;
bio(getlenBIO) = bio(1);

bio(2).blkName='%2signal';
bio(2).sigName='CV01_input';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&Pump2Test_ConstB.CV01_input';
bio(2).ndims=2;
bio(2).size=[];
bio(2).isStruct=false;

bio(3).blkName='DA_meas/src/p1';
bio(3).sigName='CV01';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&Pump2Test_B.CV01';
bio(3).ndims=2;
bio(3).size=[];
bio(3).isStruct=false;

bio(4).blkName='DA_meas/src/p2';
bio(4).sigName='DPT01';
bio(4).portIdx=1;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&Pump2Test_B.DPT01';
bio(4).ndims=2;
bio(4).size=[];
bio(4).isStruct=false;

bio(5).blkName='DA_meas/src/p3';
bio(5).sigName='LMGC1';
bio(5).portIdx=2;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&Pump2Test_B.LMGC1';
bio(5).ndims=2;
bio(5).size=[];
bio(5).isStruct=false;

bio(6).blkName='DA_meas/src/p4';
bio(6).sigName='LMGP1';
bio(6).portIdx=3;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&Pump2Test_B.LMGP1';
bio(6).ndims=2;
bio(6).size=[];
bio(6).isStruct=false;

bio(7).blkName='DA_meas/src/p5';
bio(7).sigName='LMGV1';
bio(7).portIdx=4;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&Pump2Test_B.LMGV1';
bio(7).ndims=2;
bio(7).size=[];
bio(7).isStruct=false;

bio(8).blkName='DA_meas/src/p6';
bio(8).sigName='MFM01';
bio(8).portIdx=5;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&Pump2Test_B.MFM01';
bio(8).ndims=2;
bio(8).size=[];
bio(8).isStruct=false;

bio(9).blkName='DA_meas/src/p7';
bio(9).sigName='PT01';
bio(9).portIdx=6;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&Pump2Test_B.PT01';
bio(9).ndims=2;
bio(9).size=[];
bio(9).isStruct=false;

bio(10).blkName='DA_meas/src/p8';
bio(10).sigName='WP01';
bio(10).portIdx=7;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&Pump2Test_B.WP01';
bio(10).ndims=2;
bio(10).size=[];
bio(10).isStruct=false;

bio(11).blkName='DA_meas/src/p9';
bio(11).sigName='DPT02';
bio(11).portIdx=8;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&Pump2Test_B.DPT02';
bio(11).ndims=2;
bio(11).size=[];
bio(11).isStruct=false;

bio(12).blkName='DA_meas/src/p10';
bio(12).sigName='LMGC2';
bio(12).portIdx=9;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&Pump2Test_B.LMGC2';
bio(12).ndims=2;
bio(12).size=[];
bio(12).isStruct=false;

bio(13).blkName='DA_meas/src/p11';
bio(13).sigName='LMGP2';
bio(13).portIdx=10;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&Pump2Test_B.LMGP2';
bio(13).ndims=2;
bio(13).size=[];
bio(13).isStruct=false;

bio(14).blkName='DA_meas/src/p12';
bio(14).sigName='LMGV2';
bio(14).portIdx=11;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&Pump2Test_B.LMGV2';
bio(14).ndims=2;
bio(14).size=[];
bio(14).isStruct=false;

bio(15).blkName='DA_meas/src/p13';
bio(15).sigName='MFM02';
bio(15).portIdx=12;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&Pump2Test_B.MFM02';
bio(15).ndims=2;
bio(15).size=[];
bio(15).isStruct=false;

bio(16).blkName='DA_meas/src/p14';
bio(16).sigName='PT02';
bio(16).portIdx=13;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&Pump2Test_B.PT02';
bio(16).ndims=2;
bio(16).size=[];
bio(16).isStruct=false;

bio(17).blkName='DA_meas/src/p15';
bio(17).sigName='WP02';
bio(17).portIdx=14;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&Pump2Test_B.WP02';
bio(17).ndims=2;
bio(17).size=[];
bio(17).isStruct=false;

bio(18).blkName='DA_meas/src/p16';
bio(18).sigName='DPT03';
bio(18).portIdx=15;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&Pump2Test_B.DPT03';
bio(18).ndims=2;
bio(18).size=[];
bio(18).isStruct=false;

bio(19).blkName='DA_meas/src/p17';
bio(19).sigName='LMGC3';
bio(19).portIdx=16;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&Pump2Test_B.LMGC3';
bio(19).ndims=2;
bio(19).size=[];
bio(19).isStruct=false;

bio(20).blkName='DA_meas/src/p18';
bio(20).sigName='LMGP3';
bio(20).portIdx=17;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&Pump2Test_B.LMGP3';
bio(20).ndims=2;
bio(20).size=[];
bio(20).isStruct=false;

bio(21).blkName='DA_meas/src/p19';
bio(21).sigName='LMGV3';
bio(21).portIdx=18;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&Pump2Test_B.LMGV3';
bio(21).ndims=2;
bio(21).size=[];
bio(21).isStruct=false;

bio(22).blkName='DA_meas/src/p20';
bio(22).sigName='MFM03';
bio(22).portIdx=19;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&Pump2Test_B.MFM03';
bio(22).ndims=2;
bio(22).size=[];
bio(22).isStruct=false;

bio(23).blkName='DA_meas/src/p21';
bio(23).sigName='PT03';
bio(23).portIdx=20;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&Pump2Test_B.PT03';
bio(23).ndims=2;
bio(23).size=[];
bio(23).isStruct=false;

bio(24).blkName='DA_meas/src/p22';
bio(24).sigName='WP03';
bio(24).portIdx=21;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&Pump2Test_B.WP03';
bio(24).ndims=2;
bio(24).size=[];
bio(24).isStruct=false;

bio(25).blkName='Stair Generator/Model/Clock';
bio(25).sigName='';
bio(25).portIdx=0;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&Pump2Test_B.Clock';
bio(25).ndims=2;
bio(25).size=[];
bio(25).isStruct=false;

bio(26).blkName='Stair Generator/Model/Derivative';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&Pump2Test_B.Derivative';
bio(26).ndims=2;
bio(26).size=[];
bio(26).isStruct=false;

bio(27).blkName='Stair Generator/Model/Look-Up Table';
bio(27).sigName='';
bio(27).portIdx=0;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&Pump2Test_B.LookUpTable';
bio(27).ndims=2;
bio(27).size=[];
bio(27).isStruct=false;

function len = getlenBIO
len = 27;

