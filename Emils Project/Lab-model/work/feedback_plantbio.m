function bio=feedback_plantbio
bio = [];
bio(1).blkName='MATLAB Function';
bio(1).sigName='';
bio(1).portIdx=0;
bio(1).dim=[1,1];
bio(1).sigWidth=1;
bio(1).sigAddress='&feedback_plant_B.Q_tot';
bio(1).ndims=2;
bio(1).size=[];
bio(1).isStruct=false;
bio(getlenBIO) = bio(1);

bio(2).blkName='From Workspace';
bio(2).sigName='';
bio(2).portIdx=0;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&feedback_plant_B.FromWorkspace';
bio(2).ndims=2;
bio(2).size=[];
bio(2).isStruct=false;

bio(3).blkName='From Workspace1';
bio(3).sigName='';
bio(3).portIdx=0;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&feedback_plant_B.FromWorkspace1';
bio(3).ndims=2;
bio(3).size=[];
bio(3).isStruct=false;

bio(4).blkName='From Workspace2';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&feedback_plant_B.FromWorkspace2';
bio(4).ndims=2;
bio(4).size=[];
bio(4).isStruct=false;

bio(5).blkName='From Workspace3';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&feedback_plant_B.FromWorkspace3';
bio(5).ndims=2;
bio(5).size=[];
bio(5).isStruct=false;

bio(6).blkName='Gain';
bio(6).sigName='';
bio(6).portIdx=0;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&feedback_plant_B.Gain';
bio(6).ndims=2;
bio(6).size=[];
bio(6).isStruct=false;

bio(7).blkName='Gain1';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&feedback_plant_B.Gain1';
bio(7).ndims=2;
bio(7).size=[];
bio(7).isStruct=false;

bio(8).blkName='Gain2';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&feedback_plant_B.Gain2';
bio(8).ndims=2;
bio(8).size=[];
bio(8).isStruct=false;

bio(9).blkName='Gain3';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&feedback_plant_B.Gain3';
bio(9).ndims=2;
bio(9).size=[];
bio(9).isStruct=false;

bio(10).blkName='Gain4';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&feedback_plant_B.Gain4';
bio(10).ndims=2;
bio(10).size=[];
bio(10).isStruct=false;

bio(11).blkName='Saturation5';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&feedback_plant_B.Saturation5';
bio(11).ndims=2;
bio(11).size=[];
bio(11).isStruct=false;

bio(12).blkName='actuators/transform/p1';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[1,1];
bio(12).sigWidth=1;
bio(12).sigAddress='&feedback_plant_B.CV01_j';
bio(12).ndims=2;
bio(12).size=[];
bio(12).isStruct=false;

bio(13).blkName='actuators/transform/p2';
bio(13).sigName='';
bio(13).portIdx=1;
bio(13).dim=[1,1];
bio(13).sigWidth=1;
bio(13).sigAddress='&feedback_plant_B.WP01_o';
bio(13).ndims=2;
bio(13).size=[];
bio(13).isStruct=false;

bio(14).blkName='actuators/transform/p3';
bio(14).sigName='';
bio(14).portIdx=2;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&feedback_plant_B.WP02_l';
bio(14).ndims=2;
bio(14).size=[];
bio(14).isStruct=false;

bio(15).blkName='actuators/transform/p4';
bio(15).sigName='';
bio(15).portIdx=3;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&feedback_plant_B.WP03_d';
bio(15).ndims=2;
bio(15).size=[];
bio(15).isStruct=false;

bio(16).blkName='analogdigital/transform/p1';
bio(16).sigName='CV01';
bio(16).portIdx=0;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&feedback_plant_B.CV01';
bio(16).ndims=2;
bio(16).size=[];
bio(16).isStruct=false;

bio(17).blkName='analogdigital/transform/p2';
bio(17).sigName='DPT01';
bio(17).portIdx=1;
bio(17).dim=[1,1];
bio(17).sigWidth=1;
bio(17).sigAddress='&feedback_plant_B.DPT01';
bio(17).ndims=2;
bio(17).size=[];
bio(17).isStruct=false;

bio(18).blkName='analogdigital/transform/p3';
bio(18).sigName='LMGC1';
bio(18).portIdx=2;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&feedback_plant_B.LMGC1';
bio(18).ndims=2;
bio(18).size=[];
bio(18).isStruct=false;

