from mpmath import *

mp.dps = 1024

c1 = mpc('.5', '.8053')
c2 = mpc('0.593072401841', '0.4289603490173713')
c3 = mpc('0.583201013489743', '0.9068024709817308')
c4 = mpc('0.48129763917097402170740188306528960808', '0.582528390710367708537023494697095375046194720237124959874026')
c5 = mpc('0.593073103694701381693987901724396871263896593081304801274697809314798612498494057920356294', '0.648074209478056347204783962493184238057103756912074080984057203480192430680234719261979018023807609648235378947619')
c6 = mpc('0.289472038409743092600000000000000000000000000000000000', '0.812397503802492947200000000000000000000000000000000000')
c7 = c1*c3
c8 = c1+c3
c9 = c1 - c3
c10 = c1/c3
c11 = c1*c4
c12 = c11*c1
c13 = c11*c5
c14 = c11+c5
c15 = c1+c5
c16 = c5+c3
c17 = c11-c5
c18 = c1-c5
c19 = c5-c3
c20 = c11/c5
c21 = c1/c5
c22 = c5/c3
c23 = mpc('1', '0') + c5
c24 = c5 + mpc('1', '0')
c25 = mpc('1', '0') +c1
c26 = c1+mpc('1', '0')
c27 = mpc('1', '0')-c5
c28 = c5 - mpc('1', '0')
c29 = mpc('1', '0') - c1
c30 = c1 - mpc('1', '0')
c31 = mpc('2', '0')*c5
c32 = c5*mpc('2', '0')
c33 = mpc('2', '0')*c1
c34 = c1*mpc('2', '0')
c35 = mpc('3', '0')/c5
c36 = c5/mpc('3', '0')
c37 = mpc('3', '0')/c1
c38 = c1/mpc('3', '0')
a42 = mpc('0.593073103694701381693987901724396871263896593081304801274697809314798612498494057920356294', '0')
a43 = mpc('0.648074209478056347204783962493184238057103756912074080984057203480192430680234719261979018023807609648235378947619', '0')
a44 = mpc('0.812397503802492947209480573204809850937130975207034785902384048297', '0')
a45 = mpc('0.289472038409743092572034873892570328509730238401735032795093486098235857302968', '0')
c39 = c1 + a42
c40 = a42 + c1
c41 = c4 + a42
c42 = a42 + c5
c43 = c1 - a42
c44 = a42 - c1
c45 = c4 - a42
c46 = a42 - c5
c47 = c9 * a42
c48 = a42 * c10
c49 = c40 * a42
c50 = a42 * c39
c51 = c10 / a42
c52 = a42 / c10
c53 = c4 / a42
c54 = a42 / c5
print c1
print c2
print c3
print c4
print c5
print c6
print c7
print c8
print c9
print c10
print " " 
print c11
print c12
print c13
print c14
print c15
print c16
print c17
print c18
print c19
print c20
print " " 
print c21
print c22
print c23
print c24
print c25
print c26
print c27
print c28
print c29
print c30
print " " 
print c31
print c32
print c33
print c34
print c35
print c36
print c37
print c38
print c39
print c40
print " " 
print c41
print c42
print c43
print c44
print c45
print c46
print c47
print c48
print c49
print c50
print " " 
print c51
print c52
print c53
print c54
print " "