bio(19).blkName='analogdigital/transform/p4';
bio(19).sigName='LMGP1';
bio(19).portIdx=3;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&feedback_plant_B.LMGP1';
bio(19).ndims=2;
bio(19).size=[];
bio(19).isStruct=false;

bio(20).blkName='analogdigital/transform/p5';
bio(20).sigName='LMGV1';
bio(20).portIdx=4;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&feedback_plant_B.LMGV1';
bio(20).ndims=2;
bio(20).size=[];
bio(20).isStruct=false;

bio(21).blkName='analogdigital/transform/p6';
bio(21).sigName='MFM01';
bio(21).portIdx=5;
bio(21).dim=[1,1];
bio(21).sigWidth=1;
bio(21).sigAddress='&feedback_plant_B.MFM01';
bio(21).ndims=2;
bio(21).size=[];
bio(21).isStruct=false;

bio(22).blkName='analogdigital/transform/p7';
bio(22).sigName='PT01';
bio(22).portIdx=6;
bio(22).dim=[1,1];
bio(22).sigWidth=1;
bio(22).sigAddress='&feedback_plant_B.PT01';
bio(22).ndims=2;
bio(22).size=[];
bio(22).isStruct=false;

bio(23).blkName='analogdigital/transform/p8';
bio(23).sigName='WP01';
bio(23).portIdx=7;
bio(23).dim=[1,1];
bio(23).sigWidth=1;
bio(23).sigAddress='&feedback_plant_B.WP01';
bio(23).ndims=2;
bio(23).size=[];
bio(23).isStruct=false;

bio(24).blkName='analogdigital/transform/p9';
bio(24).sigName='DPT02';
bio(24).portIdx=8;
bio(24).dim=[1,1];
bio(24).sigWidth=1;
bio(24).sigAddress='&feedback_plant_B.DPT02';
bio(24).ndims=2;
bio(24).size=[];
bio(24).isStruct=false;

bio(25).blkName='analogdigital/transform/p10';
bio(25).sigName='LMGC2';
bio(25).portIdx=9;
bio(25).dim=[1,1];
bio(25).sigWidth=1;
bio(25).sigAddress='&feedback_plant_B.LMGC2';
bio(25).ndims=2;
bio(25).size=[];
bio(25).isStruct=false;

bio(26).blkName='analogdigital/transform/p11';
bio(26).sigName='LMGP2';
bio(26).portIdx=10;
bio(26).dim=[1,1];
bio(26).sigWidth=1;
bio(26).sigAddress='&feedback_plant_B.LMGP2';
bio(26).ndims=2;
bio(26).size=[];
bio(26).isStruct=false;

bio(27).blkName='analogdigital/transform/p12';
bio(27).sigName='LMGV2';
bio(27).portIdx=11;
bio(27).dim=[1,1];
bio(27).sigWidth=1;
bio(27).sigAddress='&feedback_plant_B.LMGV2';
bio(27).ndims=2;
bio(27).size=[];
bio(27).isStruct=false;

bio(28).blkName='analogdigital/transform/p13';
bio(28).sigName='MFM02';
bio(28).portIdx=12;
bio(28).dim=[1,1];
bio(28).sigWidth=1;
bio(28).sigAddress='&feedback_plant_B.MFM02';
bio(28).ndims=2;
bio(28).size=[];
bio(28).isStruct=false;

bio(29).blkName='analogdigital/transform/p14';
bio(29).sigName='PT02';
bio(29).portIdx=13;
bio(29).dim=[1,1];
bio(29).sigWidth=1;
bio(29).sigAddress='&feedback_plant_B.PT02';
bio(29).ndims=2;
bio(29).size=[];
bio(29).isStruct=false;

bio(30).blkName='analogdigital/transform/p15';
bio(30).sigName='WP02';
bio(30).portIdx=14;
bio(30).dim=[1,1];
bio(30).sigWidth=1;
bio(30).sigAddress='&feedback_plant_B.WP02';
bio(30).ndims=2;
bio(30).size=[];
bio(30).isStruct=false;

bio(31).blkName='analogdigital/transform/p16';
bio(31).sigName='DPT03';
bio(31).portIdx=15;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&feedback_plant_B.DPT03';
bio(31).ndims=2;
bio(31).size=[];
bio(31).isStruct=false;

bio(32).blkName='analogdigital/transform/p17';
bio(32).sigName='LMGC3';
bio(32).portIdx=16;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&feedback_plant_B.LMGC3';
bio(32).ndims=2;
bio(32).size=[];
bio(32).isStruct=false;

bio(33).blkName='analogdigital/transform/p18';
bio(33).sigName='LMGP3';
bio(33).portIdx=17;
bio(33).dim=[1,1];
bio(33).sigWidth=1;
bio(33).sigAddress='&feedback_plant_B.LMGP3';
bio(33).ndims=2;
bio(33).size=[];
bio(33).isStruct=false;

bio(34).blkName='analogdigital/transform/p19';
bio(34).sigName='LMGV3';
bio(34).portIdx=18;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&feedback_plant_B.LMGV3';
bio(34).ndims=2;
bio(34).size=[];
bio(34).isStruct=false;

bio(35).blkName='analogdigital/transform/p20';
bio(35).sigName='MFM03';
bio(35).portIdx=19;
bio(35).dim=[1,1];
bio(35).sigWidth=1;
bio(35).sigAddress='&feedback_plant_B.MFM03';
bio(35).ndims=2;
bio(35).size=[];
bio(35).isStruct=false;

bio(36).blkName='analogdigital/transform/p21';
bio(36).sigName='PT03';
bio(36).portIdx=20;
bio(36).dim=[1,1];
bio(36).sigWidth=1;
bio(36).sigAddress='&feedback_plant_B.PT03';
bio(36).ndims=2;
bio(36).size=[];
bio(36).isStruct=false;

bio(37).blkName='analogdigital/transform/p22';
bio(37).sigName='WP03';
bio(37).portIdx=21;
bio(37).dim=[1,1];
bio(37).sigWidth=1;
bio(37).sigAddress='&feedback_plant_B.WP03';
bio(37).ndims=2;
bio(37).size=[];
bio(37).isStruct=false;

bio(38).blkName='analogdigital/src/p1';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[1,1];
bio(38).sigWidth=1;
bio(38).sigAddress='&feedback_plant_B.src_o1';
bio(38).ndims=2;
bio(38).size=[];
bio(38).isStruct=false;

bio(39).blkName='analogdigital/src/p2';
bio(39).sigName='';
bio(39).portIdx=1;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&feedback_plant_B.src_o2';
bio(39).ndims=2;
bio(39).size=[];
bio(39).isStruct=false;

bio(40).blkName='analogdigital/src/p3';
bio(40).sigName='';
bio(40).portIdx=2;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&feedback_plant_B.src_o3';
bio(40).ndims=2;
bio(40).size=[];
bio(40).isStruct=false;

bio(41).blkName='analogdigital/src/p4';
bio(41).sigName='';
bio(41).portIdx=3;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&feedback_plant_B.src_o4';
bio(41).ndims=2;
bio(41).size=[];
bio(41).isStruct=false;

bio(42).blkName='analogdigital/src/p5';
bio(42).sigName='';
bio(42).portIdx=4;
bio(42).dim=[1,1];
bio(42).sigWidth=1;
bio(42).sigAddress='&feedback_plant_B.src_o5';
bio(42).ndims=2;
bio(42).size=[];
bio(42).isStruct=false;

bio(43).blkName='analogdigital/src/p6';
bio(43).sigName='';
bio(43).portIdx=5;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&feedback_plant_B.src_o6';
bio(43).ndims=2;
bio(43).size=[];
bio(43).isStruct=false;

bio(44).blkName='analogdigital/src/p7';
bio(44).sigName='';
bio(44).portIdx=6;
bio(44).dim=[1,1];
bio(44).sigWidth=1;
bio(44).sigAddress='&feedback_plant_B.src_o7';
bio(44).ndims=2;
bio(44).size=[];
bio(44).isStruct=false;

bio(45).blkName='analogdigital/src/p8';
bio(45).sigName='';
bio(45).portIdx=7;
bio(45).dim=[1,1];
bio(45).sigWidth=1;
bio(45).sigAddress='&feedback_plant_B.src_o8';
bio(45).ndims=2;
bio(45).size=[];
bio(45).isStruct=false;

bio(46).blkName='analogdigital/src/p9';
bio(46).sigName='';
bio(46).portIdx=8;
bio(46).dim=[1,1];
bio(46).sigWidth=1;
bio(46).sigAddress='&feedback_plant_B.src_o9';
bio(46).ndims=2;
bio(46).size=[];
bio(46).isStruct=false;

bio(47).blkName='analogdigital/src/p10';
bio(47).sigName='';
bio(47).portIdx=9;
bio(47).dim=[1,1];
bio(47).sigWidth=1;
bio(47).sigAddress='&feedback_plant_B.src_o10';
bio(47).ndims=2;
bio(47).size=[];
bio(47).isStruct=false;

bio(48).blkName='analogdigital/src/p11';
bio(48).sigName='';
bio(48).portIdx=10;
bio(48).dim=[1,1];
bio(48).sigWidth=1;
bio(48).sigAddress='&feedback_plant_B.src_o11';
bio(48).ndims=2;
bio(48).size=[];
bio(48).isStruct=false;

bio(49).blkName='analogdigital/src/p12';
bio(49).sigName='';
bio(49).portIdx=11;
bio(49).dim=[1,1];
bio(49).sigWidth=1;
bio(49).sigAddress='&feedback_plant_B.src_o12';
bio(49).ndims=2;
bio(49).size=[];
bio(49).isStruct=false;

bio(50).blkName='analogdigital/src/p13';
bio(50).sigName='';
bio(50).portIdx=12;
bio(50).dim=[1,1];
bio(50).sigWidth=1;
bio(50).sigAddress='&feedback_plant_B.src_o13';
bio(50).ndims=2;
bio(50).size=[];
bio(50).isStruct=false;

bio(51).blkName='analogdigital/src/p14';
bio(51).sigName='';
bio(51).portIdx=13;
bio(51).dim=[1,1];
bio(51).sigWidth=1;
bio(51).sigAddress='&feedback_plant_B.src_o14';
bio(51).ndims=2;
bio(51).size=[];
bio(51).isStruct=false;

bio(52).blkName='analogdigital/src/p15';
bio(52).sigName='';
bio(52).portIdx=14;
bio(52).dim=[1,1];
bio(52).sigWidth=1;
bio(52).sigAddress='&feedback_plant_B.src_o15';
bio(52).ndims=2;
bio(52).size=[];
bio(52).isStruct=false;

bio(53).blkName='analogdigital/src/p16';
bio(53).sigName='';
bio(53).portIdx=15;
bio(53).dim=[1,1];
bio(53).sigWidth=1;
bio(53).sigAddress='&feedback_plant_B.src_o16';
bio(53).ndims=2;
bio(53).size=[];
bio(53).isStruct=false;

bio(54).blkName='analogdigital/src/p17';
bio(54).sigName='';
bio(54).portIdx=16;
bio(54).dim=[1,1];
bio(54).sigWidth=1;
bio(54).sigAddress='&feedback_plant_B.src_o17';
bio(54).ndims=2;
bio(54).size=[];
bio(54).isStruct=false;

bio(55).blkName='analogdigital/src/p18';
bio(55).sigName='';
bio(55).portIdx=17;
bio(55).dim=[1,1];
bio(55).sigWidth=1;
bio(55).sigAddress='&feedback_plant_B.src_o18';
bio(55).ndims=2;
bio(55).size=[];
bio(55).isStruct=false;

bio(56).blkName='analogdigital/src/p19';
bio(56).sigName='';
bio(56).portIdx=18;
bio(56).dim=[1,1];
bio(56).sigWidth=1;
bio(56).sigAddress='&feedback_plant_B.src_o19';
bio(56).ndims=2;
bio(56).size=[];
bio(56).isStruct=false;

bio(57).blkName='analogdigital/src/p20';
bio(57).sigName='';
bio(57).portIdx=19;
bio(57).dim=[1,1];
bio(57).sigWidth=1;
bio(57).sigAddress='&feedback_plant_B.src_o20';
bio(57).ndims=2;
bio(57).size=[];
bio(57).isStruct=false;

bio(58).blkName='analogdigital/src/p21';
bio(58).sigName='';
bio(58).portIdx=20;
bio(58).dim=[1,1];
bio(58).sigWidth=1;
bio(58).sigAddress='&feedback_plant_B.src_o21';
bio(58).ndims=2;
bio(58).size=[];
bio(58).isStruct=false;

bio(59).blkName='analogdigital/src/p22';
bio(59).sigName='';
bio(59).portIdx=21;
bio(59).dim=[1,1];
bio(59).sigWidth=1;
bio(59).sigAddress='&feedback_plant_B.src_o22';
bio(59).ndims=2;
bio(59).size=[];
bio(59).isStruct=false;

bio(60).blkName='best_mode_control/cost_power_1';
bio(60).sigName='';
bio(60).portIdx=0;
bio(60).dim=[1,1];
bio(60).sigWidth=1;
bio(60).sigAddress='&feedback_plant_B.cost_power_1_w_sat_i';
bio(60).ndims=2;
bio(60).size=[];
bio(60).isStruct=false;

bio(61).blkName='best_mode_control/cost_power_2';
bio(61).sigName='';
bio(61).portIdx=0;
bio(61).dim=[1,1];
bio(61).sigWidth=1;
bio(61).sigAddress='&feedback_plant_B.cost_power_1_w_sat_p';
bio(61).ndims=2;
bio(61).size=[];
bio(61).isStruct=false;

bio(62).blkName='best_mode_control/cost_power_3';
bio(62).sigName='';
bio(62).portIdx=0;
bio(62).dim=[1,1];
bio(62).sigWidth=1;
bio(62).sigAddress='&feedback_plant_B.cost_power_1_w_sat';
bio(62).ndims=2;
bio(62).size=[];
bio(62).isStruct=false;

bio(63).blkName='best_mode_control/test /p1';
bio(63).sigName='';
bio(63).portIdx=0;
bio(63).dim=[1,1];
bio(63).sigWidth=1;
bio(63).sigAddress='&feedback_plant_B.sumP1';
bio(63).ndims=2;
bio(63).size=[];
bio(63).isStruct=false;

bio(64).blkName='best_mode_control/test /p2';
bio(64).sigName='';
bio(64).portIdx=1;
bio(64).dim=[1,1];
bio(64).sigWidth=1;
bio(64).sigAddress='&feedback_plant_B.sumP2';
bio(64).ndims=2;
bio(64).size=[];
bio(64).isStruct=false;

bio(65).blkName='best_mode_control/test /p3';
bio(65).sigName='';
bio(65).portIdx=2;
bio(65).dim=[1,1];
bio(65).sigWidth=1;
bio(65).sigAddress='&feedback_plant_B.sumP3';
bio(65).ndims=2;
bio(65).size=[];
bio(65).isStruct=false;

bio(66).blkName='best_mode_control/test 1';
bio(66).sigName='';
bio(66).portIdx=0;
bio(66).dim=[1,1];
bio(66).sigWidth=1;
bio(66).sigAddress='&feedback_plant_B.y';
bio(66).ndims=2;
bio(66).size=[];
bio(66).isStruct=false;

bio(67).blkName='best_mode_control/Gain';
bio(67).sigName='';
bio(67).portIdx=0;
bio(67).dim=[1,1];
bio(67).sigWidth=1;
bio(67).sigAddress='&feedback_plant_B.Gain_g';
bio(67).ndims=2;
bio(67).size=[];
bio(67).isStruct=false;

bio(68).blkName='best_mode_control/Gain1';
bio(68).sigName='';
bio(68).portIdx=0;
bio(68).dim=[1,1];
bio(68).sigWidth=1;
bio(68).sigAddress='&feedback_plant_B.Gain1_m';
bio(68).ndims=2;
bio(68).size=[];
bio(68).isStruct=false;

bio(69).blkName='best_mode_control/Gain3';
bio(69).sigName='';
bio(69).portIdx=0;
bio(69).dim=[1,1];
bio(69).sigWidth=1;
bio(69).sigAddress='&feedback_plant_B.Gain3_m';
bio(69).ndims=2;
bio(69).size=[];
bio(69).isStruct=false;

bio(70).blkName='best_mode_control/Integrator';
bio(70).sigName='';
bio(70).portIdx=0;
bio(70).dim=[1,1];
bio(70).sigWidth=1;
bio(70).sigAddress='&feedback_plant_B.Integrator';
bio(70).ndims=2;
bio(70).size=[];
bio(70).isStruct=false;

bio(71).blkName='best_mode_control/Integrator1';
bio(71).sigName='';
bio(71).portIdx=0;
bio(71).dim=[1,1];
bio(71).sigWidth=1;
bio(71).sigAddress='&feedback_plant_B.Integrator1';
bio(71).ndims=2;
bio(71).size=[];
bio(71).isStruct=false;

bio(72).blkName='best_mode_control/Integrator2';
bio(72).sigName='';
bio(72).portIdx=0;
bio(72).dim=[1,1];
bio(72).sigWidth=1;
bio(72).sigAddress='&feedback_plant_B.Integrator2';
bio(72).ndims=2;
bio(72).size=[];
bio(72).isStruct=false;

bio(73).blkName='best_mode_control/Divide';
bio(73).sigName='';
bio(73).portIdx=0;
bio(73).dim=[1,1];
bio(73).sigWidth=1;
bio(73).sigAddress='&feedback_plant_B.Divide';
bio(73).ndims=2;
bio(73).size=[];
bio(73).isStruct=false;

bio(74).blkName='best_mode_control/Divide1';
bio(74).sigName='';
bio(74).portIdx=0;
bio(74).dim=[1,1];
bio(74).sigWidth=1;
bio(74).sigAddress='&feedback_plant_B.Divide1';
bio(74).ndims=2;
bio(74).size=[];
bio(74).isStruct=false;

bio(75).blkName='best_mode_control/Divide2';
bio(75).sigName='';
bio(75).portIdx=0;
bio(75).dim=[1,1];
bio(75).sigWidth=1;
bio(75).sigAddress='&feedback_plant_B.Divide2';
bio(75).ndims=2;
bio(75).size=[];
bio(75).isStruct=false;

bio(76).blkName='best_mode_control/Divide3';
bio(76).sigName='';
bio(76).portIdx=0;
bio(76).dim=[1,1];
bio(76).sigWidth=1;
bio(76).sigAddress='&feedback_plant_B.Divide3';
bio(76).ndims=2;
bio(76).size=[];
bio(76).isStruct=false;

bio(77).blkName='best_mode_control/Divide4';
bio(77).sigName='';
bio(77).portIdx=0;
bio(77).dim=[1,1];
bio(77).sigWidth=1;
bio(77).sigAddress='&feedback_plant_B.Divide4';
bio(77).ndims=2;
bio(77).size=[];
bio(77).isStruct=false;

bio(78).blkName='best_mode_control/Divide5';
bio(78).sigName='';
bio(78).portIdx=0;
bio(78).dim=[1,1];
bio(78).sigWidth=1;
bio(78).sigAddress='&feedback_plant_B.Divide5';
bio(78).ndims=2;
bio(78).size=[];
bio(78).isStruct=false;

bio(79).blkName='best_mode_control/Saturation';
bio(79).sigName='p3';
bio(79).portIdx=0;
bio(79).dim=[1,1];
bio(79).sigWidth=1;
bio(79).sigAddress='&feedback_plant_B.p3';
bio(79).ndims=2;
bio(79).size=[];
bio(79).isStruct=false;

bio(80).blkName='best_mode_control/Saturation1';
bio(80).sigName='p2';
bio(80).portIdx=0;
bio(80).dim=[1,1];
bio(80).sigWidth=1;
bio(80).sigAddress='&feedback_plant_B.p2';
bio(80).ndims=2;
bio(80).size=[];
bio(80).isStruct=false;

bio(81).blkName='best_mode_control/Saturation2';
bio(81).sigName='p1';
bio(81).portIdx=0;
bio(81).dim=[1,1];
bio(81).sigWidth=1;
bio(81).sigAddress='&feedback_plant_B.p1';
bio(81).ndims=2;
bio(81).size=[];
bio(81).isStruct=false;

bio(82).blkName='best_mode_control/Saturation3';
bio(82).sigName='';
bio(82).portIdx=0;
bio(82).dim=[1,1];
bio(82).sigWidth=1;
bio(82).sigAddress='&feedback_plant_B.Saturation3';
bio(82).ndims=2;
bio(82).size=[];
bio(82).isStruct=false;

bio(83).blkName='best_mode_control/Saturation4';
bio(83).sigName='';
bio(83).portIdx=0;
bio(83).dim=[1,1];
bio(83).sigWidth=1;
bio(83).sigAddress='&feedback_plant_B.Saturation4';
bio(83).ndims=2;
bio(83).size=[];
bio(83).isStruct=false;

bio(84).blkName='best_mode_control/Saturation5';
bio(84).sigName='';
bio(84).portIdx=0;
bio(84).dim=[1,1];
bio(84).sigWidth=1;
bio(84).sigAddress='&feedback_plant_B.Saturation5_g';
bio(84).ndims=2;
bio(84).size=[];
bio(84).isStruct=false;

bio(85).blkName='best_mode_control/Sum';
bio(85).sigName='';
bio(85).portIdx=0;
bio(85).dim=[1,1];
bio(85).sigWidth=1;
bio(85).sigAddress='&feedback_plant_B.Sum';
bio(85).ndims=2;
bio(85).size=[];
bio(85).isStruct=false;

bio(86).blkName='best_mode_control/Sum1';
bio(86).sigName='';
bio(86).portIdx=0;
bio(86).dim=[1,1];
bio(86).sigWidth=1;
bio(86).sigAddress='&feedback_plant_B.Sum1';
bio(86).ndims=2;
bio(86).size=[];
bio(86).isStruct=false;

bio(87).blkName='best_mode_control/Sum2';
bio(87).sigName='';
bio(87).portIdx=0;
bio(87).dim=[1,1];
bio(87).sigWidth=1;
bio(87).sigAddress='&feedback_plant_B.Sum2';
bio(87).ndims=2;
bio(87).size=[];
bio(87).isStruct=false;

bio(88).blkName='best_mode_control/Sum3';
bio(88).sigName='';
bio(88).portIdx=0;
bio(88).dim=[1,1];
bio(88).sigWidth=1;
bio(88).sigAddress='&feedback_plant_B.Sum3';
bio(88).ndims=2;
bio(88).size=[];
bio(88).isStruct=false;

bio(89).blkName='best_mode_control/Sum4';
bio(89).sigName='';
bio(89).portIdx=0;
bio(89).dim=[1,1];
bio(89).sigWidth=1;
bio(89).sigAddress='&feedback_plant_B.Sum4';
bio(89).ndims=2;
bio(89).size=[];
bio(89).isStruct=false;

bio(90).blkName='best_mode_control/Sum5';
bio(90).sigName='';
bio(90).portIdx=0;
bio(90).dim=[1,1];
bio(90).sigWidth=1;
bio(90).sigAddress='&feedback_plant_B.Sum5';
bio(90).ndims=2;
bio(90).size=[];
bio(90).isStruct=false;

bio(91).blkName='best_mode_control/Unit Delay';
bio(91).sigName='';
bio(91).portIdx=0;
bio(91).dim=[1,1];
bio(91).sigWidth=1;
bio(91).sigAddress='&feedback_plant_B.UnitDelay';
bio(91).ndims=2;
bio(91).size=[];
bio(91).isStruct=false;

bio(92).blkName='terminating_safety/err_high';
bio(92).sigName='';
bio(92).portIdx=0;
bio(92).dim=[1,1];
bio(92).sigWidth=1;
bio(92).sigAddress='&feedback_plant_B.stop_a';
bio(92).ndims=2;
bio(92).size=[];
bio(92).isStruct=false;

bio(93).blkName='terminating_safety/err_low';
bio(93).sigName='';
bio(93).portIdx=0;
bio(93).dim=[1,1];
bio(93).sigWidth=1;
bio(93).sigAddress='&feedback_plant_B.stop';
bio(93).ndims=2;
bio(93).size=[];
bio(93).isStruct=false;

bio(94).blkName='terminating_safety/Check Static  Lower Bound/min_relop';
bio(94).sigName='';
bio(94).portIdx=0;
bio(94).dim=[22,1];
bio(94).sigWidth=22;
bio(94).sigAddress='&feedback_plant_B.min_relop[0]';
bio(94).ndims=2;
bio(94).size=[];
bio(94).isStruct=false;

bio(95).blkName='terminating_safety/Check Static  Upper Bound/max_relop';
bio(95).sigName='';
bio(95).portIdx=0;
bio(95).dim=[22,1];
bio(95).sigWidth=22;
bio(95).sigAddress='&feedback_plant_B.max_relop[0]';
bio(95).ndims=2;
bio(95).size=[];
bio(95).isStruct=false;

function len = getlenBIO
len = 95;

