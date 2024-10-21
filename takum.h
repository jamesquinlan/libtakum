/* See LICENSE file for copyright and license details. */
#ifndef TAKUM_H
#define TAKUM_H

#include <stdint.h>

/* Type definitions (availability of int*_t infers two's complement) */
typedef int8_t takum8;
typedef int16_t takum16;
typedef int32_t takum32;
typedef int64_t takum64;

typedef int8_t takum_linear8;
typedef int16_t takum_linear16;
typedef int32_t takum_linear32;
typedef int64_t takum_linear64;

/* type punning unions */
union takum_internal_takum8_union {
	int8_t value;
	uint8_t bits;
};

union takum_internal_takum16_union {
	int16_t value;
	uint16_t bits;
};

union takum_internal_takum32_union {
	int32_t value;
	uint32_t bits;
};

union takum_internal_takum64_union {
	int64_t value;
	uint64_t bits;
};

/* NaR (Not a Real) */
#define TAKUM8_NAR  (INT8_C(-127) - INT8_C(1))
#define TAKUM16_NAR (INT16_C(-32767) - INT16_C(1))
#define TAKUM32_NAR (INT32_C(-2147483647) - INT32_C(1))
#define TAKUM64_NAR (INT64_C(-9223372036854775807) - INT64_C(1))

#define TAKUM_LINEAR8_NAR  (INT8_C(-127) - INT8_C(1))
#define TAKUM_LINEAR16_NAR (INT16_C(-32767) - INT16_C(1))
#define TAKUM_LINEAR32_NAR (INT32_C(-2147483647) - INT32_C(1))
#define TAKUM_LINEAR64_NAR (INT64_C(-9223372036854775807) - INT64_C(1))

/* Smallest Positive */
#define TAKUM8_POSITIVE_MINIMUM  INT8_C(1)
#define TAKUM16_POSITIVE_MINIMUM INT16_C(1)
#define TAKUM32_POSITIVE_MINIMUM INT32_C(1)
#define TAKUM64_POSITIVE_MINIMUM INT64_C(1)

#define TAKUM_LINEAR8_POSITIVE_MINIMUM  INT8_C(1)
#define TAKUM_LINEAR16_POSITIVE_MINIMUM INT16_C(1)
#define TAKUM_LINEAR32_POSITIVE_MINIMUM INT32_C(1)
#define TAKUM_LINEAR64_POSITIVE_MINIMUM INT64_C(1)

/* Largest Positive */
#define TAKUM8_POSITIVE_MAXIMUM  INT8_MAX
#define TAKUM16_POSITIVE_MAXIMUM INT16_MAX
#define TAKUM32_POSITIVE_MAXIMUM INT32_MAX
#define TAKUM64_POSITIVE_MAXIMUM INT64_MAX

#define TAKUM_LINEAR8_POSITIVE_MAXIMUM  INT8_MAX
#define TAKUM_LINEAR16_POSITIVE_MAXIMUM INT16_MAX
#define TAKUM_LINEAR32_POSITIVE_MAXIMUM INT32_MAX
#define TAKUM_LINEAR64_POSITIVE_MAXIMUM INT64_MAX

/* 2π */
#define TAKUM8_2_PI  INT8_C(81)
#define TAKUM16_2_PI INT16_C(20826)
#define TAKUM32_2_PI INT32_C(1364851826)
#define TAKUM64_2_PI INT64_C(5861993956978437418)

#define TAKUM_LINEAR8_2_PI  INT8_C(78)
#define TAKUM_LINEAR16_2_PI INT16_C(20040)
#define TAKUM_LINEAR32_2_PI INT32_C(1313373909)
#define TAKUM_LINEAR64_2_PI INT64_C(5640897986860631570)

/* 2π/3 */
#define TAKUM8_2_PI_OVER_3  INT8_C(74)
#define TAKUM16_2_PI_OVER_3 INT16_C(18922)
#define TAKUM32_2_PI_OVER_3 INT32_C(1240073127)
#define TAKUM64_2_PI_OVER_3 INT64_C(5326073524507235592)

#define TAKUM_LINEAR8_2_PI_OVER_3  INT8_C(72)
#define TAKUM_LINEAR16_2_PI_OVER_3 INT16_C(18480)
#define TAKUM_LINEAR32_2_PI_OVER_3 INT32_C(1211126926)
#define TAKUM_LINEAR64_2_PI_OVER_3 INT64_C(5201750538665646433)

/* 2π/5 */
#define TAKUM8_2_PI_OVER_5  INT8_C(68)
#define TAKUM16_2_PI_OVER_5 INT16_C(17320)
#define TAKUM32_2_PI_OVER_5 INT32_C(1135062992)
#define TAKUM64_2_PI_OVER_5 INT64_C(4875058431539642684)

#define TAKUM_LINEAR8_2_PI_OVER_5  INT8_C(66)
#define TAKUM_LINEAR16_2_PI_OVER_5 INT16_C(16910)
#define TAKUM_LINEAR32_2_PI_OVER_5 INT32_C(1108187067)
#define TAKUM_LINEAR64_2_PI_OVER_5 INT64_C(4759627211931676700)

/* 3π */
#define TAKUM8_3_PI  INT8_C(83)
#define TAKUM16_3_PI INT16_C(21241)
#define TAKUM32_3_PI INT32_C(1392062129)
#define TAKUM64_3_PI INT64_C(5978861317604848105)

#define TAKUM_LINEAR8_3_PI  INT8_C(80)
#define TAKUM_LINEAR16_3_PI INT16_C(20571)
#define TAKUM_LINEAR32_3_PI INT32_C(1348153232)
#define TAKUM_LINEAR64_3_PI INT64_C(5790274041007061575)

/* 3π/2 */
#define TAKUM8_3_PI_OVER_2  INT8_C(80)
#define TAKUM16_3_PI_OVER_2 INT16_C(20531)
#define TAKUM32_3_PI_OVER_2 INT32_C(1345545809)
#define TAKUM64_3_PI_OVER_2 INT64_C(5779075245023556610)

#define TAKUM_LINEAR8_3_PI_OVER_2  INT8_C(77)
#define TAKUM_LINEAR16_3_PI_OVER_2 INT16_C(19638)
#define TAKUM_LINEAR32_3_PI_OVER_2 INT32_C(1287020320)
#define TAKUM_LINEAR64_3_PI_OVER_2 INT64_C(5527710182828176525)

/* 3π/4 */
#define TAKUM8_3_PI_OVER_4  INT8_C(75)
#define TAKUM16_3_PI_OVER_4 INT16_C(19163)
#define TAKUM32_3_PI_OVER_4 INT32_C(1255881698)
#define TAKUM64_3_PI_OVER_4 INT64_C(5393970821850295351)

#define TAKUM_LINEAR8_3_PI_OVER_4  INT8_C(73)
#define TAKUM_LINEAR16_3_PI_OVER_4 INT16_C(18614)
#define TAKUM_LINEAR32_3_PI_OVER_4 INT32_C(1219911456)
#define TAKUM_LINEAR64_3_PI_OVER_4 INT64_C(5239479806676464781)

/* 3π/5 */
#define TAKUM8_3_PI_OVER_5  INT8_C(73)
#define TAKUM16_3_PI_OVER_5 INT16_C(18706)
#define TAKUM32_3_PI_OVER_5 INT32_C(1225931878)
#define TAKUM64_3_PI_OVER_5 INT64_C(5265337322388048412)

#define TAKUM_LINEAR8_3_PI_OVER_5  INT8_C(71)
#define TAKUM_LINEAR16_3_PI_OVER_5 INT16_C(18196)
#define TAKUM_LINEAR32_3_PI_OVER_5 INT32_C(1192518553)
#define TAKUM_LINEAR64_3_PI_OVER_5 INT64_C(5121828184835532842)

/* 4π */
#define TAKUM8_4_PI  INT8_C(84)
#define TAKUM16_4_PI INT16_C(21536)
#define TAKUM32_4_PI INT32_C(1411368146)
#define TAKUM64_4_PI INT64_C(6061780029559728912)

#define TAKUM_LINEAR8_4_PI  INT8_C(81)
#define TAKUM_LINEAR16_4_PI INT16_C(20772)
#define TAKUM_LINEAR32_4_PI INT32_C(1361330027)
#define TAKUM_LINEAR64_4_PI INT64_C(5846867943023289097)

/* 4π/3 */
#define TAKUM8_4_PI_OVER_3  INT8_C(79)
#define TAKUM16_4_PI_OVER_3 INT16_C(20342)
#define TAKUM32_4_PI_OVER_3 INT32_C(1333105767)
#define TAKUM64_4_PI_OVER_3 INT64_C(5725645669669818581)

#define TAKUM_LINEAR8_4_PI_OVER_3  INT8_C(76)
#define TAKUM_LINEAR16_4_PI_OVER_3 INT16_C(19504)
#define TAKUM_LINEAR32_4_PI_OVER_3 INT32_C(1278235790)
#define TAKUM_LINEAR64_4_PI_OVER_3 INT64_C(5489980914817358177)

/* 4π/5 */
#define TAKUM8_4_PI_OVER_5  INT8_C(75)
#define TAKUM16_4_PI_OVER_5 INT16_C(19295)
#define TAKUM32_4_PI_OVER_5 INT32_C(1264543912)
#define TAKUM64_4_PI_OVER_5 INT64_C(5431174746297810027)

#define TAKUM_LINEAR8_4_PI_OVER_5  INT8_C(73)
#define TAKUM_LINEAR16_4_PI_OVER_5 INT16_C(18695)
#define TAKUM_LINEAR32_4_PI_OVER_5 INT32_C(1225182174)
#define TAKUM_LINEAR64_4_PI_OVER_5 INT64_C(5262117367482955790)

/* 5π */
#define TAKUM8_5_PI  INT8_C(85)
#define TAKUM16_5_PI INT16_C(21764)
#define TAKUM32_5_PI INT32_C(1426343056)
#define TAKUM64_5_PI INT64_C(6126096779290852382)

#define TAKUM_LINEAR8_5_PI  INT8_C(82)
#define TAKUM_LINEAR16_5_PI INT16_C(20973)
#define TAKUM_LINEAR32_5_PI INT32_C(1374506821)
#define TAKUM_LINEAR64_5_PI INT64_C(5903461845039516619)

/* 5π/2 */
#define TAKUM8_5_PI_OVER_2  INT8_C(82)
#define TAKUM16_5_PI_OVER_2 INT16_C(21054)
#define TAKUM32_5_PI_OVER_2 INT32_C(1379826736)
#define TAKUM64_5_PI_OVER_2 INT64_C(5926310706709560887)

#define TAKUM_LINEAR8_5_PI_OVER_2  INT8_C(80)
#define TAKUM_LINEAR16_5_PI_OVER_2 INT16_C(20443)
#define TAKUM_LINEAR32_5_PI_OVER_2 INT32_C(1339727498)
#define TAKUM_LINEAR64_5_PI_OVER_2 INT64_C(5754085790893086614)

/* 5π/3 */
#define TAKUM8_5_PI_OVER_3  INT8_C(81)
#define TAKUM16_5_PI_OVER_3 INT16_C(20639)
#define TAKUM32_5_PI_OVER_3 INT32_C(1352616434)
#define TAKUM64_5_PI_OVER_3 INT64_C(5809443346083150200)

#define TAKUM_LINEAR8_5_PI_OVER_3  INT8_C(77)
#define TAKUM_LINEAR16_5_PI_OVER_3 INT16_C(19772)
#define TAKUM_LINEAR32_5_PI_OVER_3 INT32_C(1295804850)
#define TAKUM_LINEAR64_5_PI_OVER_3 INT64_C(5565439450838994873)

/* 5π/4 */
#define TAKUM8_5_PI_OVER_4  INT8_C(79)
#define TAKUM16_5_PI_OVER_4 INT16_C(20209)
#define TAKUM32_5_PI_OVER_4 INT32_C(1324443553)
#define TAKUM64_5_PI_OVER_4 INT64_C(5688441745222303905)

#define TAKUM_LINEAR8_5_PI_OVER_4  INT8_C(76)
#define TAKUM_LINEAR16_5_PI_OVER_4 INT16_C(19419)
#define TAKUM_LINEAR32_5_PI_OVER_4 INT32_C(1272618634)
#define TAKUM_LINEAR64_5_PI_OVER_4 INT64_C(5465855414741374870)

/* 5π/6 */
#define TAKUM8_5_PI_OVER_6  INT8_C(76)
#define TAKUM16_5_PI_OVER_6 INT16_C(19379)
#define TAKUM32_5_PI_OVER_6 INT32_C(1270022947)
#define TAKUM64_5_PI_OVER_6 INT64_C(5454707023969482530)

#define TAKUM_LINEAR8_5_PI_OVER_6  INT8_C(73)
#define TAKUM_LINEAR16_5_PI_OVER_6 INT16_C(18748)
#define TAKUM_LINEAR32_5_PI_OVER_6 INT32_C(1228695986)
#define TAKUM_LINEAR64_5_PI_OVER_6 INT64_C(5277209074687283129)

/* 6π */
#define TAKUM8_6_PI  INT8_C(86)
#define TAKUM16_6_PI INT16_C(21951)
#define TAKUM32_6_PI INT32_C(1438578449)
#define TAKUM64_6_PI INT64_C(6178647390186139600)

#define TAKUM_LINEAR8_6_PI  INT8_C(82)
#define TAKUM_LINEAR16_6_PI INT16_C(21083)
#define TAKUM_LINEAR32_6_PI INT32_C(1381707664)
#define TAKUM_LINEAR64_6_PI INT64_C(5934389229082917447)

/* 6π/5 */
#define TAKUM8_6_PI_OVER_5  INT8_C(79)
#define TAKUM16_6_PI_OVER_5 INT16_C(20126)
#define TAKUM32_6_PI_OVER_5 INT32_C(1318964518)
#define TAKUM64_6_PI_OVER_5 INT64_C(5664909467550631402)

#define TAKUM_LINEAR8_6_PI_OVER_5  INT8_C(76)
#define TAKUM_LINEAR16_6_PI_OVER_5 INT16_C(19338)
#define TAKUM_LINEAR32_6_PI_OVER_5 INT32_C(1267347916)
#define TAKUM_LINEAR64_6_PI_OVER_5 INT64_C(5443217853934883861)

/* Euler-Mascheroni Constant γ */
#define TAKUM8_GAMMA  INT8_C(56)
#define TAKUM16_GAMMA INT16_C(14235)
#define TAKUM32_GAMMA INT32_C(932875042)
#define TAKUM64_GAMMA INT64_C(4006667796493970688)

#define TAKUM_LINEAR8_GAMMA  INT8_C(57)
#define TAKUM_LINEAR16_GAMMA INT16_C(14652)
#define TAKUM_LINEAR32_GAMMA INT32_C(960251518)
#define TAKUM_LINEAR64_GAMMA INT64_C(4124248866681457786)

/* lb(10) */
#define TAKUM8_LB_10  INT8_C(78)
#define TAKUM16_LB_10 INT16_C(19867)
#define TAKUM32_LB_10 INT32_C(1301985159)
#define TAKUM64_LB_10 INT64_C(5591983679339631233)

#define TAKUM_LINEAR8_LB_10  INT8_C(75)
#define TAKUM_LINEAR16_LB_10 INT16_C(19109)
#define TAKUM_LINEAR32_LB_10 INT32_C(1252316098)
#define TAKUM_LINEAR64_LB_10 INT64_C(5378656686748261464)

/* lb(e) */
#define TAKUM8_LB_E  INT8_C(70)
#define TAKUM16_LB_E INT16_C(17885)
#define TAKUM32_LB_E INT32_C(1172126887)
#define TAKUM64_LB_E INT64_C(5034246646282250152)

#define TAKUM_LINEAR8_LB_E  INT8_C(68)
#define TAKUM_LINEAR16_LB_E INT16_C(17291)
#define TAKUM_LINEAR32_LB_E INT32_C(1133159347)
#define TAKUM_LINEAR64_LB_E INT64_C(4866882334739234572)

/* lg(2) */
#define TAKUM8_LG_2  INT8_C(50)
#define TAKUM16_LG_2 INT16_C(12901)
#define TAKUM32_LG_2 INT32_C(845498489)
#define TAKUM64_LG_2 INT64_C(3631388357515144575)

#define TAKUM_LINEAR8_LG_2  INT8_C(53)
#define TAKUM_LINEAR16_LG_2 INT16_C(13521)
#define TAKUM_LINEAR32_LG_2 INT32_C(886113492)
#define TAKUM_LINEAR64_LG_2 INT64_C(3805828469353250749)

/* lg(e) */
#define TAKUM8_LG_E  INT8_C(53)
#define TAKUM16_LG_E INT16_C(13652)
#define TAKUM32_LG_E INT32_C(894691020)
#define TAKUM64_LG_E INT64_C(3842668671442575700)

#define TAKUM_LINEAR8_LG_E  INT8_C(55)
#define TAKUM_LINEAR16_LG_E INT16_C(14067)
#define TAKUM_LINEAR32_LG_E INT32_C(921886405)
#define TAKUM_LINEAR64_LG_E INT64_C(3959471961338889101)

/* ln(10) */
#define TAKUM8_LN_10  INT8_C(75)
#define TAKUM16_LN_10 INT16_C(19116)
#define TAKUM32_LN_10 INT32_C(1252792628)
#define TAKUM64_LN_10 INT64_C(5380703365412200108)

#define TAKUM_LINEAR8_LN_10  INT8_C(73)
#define TAKUM_LINEAR16_LN_10 INT16_C(18587)
#define TAKUM_LINEAR32_LN_10 INT32_C(1218112623)
#define TAKUM_LINEAR64_LN_10 INT64_C(5231753878316598625)

/* ln(2) */
#define TAKUM8_LN_2  INT8_C(58)
#define TAKUM16_LN_2 INT16_C(14883)
#define TAKUM32_LN_2 INT32_C(975356761)
#define TAKUM64_LN_2 INT64_C(4189125390572525656)

#define TAKUM_LINEAR8_LN_2  INT8_C(59)
#define TAKUM_LINEAR16_LN_2 INT16_C(15127)
#define TAKUM_LINEAR32_LN_2 INT32_C(991371647)
#define TAKUM_LINEAR64_LN_2 INT64_C(4257908804145706907)

/* constant 1 */
#define TAKUM8_ONE  INT8_C(64)
#define TAKUM16_ONE INT16_C(16384)
#define TAKUM32_ONE INT32_C(1073741824)
#define TAKUM64_ONE INT64_C(4611686018427387904)

#define TAKUM_LINEAR8_ONE  INT8_C(64)
#define TAKUM_LINEAR16_ONE INT16_C(16384)
#define TAKUM_LINEAR32_ONE INT32_C(1073741824)
#define TAKUM_LINEAR64_ONE INT64_C(4611686018427387904)

/* Golden Ratio φ */
#define TAKUM8_PHI  INT8_C(72)
#define TAKUM16_PHI INT16_C(18355)
#define TAKUM32_PHI INT32_C(1202916140)
#define TAKUM64_PHI INT64_C(5166485479809712741)

#define TAKUM_LINEAR8_PHI  INT8_C(69)
#define TAKUM_LINEAR16_PHI INT16_C(17650)
#define TAKUM_LINEAR32_PHI INT32_C(1156692942)
#define TAKUM_LINEAR64_PHI INT64_C(4967958356531237857)

/* π */
#define TAKUM8_PI  INT8_C(77)
#define TAKUM16_PI INT16_C(19752)
#define TAKUM32_PI INT32_C(1294493732)
#define TAKUM64_PI INT64_C(5559808245760056966)

#define TAKUM_LINEAR8_PI  INT8_C(74)
#define TAKUM_LINEAR16_PI INT16_C(19016)
#define TAKUM_LINEAR32_PI INT32_C(1246265045)
#define TAKUM_LINEAR64_PI INT64_C(5352667610708919826)

/* π/2 */
#define TAKUM8_PI_OVER_2  INT8_C(71)
#define TAKUM16_PI_OVER_2 INT16_C(18234)
#define TAKUM32_PI_OVER_2 INT32_C(1194962633)
#define TAKUM64_PI_OVER_2 INT64_C(5132325430464136561)

#define TAKUM_LINEAR8_PI_OVER_2  INT8_C(69)
#define TAKUM_LINEAR16_PI_OVER_2 INT16_C(17553)
#define TAKUM_LINEAR32_PI_OVER_2 INT32_C(1150352810)
#define TAKUM_LINEAR64_PI_OVER_2 INT64_C(4940727698383604771)

/* π/3 */
#define TAKUM8_PI_OVER_3  INT8_C(65)
#define TAKUM16_PI_OVER_3 INT16_C(16573)
#define TAKUM32_PI_OVER_3 INT32_C(1086121422)
#define TAKUM64_PI_OVER_3 INT64_C(4664855987958493812)

#define TAKUM_LINEAR8_PI_OVER_3  INT8_C(64)
#define TAKUM_LINEAR16_PI_OVER_3 INT16_C(16481)
#define TAKUM_LINEAR32_PI_OVER_3 INT32_C(1080076572)
#define TAKUM_LINEAR64_PI_OVER_3 INT64_C(4638893554297057986)

/* π/4 */
#define TAKUM8_PI_OVER_4  INT8_C(60)
#define TAKUM16_PI_OVER_4 INT16_C(15395)
#define TAKUM32_PI_OVER_4 INT32_C(1008897354)
#define TAKUM64_PI_OVER_4 INT64_C(4333181140138970582)

#define TAKUM_LINEAR8_PI_OVER_4  INT8_C(61)
#define TAKUM_LINEAR16_PI_OVER_4 INT16_C(15505)
#define TAKUM_LINEAR32_PI_OVER_4 INT32_C(1016135082)
#define TAKUM_LINEAR64_PI_OVER_4 INT64_C(4364266946080181283)

/* π/5 */
#define TAKUM8_PI_OVER_5  INT8_C(57)
#define TAKUM16_PI_OVER_5 INT16_C(14481)
#define TAKUM32_PI_OVER_5 INT32_C(948997713)
#define TAKUM64_PI_OVER_5 INT64_C(4075914141214476705)

#define TAKUM_LINEAR8_PI_OVER_5  INT8_C(58)
#define TAKUM_LINEAR16_PI_OVER_5 INT16_C(14862)
#define TAKUM_LINEAR32_PI_OVER_5 INT32_C(973969339)
#define TAKUM_LINEAR64_PI_OVER_5 INT64_C(4183166459628253212)

/* π/6 */
#define TAKUM8_PI_OVER_6  INT8_C(55)
#define TAKUM16_PI_OVER_6 INT16_C(14035)
#define TAKUM32_PI_OVER_6 INT32_C(919790119)
#define TAKUM64_PI_OVER_6 INT64_C(3950468481878646125)

#define TAKUM_LINEAR8_PI_OVER_6  INT8_C(56)
#define TAKUM_LINEAR16_PI_OVER_6 INT16_C(14433)
#define TAKUM_LINEAR32_PI_OVER_6 INT32_C(945858844)
#define TAKUM_LINEAR64_PI_OVER_6 INT64_C(4062432801993634498)

/* √2 */
#define TAKUM8_SQUARE_ROOT_2  INT8_C(70)
#define TAKUM16_SQUARE_ROOT_2 INT16_C(17804)
#define TAKUM32_SQUARE_ROOT_2 INT32_C(1166774464)
#define TAKUM64_SQUARE_ROOT_2 INT64_C(5011258163589970893)

#define TAKUM_LINEAR8_SQUARE_ROOT_2  INT8_C(67)
#define TAKUM_LINEAR16_SQUARE_ROOT_2 INT16_C(17232)
#define TAKUM_LINEAR32_SQUARE_ROOT_2 INT32_C(1129336627)
#define TAKUM_LINEAR64_SQUARE_ROOT_2 INT64_C(4850463880207263304)

/* √3 */
#define TAKUM8_SQUARE_ROOT_3  INT8_C(72)
#define TAKUM16_SQUARE_ROOT_3 INT16_C(18533)
#define TAKUM32_SQUARE_ROOT_3 INT32_C(1214577311)
#define TAKUM64_SQUARE_ROOT_3 INT64_C(5216569827786801830)

#define TAKUM_LINEAR8_SQUARE_ROOT_3  INT8_C(70)
#define TAKUM_LINEAR16_SQUARE_ROOT_3 INT16_C(17883)
#define TAKUM_LINEAR32_SQUARE_ROOT_3 INT32_C(1171996020)
#define TAKUM_LINEAR64_SQUARE_ROOT_3 INT64_C(5033684577682871610)

/* √5 */
#define TAKUM8_SQUARE_ROOT_5  INT8_C(74)
#define TAKUM16_SQUARE_ROOT_5 INT16_C(19056)
#define TAKUM32_SQUARE_ROOT_5 INT32_C(1248858238)
#define TAKUM64_SQUARE_ROOT_5 INT64_C(5363805289472806107)

#define TAKUM_LINEAR8_SQUARE_ROOT_5  INT8_C(72)
#define TAKUM_LINEAR16_SQUARE_ROOT_5 INT16_C(18553)
#define TAKUM_LINEAR32_SQUARE_ROOT_5 INT32_C(1215880679)
#define TAKUM_LINEAR64_SQUARE_ROOT_5 INT64_C(5222167751706880496)

/* √6 */
#define TAKUM8_SQUARE_ROOT_6  INT8_C(75)
#define TAKUM16_SQUARE_ROOT_6 INT16_C(19243)
#define TAKUM32_SQUARE_ROOT_6 INT32_C(1261093631)
#define TAKUM64_SQUARE_ROOT_6 INT64_C(5416355900368093325)

#define TAKUM_LINEAR8_SQUARE_ROOT_6  INT8_C(73)
#define TAKUM_LINEAR16_SQUARE_ROOT_6 INT16_C(18662)
#define TAKUM_LINEAR32_SQUARE_ROOT_6 INT32_C(1223041925)
#define TAKUM_LINEAR64_SQUARE_ROOT_6 INT64_C(5252925069550177183)

/* Base 10 Exponential Function */
takum8 takum8_10_raised(takum8);
takum16 takum16_10_raised(takum16);
takum32 takum32_10_raised(takum32);
takum64 takum64_10_raised(takum64);

takum_linear8 takum_linear8_10_raised(takum_linear8);
takum_linear16 takum_linear16_10_raised(takum_linear16);
takum_linear32 takum_linear32_10_raised(takum_linear32);
takum_linear64 takum_linear64_10_raised(takum_linear64);

/* Base 10 Exponential Function Minus 1 */
takum8 takum8_10_raised_minus_1(takum8);
takum16 takum16_10_raised_minus_1(takum16);
takum32 takum32_10_raised_minus_1(takum32);
takum64 takum64_10_raised_minus_1(takum64);

takum_linear8 takum_linear8_10_raised_minus_1(takum_linear8);
takum_linear16 takum_linear16_10_raised_minus_1(takum_linear16);
takum_linear32 takum_linear32_10_raised_minus_1(takum_linear32);
takum_linear64 takum_linear64_10_raised_minus_1(takum_linear64);

/* Base 2 Exponential Function */
takum8 takum8_2_raised(takum8);
takum16 takum16_2_raised(takum16);
takum32 takum32_2_raised(takum32);
takum64 takum64_2_raised(takum64);

takum_linear8 takum_linear8_2_raised(takum_linear8);
takum_linear16 takum_linear16_2_raised(takum_linear16);
takum_linear32 takum_linear32_2_raised(takum_linear32);
takum_linear64 takum_linear64_2_raised(takum_linear64);

/* Base 2 Exponential Function Minus 1 */
takum8 takum8_2_raised_minus_1(takum8);
takum16 takum16_2_raised_minus_1(takum16);
takum32 takum32_2_raised_minus_1(takum32);
takum64 takum64_2_raised_minus_1(takum64);

takum_linear8 takum_linear8_2_raised_minus_1(takum_linear8);
takum_linear16 takum_linear16_2_raised_minus_1(takum_linear16);
takum_linear32 takum_linear32_2_raised_minus_1(takum_linear32);
takum_linear64 takum_linear64_2_raised_minus_1(takum_linear64);

/* Absolute */
static inline takum8
takum8_absolute(takum8 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

static inline takum16
takum16_absolute(takum16 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

static inline takum32
takum32_absolute(takum32 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

static inline takum64
takum64_absolute(takum64 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

static inline takum_linear8
takum_linear8_absolute(takum_linear8 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

static inline takum_linear16
takum_linear16_absolute(takum_linear16 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

static inline takum_linear32
takum_linear32_absolute(takum_linear32 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

static inline takum_linear64
takum_linear64_absolute(takum_linear64 t)
{
	return (t < 0) * (-t) + (t >= 0) * t;
}

/* Addition */
takum8 takum8_addition(takum8, takum8);
takum16 takum16_addition(takum16, takum16);
takum32 takum32_addition(takum32, takum32);
takum64 takum64_addition(takum64, takum64);

takum_linear8 takum_linear8_addition(takum_linear8, takum_linear8);
takum_linear16 takum_linear16_addition(takum_linear16, takum_linear16);
takum_linear32 takum_linear32_addition(takum_linear32, takum_linear32);
takum_linear64 takum_linear64_addition(takum_linear64, takum_linear64);

/* Arccosine */
takum8 takum8_arccos(takum8);
takum16 takum16_arccos(takum16);
takum32 takum32_arccos(takum32);
takum64 takum64_arccos(takum64);

takum_linear8 takum_linear8_arccos(takum_linear8);
takum_linear16 takum_linear16_arccos(takum_linear16);
takum_linear32 takum_linear32_arccos(takum_linear32);
takum_linear64 takum_linear64_arccos(takum_linear64);

/* Arccosine Over π */
takum8 takum8_arccos_over_pi(takum8);
takum16 takum16_arccos_over_pi(takum16);
takum32 takum32_arccos_over_pi(takum32);
takum64 takum64_arccos_over_pi(takum64);

takum_linear8 takum_linear8_arccos_over_pi(takum_linear8);
takum_linear16 takum_linear16_arccos_over_pi(takum_linear16);
takum_linear32 takum_linear32_arccos_over_pi(takum_linear32);
takum_linear64 takum_linear64_arccos_over_pi(takum_linear64);

/* Arccotangent */
takum8 takum8_arccot(takum8);
takum16 takum16_arccot(takum16);
takum32 takum32_arccot(takum32);
takum64 takum64_arccot(takum64);

takum_linear8 takum_linear8_arccot(takum_linear8);
takum_linear16 takum_linear16_arccot(takum_linear16);
takum_linear32 takum_linear32_arccot(takum_linear32);
takum_linear64 takum_linear64_arccot(takum_linear64);

/* Arccotangent Over π */
takum8 takum8_arccot_over_pi(takum8);
takum16 takum16_arccot_over_pi(takum16);
takum32 takum32_arccot_over_pi(takum32);
takum64 takum64_arccot_over_pi(takum64);

takum_linear8 takum_linear8_arccot_over_pi(takum_linear8);
takum_linear16 takum_linear16_arccot_over_pi(takum_linear16);
takum_linear32 takum_linear32_arccot_over_pi(takum_linear32);
takum_linear64 takum_linear64_arccot_over_pi(takum_linear64);

/* Arccosecant */
takum8 takum8_arccsc(takum8);
takum16 takum16_arccsc(takum16);
takum32 takum32_arccsc(takum32);
takum64 takum64_arccsc(takum64);

takum_linear8 takum_linear8_arccsc(takum_linear8);
takum_linear16 takum_linear16_arccsc(takum_linear16);
takum_linear32 takum_linear32_arccsc(takum_linear32);
takum_linear64 takum_linear64_arccsc(takum_linear64);

/* Arccosecant Over π */
takum8 takum8_arccsc_over_pi(takum8);
takum16 takum16_arccsc_over_pi(takum16);
takum32 takum32_arccsc_over_pi(takum32);
takum64 takum64_arccsc_over_pi(takum64);

takum_linear8 takum_linear8_arccsc_over_pi(takum_linear8);
takum_linear16 takum_linear16_arccsc_over_pi(takum_linear16);
takum_linear32 takum_linear32_arccsc_over_pi(takum_linear32);
takum_linear64 takum_linear64_arccsc_over_pi(takum_linear64);

/* Area Hyperbolic Cosine */
takum8 takum8_arcosh(takum8);
takum16 takum16_arcosh(takum16);
takum32 takum32_arcosh(takum32);
takum64 takum64_arcosh(takum64);

takum_linear8 takum_linear8_arcosh(takum_linear8);
takum_linear16 takum_linear16_arcosh(takum_linear16);
takum_linear32 takum_linear32_arcosh(takum_linear32);
takum_linear64 takum_linear64_arcosh(takum_linear64);

/* Area Hyperbolic Cotangent */
takum8 takum8_arcoth(takum8);
takum16 takum16_arcoth(takum16);
takum32 takum32_arcoth(takum32);
takum64 takum64_arcoth(takum64);

takum_linear8 takum_linear8_arcoth(takum_linear8);
takum_linear16 takum_linear16_arcoth(takum_linear16);
takum_linear32 takum_linear32_arcoth(takum_linear32);
takum_linear64 takum_linear64_arcoth(takum_linear64);

/* Area Hyperbolic Cosecant */
takum8 takum8_arcsch(takum8);
takum16 takum16_arcsch(takum16);
takum32 takum32_arcsch(takum32);
takum64 takum64_arcsch(takum64);

takum_linear8 takum_linear8_arcsch(takum_linear8);
takum_linear16 takum_linear16_arcsch(takum_linear16);
takum_linear32 takum_linear32_arcsch(takum_linear32);
takum_linear64 takum_linear64_arcsch(takum_linear64);

/* Arcsecant */
takum8 takum8_arcsec(takum8);
takum16 takum16_arcsec(takum16);
takum32 takum32_arcsec(takum32);
takum64 takum64_arcsec(takum64);

takum_linear8 takum_linear8_arcsec(takum_linear8);
takum_linear16 takum_linear16_arcsec(takum_linear16);
takum_linear32 takum_linear32_arcsec(takum_linear32);
takum_linear64 takum_linear64_arcsec(takum_linear64);

/* Arcsecant Over π */
takum8 takum8_arcsec_over_pi(takum8);
takum16 takum16_arcsec_over_pi(takum16);
takum32 takum32_arcsec_over_pi(takum32);
takum64 takum64_arcsec_over_pi(takum64);

takum_linear8 takum_linear8_arcsec_over_pi(takum_linear8);
takum_linear16 takum_linear16_arcsec_over_pi(takum_linear16);
takum_linear32 takum_linear32_arcsec_over_pi(takum_linear32);
takum_linear64 takum_linear64_arcsec_over_pi(takum_linear64);

/* Arcsine */
takum8 takum8_arcsin(takum8);
takum16 takum16_arcsin(takum16);
takum32 takum32_arcsin(takum32);
takum64 takum64_arcsin(takum64);

takum_linear8 takum_linear8_arcsin(takum_linear8);
takum_linear16 takum_linear16_arcsin(takum_linear16);
takum_linear32 takum_linear32_arcsin(takum_linear32);
takum_linear64 takum_linear64_arcsin(takum_linear64);

/* Arcsine Over π */
takum8 takum8_arcsin_over_pi(takum8);
takum16 takum16_arcsin_over_pi(takum16);
takum32 takum32_arcsin_over_pi(takum32);
takum64 takum64_arcsin_over_pi(takum64);

takum_linear8 takum_linear8_arcsin_over_pi(takum_linear8);
takum_linear16 takum_linear16_arcsin_over_pi(takum_linear16);
takum_linear32 takum_linear32_arcsin_over_pi(takum_linear32);
takum_linear64 takum_linear64_arcsin_over_pi(takum_linear64);

/* 2-Argument Arctangent */
takum8 takum8_arctan2(takum8, takum8);
takum16 takum16_arctan2(takum16, takum16);
takum32 takum32_arctan2(takum32, takum32);
takum64 takum64_arctan2(takum64, takum64);

takum_linear8 takum_linear8_arctan2(takum_linear8, takum_linear8);
takum_linear16 takum_linear16_arctan2(takum_linear16, takum_linear16);
takum_linear32 takum_linear32_arctan2(takum_linear32, takum_linear32);
takum_linear64 takum_linear64_arctan2(takum_linear64, takum_linear64);

/* 2-Argument Arctangent Over π */
takum8 takum8_arctan2_over_pi(takum8, takum8);
takum16 takum16_arctan2_over_pi(takum16, takum16);
takum32 takum32_arctan2_over_pi(takum32, takum32);
takum64 takum64_arctan2_over_pi(takum64, takum64);

takum_linear8 takum_linear8_arctan2_over_pi(takum_linear8, takum_linear8);
takum_linear16 takum_linear16_arctan2_over_pi(takum_linear16, takum_linear16);
takum_linear32 takum_linear32_arctan2_over_pi(takum_linear32, takum_linear32);
takum_linear64 takum_linear64_arctan2_over_pi(takum_linear64, takum_linear64);

/* Arctangent */
takum8 takum8_arctan(takum8);
takum16 takum16_arctan(takum16);
takum32 takum32_arctan(takum32);
takum64 takum64_arctan(takum64);

takum_linear8 takum_linear8_arctan(takum_linear8);
takum_linear16 takum_linear16_arctan(takum_linear16);
takum_linear32 takum_linear32_arctan(takum_linear32);
takum_linear64 takum_linear64_arctan(takum_linear64);

/* Arctangent Over π */
takum8 takum8_arctan_over_pi(takum8);
takum16 takum16_arctan_over_pi(takum16);
takum32 takum32_arctan_over_pi(takum32);
takum64 takum64_arctan_over_pi(takum64);

takum_linear8 takum_linear8_arctan_over_pi(takum_linear8);
takum_linear16 takum_linear16_arctan_over_pi(takum_linear16);
takum_linear32 takum_linear32_arctan_over_pi(takum_linear32);
takum_linear64 takum_linear64_arctan_over_pi(takum_linear64);

/* Area Hyperbolic Secant */
takum8 takum8_arsech(takum8);
takum16 takum16_arsech(takum16);
takum32 takum32_arsech(takum32);
takum64 takum64_arsech(takum64);

takum_linear8 takum_linear8_arsech(takum_linear8);
takum_linear16 takum_linear16_arsech(takum_linear16);
takum_linear32 takum_linear32_arsech(takum_linear32);
takum_linear64 takum_linear64_arsech(takum_linear64);

/* Area Hyperbolic Sine */
takum8 takum8_arsinh(takum8);
takum16 takum16_arsinh(takum16);
takum32 takum32_arsinh(takum32);
takum64 takum64_arsinh(takum64);

takum_linear8 takum_linear8_arsinh(takum_linear8);
takum_linear16 takum_linear16_arsinh(takum_linear16);
takum_linear32 takum_linear32_arsinh(takum_linear32);
takum_linear64 takum_linear64_arsinh(takum_linear64);

/* Area Hyperbolic Tangent */
takum8 takum8_artanh(takum8);
takum16 takum16_artanh(takum16);
takum32 takum32_artanh(takum32);
takum64 takum64_artanh(takum64);

takum_linear8 takum_linear8_artanh(takum_linear8);
takum_linear16 takum_linear16_artanh(takum_linear16);
takum_linear32 takum_linear32_artanh(takum_linear32);
takum_linear64 takum_linear64_artanh(takum_linear64);

/* Cosine */
takum8 takum8_cos(takum8);
takum16 takum16_cos(takum16);
takum32 takum32_cos(takum32);
takum64 takum64_cos(takum64);

takum_linear8 takum_linear8_cos(takum_linear8);
takum_linear16 takum_linear16_cos(takum_linear16);
takum_linear32 takum_linear32_cos(takum_linear32);
takum_linear64 takum_linear64_cos(takum_linear64);

/* Cosine π Times */
takum8 takum8_cos_pi_times(takum8);
takum16 takum16_cos_pi_times(takum16);
takum32 takum32_cos_pi_times(takum32);
takum64 takum64_cos_pi_times(takum64);

takum_linear8 takum_linear8_cos_pi_times(takum_linear8);
takum_linear16 takum_linear16_cos_pi_times(takum_linear16);
takum_linear32 takum_linear32_cos_pi_times(takum_linear32);
takum_linear64 takum_linear64_cos_pi_times(takum_linear64);

/* Hyperbolic Cosine */
takum8 takum8_cosh(takum8);
takum16 takum16_cosh(takum16);
takum32 takum32_cosh(takum32);
takum64 takum64_cosh(takum64);

takum_linear8 takum_linear8_cosh(takum_linear8);
takum_linear16 takum_linear16_cosh(takum_linear16);
takum_linear32 takum_linear32_cosh(takum_linear32);
takum_linear64 takum_linear64_cosh(takum_linear64);

/* Cotangent */
takum8 takum8_cot(takum8);
takum16 takum16_cot(takum16);
takum32 takum32_cot(takum32);
takum64 takum64_cot(takum64);

takum_linear8 takum_linear8_cot(takum_linear8);
takum_linear16 takum_linear16_cot(takum_linear16);
takum_linear32 takum_linear32_cot(takum_linear32);
takum_linear64 takum_linear64_cot(takum_linear64);

/* Cotangent π Times */
takum8 takum8_cot_pi_times(takum8);
takum16 takum16_cot_pi_times(takum16);
takum32 takum32_cot_pi_times(takum32);
takum64 takum64_cot_pi_times(takum64);

takum_linear8 takum_linear8_cot_pi_times(takum_linear8);
takum_linear16 takum_linear16_cot_pi_times(takum_linear16);
takum_linear32 takum_linear32_cot_pi_times(takum_linear32);
takum_linear64 takum_linear64_cot_pi_times(takum_linear64);

/* Hyperbolic Cotangent */
takum8 takum8_coth(takum8);
takum16 takum16_coth(takum16);
takum32 takum32_coth(takum32);
takum64 takum64_coth(takum64);

takum_linear8 takum_linear8_coth(takum_linear8);
takum_linear16 takum_linear16_coth(takum_linear16);
takum_linear32 takum_linear32_coth(takum_linear32);
takum_linear64 takum_linear64_coth(takum_linear64);

/* Cosecant */
takum8 takum8_csc(takum8);
takum16 takum16_csc(takum16);
takum32 takum32_csc(takum32);
takum64 takum64_csc(takum64);

takum_linear8 takum_linear8_csc(takum_linear8);
takum_linear16 takum_linear16_csc(takum_linear16);
takum_linear32 takum_linear32_csc(takum_linear32);
takum_linear64 takum_linear64_csc(takum_linear64);

/* Cosecant π Times */
takum8 takum8_csc_pi_times(takum8);
takum16 takum16_csc_pi_times(takum16);
takum32 takum32_csc_pi_times(takum32);
takum64 takum64_csc_pi_times(takum64);

takum_linear8 takum_linear8_csc_pi_times(takum_linear8);
takum_linear16 takum_linear16_csc_pi_times(takum_linear16);
takum_linear32 takum_linear32_csc_pi_times(takum_linear32);
takum_linear64 takum_linear64_csc_pi_times(takum_linear64);

/* Hyperbolic Cosecant */
takum8 takum8_csch(takum8);
takum16 takum16_csch(takum16);
takum32 takum32_csch(takum32);
takum64 takum64_csch(takum64);

takum_linear8 takum_linear8_csch(takum_linear8);
takum_linear16 takum_linear16_csch(takum_linear16);
takum_linear32 takum_linear32_csch(takum_linear32);
takum_linear64 takum_linear64_csch(takum_linear64);

/* Division */
takum8 takum8_division(takum8, takum8);
takum16 takum16_division(takum16, takum16);
takum32 takum32_division(takum32, takum32);
takum64 takum64_division(takum64, takum64);

takum_linear8 takum_linear8_division(takum_linear8, takum_linear8);
takum_linear16 takum_linear16_division(takum_linear16, takum_linear16);
takum_linear32 takum_linear32_division(takum_linear32, takum_linear32);
takum_linear64 takum_linear64_division(takum_linear64, takum_linear64);

/* Exponential Function */
takum8 takum8_exp(takum8);
takum16 takum16_exp(takum16);
takum32 takum32_exp(takum32);
takum64 takum64_exp(takum64);

takum_linear8 takum_linear8_exp(takum_linear8);
takum_linear16 takum_linear16_exp(takum_linear16);
takum_linear32 takum_linear32_exp(takum_linear32);
takum_linear64 takum_linear64_exp(takum_linear64);

/* Exponential Function Minus 1 */
takum8 takum8_exp_minus_1(takum8);
takum16 takum16_exp_minus_1(takum16);
takum32 takum32_exp_minus_1(takum32);
takum64 takum64_exp_minus_1(takum64);

takum_linear8 takum_linear8_exp_minus_1(takum_linear8);
takum_linear16 takum_linear16_exp_minus_1(takum_linear16);
takum_linear32 takum_linear32_exp_minus_1(takum_linear32);
takum_linear64 takum_linear64_exp_minus_1(takum_linear64);

/* Conversion from extended float */
takum8 takum8_from_extended_float(long double);
takum16 takum16_from_extended_float(long double);
takum32 takum32_from_extended_float(long double);
takum64 takum64_from_extended_float(long double);

takum_linear8 takum_linear8_from_extended_float(long double);
takum_linear16 takum_linear16_from_extended_float(long double);
takum_linear32 takum_linear32_from_extended_float(long double);
takum_linear64 takum_linear64_from_extended_float(long double);

/* Conversion from float32 */
takum8 takum8_from_float32(float);
takum16 takum16_from_float32(float);
takum32 takum32_from_float32(float);
takum64 takum64_from_float32(float);

takum_linear8 takum_linear8_from_float32(float);
takum_linear16 takum_linear16_from_float32(float);
takum_linear32 takum_linear32_from_float32(float);
takum_linear64 takum_linear64_from_float32(float);

/* Conversion from float64 */
takum8 takum8_from_float64(double);
takum16 takum16_from_float64(double);
takum32 takum32_from_float64(double);
takum64 takum64_from_float64(double);

takum_linear8 takum_linear8_from_float64(double);
takum_linear16 takum_linear16_from_float64(double);
takum_linear32 takum_linear32_from_float64(double);
takum_linear64 takum_linear64_from_float64(double);

/* Takum conversion helper macros */
#define TAKUM_INTERNAL_CONVERT_EXPAND(FROM, TO)                                \
	do {                                                                   \
		const union takum_internal_takum##FROM##_union in = {          \
			.value = t,                                            \
		};                                                             \
		union takum_internal_takum##TO##_union out = {                 \
			.bits = ((uint##TO##_t)in.bits) << (TO - FROM),        \
		};                                                             \
                                                                               \
		return out.value;                                              \
	} while (0);

#define TAKUM_INTERNAL_CONVERT_REDUCE(FROM, TO)                                \
	do {                                                                   \
		const union takum_internal_takum##FROM##_union in = {          \
			.value = t,                                            \
		};                                                             \
		union takum_internal_takum##TO##_union out = {                 \
			.bits = (in.bits >> (FROM - TO)) +                     \
			        ((in.bits & UINT##FROM##_C(0x80)               \
			                            << (FROM - TO - 8)) ==     \
			         UINT##FROM##_C(0x80) << (FROM - TO - 8)),     \
		};                                                             \
                                                                               \
		/* saturate over-/underflows */                                \
		out.bits += (((out.bits == 0) & (in.bits != 0)) -              \
		             ((out.value == TAKUM##TO##_NAR) &                 \
		              (in.value != TAKUM##FROM##_NAR))) *              \
		            (1 - 2 * (in.value < 0));                          \
                                                                               \
		return out.value;                                              \
	} while (0);

/* Conversion from takum8 */
static inline takum16
takum16_from_takum8(takum8 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(8, 16);
}

static inline takum32
takum32_from_takum8(takum8 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(8, 32);
}

static inline takum64
takum64_from_takum8(takum8 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(8, 64);
}

takum_linear8 takum_linear8_from_takum8(takum8);
takum_linear16 takum_linear16_from_takum8(takum8);
takum_linear32 takum_linear32_from_takum8(takum8);
takum_linear64 takum_linear64_from_takum8(takum8);

/* Conversion from takum16 */
static inline takum8
takum8_from_takum16(takum16 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(16, 8);
}

static inline takum32
takum32_from_takum16(takum16 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(16, 32);
}

static inline takum64
takum64_from_takum16(takum16 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(16, 64);
}

takum_linear8 takum_linear8_from_takum16(takum16);
takum_linear16 takum_linear16_from_takum16(takum16);
takum_linear32 takum_linear32_from_takum16(takum16);
takum_linear64 takum_linear64_from_takum16(takum16);

/* Conversion from takum32 */
static inline takum8
takum8_from_takum32(takum32 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(32, 8);
}

static inline takum16
takum16_from_takum32(takum32 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(32, 16);
}

static inline takum64
takum64_from_takum32(takum32 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(32, 64);
}

takum_linear8 takum_linear8_from_takum32(takum32);
takum_linear16 takum_linear16_from_takum32(takum32);
takum_linear32 takum_linear32_from_takum32(takum32);
takum_linear64 takum_linear64_from_takum32(takum32);

/* Conversion from takum64 */
static inline takum8
takum8_from_takum64(takum64 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(64, 8);
}

static inline takum16
takum16_from_takum64(takum64 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(64, 16);
}

static inline takum32
takum32_from_takum64(takum64 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(64, 32);
}

takum_linear8 takum_linear8_from_takum64(takum64);
takum_linear16 takum_linear16_from_takum64(takum64);
takum_linear32 takum_linear32_from_takum64(takum64);
takum_linear64 takum_linear64_from_takum64(takum64);

/* Conversion from takum_linear8 */
takum8 takum8_from_takum_linear8(takum_linear8 t);
takum16 takum16_from_takum_linear8(takum_linear8 t);
takum32 takum32_from_takum_linear8(takum_linear8 t);
takum64 takum64_from_takum_linear8(takum_linear8 t);

static inline takum_linear16
takum_linear16_from_takum_linear8(takum_linear8 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(8, 16);
}

static inline takum_linear32
takum_linear32_from_takum_linear8(takum_linear8 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(8, 32);
}

static inline takum_linear64
takum_linear64_from_takum_linear8(takum_linear8 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(8, 64);
}

/* Conversion from takum_linear16 */
takum8 takum8_from_takum_linear16(takum_linear16 t);
takum16 takum16_from_takum_linear16(takum_linear16 t);
takum32 takum32_from_takum_linear16(takum_linear16 t);
takum64 takum64_from_takum_linear16(takum_linear16 t);

static inline takum_linear8
takum_linear8_from_takum_linear16(takum_linear16 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(16, 8);
}

static inline takum_linear32
takum_linear32_from_takum_linear16(takum_linear16 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(16, 32);
}

static inline takum_linear64
takum_linear64_from_takum_linear16(takum_linear16 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(16, 64);
}

/* Conversion from takum_linear32 */
takum8 takum8_from_takum_linear32(takum_linear32 t);
takum16 takum16_from_takum_linear32(takum_linear32 t);
takum32 takum32_from_takum_linear32(takum_linear32 t);
takum64 takum64_from_takum_linear32(takum_linear32 t);

static inline takum_linear8
takum_linear8_from_takum_linear32(takum_linear32 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(32, 8);
}

static inline takum_linear16
takum_linear16_from_takum_linear32(takum_linear32 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(32, 16);
}

static inline takum_linear64
takum_linear64_from_takum_linear32(takum_linear32 t)
{
	TAKUM_INTERNAL_CONVERT_EXPAND(32, 64);
}

/* Conversion from takum_linear64 */
takum8 takum8_from_takum_linear64(takum_linear64 t);
takum16 takum16_from_takum_linear64(takum_linear64 t);
takum32 takum32_from_takum_linear64(takum_linear64 t);
takum64 takum64_from_takum_linear64(takum_linear64 t);

static inline takum_linear8
takum_linear8_from_takum_linear64(takum_linear64 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(64, 8);
}

static inline takum_linear16
takum_linear16_from_takum_linear64(takum_linear64 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(64, 16);
}

static inline takum_linear32
takum_linear32_from_takum_linear64(takum_linear64 t)
{
	TAKUM_INTERNAL_CONVERT_REDUCE(64, 32);
}

/* Hypotenuse sqrt(a^2+b^2) */
takum8 takum8_hypotenuse(takum8, takum8);
takum16 takum16_hypotenuse(takum16, takum16);
takum32 takum32_hypotenuse(takum32, takum32);
takum64 takum64_hypotenuse(takum64, takum64);

takum_linear8 takum_linear8_hypotenuse(takum_linear8, takum_linear8);
takum_linear16 takum_linear16_hypotenuse(takum_linear16, takum_linear16);
takum_linear32 takum_linear32_hypotenuse(takum_linear32, takum_linear32);
takum_linear64 takum_linear64_hypotenuse(takum_linear64, takum_linear64);

/* Integer Power */
takum8 takum8_integer_power(takum8, int64_t);
takum16 takum16_integer_power(takum16, int64_t);
takum32 takum32_integer_power(takum32, int64_t);
takum64 takum64_integer_power(takum64, int64_t);

takum_linear8 takum_linear8_integer_power(takum_linear8, int64_t);
takum_linear16 takum_linear16_integer_power(takum_linear16, int64_t);
takum_linear32 takum_linear32_integer_power(takum_linear32, int64_t);
takum_linear64 takum_linear64_integer_power(takum_linear64, int64_t);

/* Integer Root */
takum8 takum8_root(takum8, int64_t);
takum16 takum16_root(takum16, int64_t);
takum32 takum32_root(takum32, int64_t);
takum64 takum64_root(takum64, int64_t);

takum_linear8 takum_linear8_root(takum_linear8, int64_t);
takum_linear16 takum_linear16_root(takum_linear16, int64_t);
takum_linear32 takum_linear32_root(takum_linear32, int64_t);
takum_linear64 takum_linear64_root(takum_linear64, int64_t);

/* Inversion */
static inline takum8
takum8_inversion(takum8 t)
{
	union takum_internal_takum8_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT8_C(0x7f)) + 1;

	return (t == TAKUM8_NAR) ? TAKUM8_NAR : out.value;
}

static inline takum16
takum16_inversion(takum16 t)
{
	union takum_internal_takum16_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT16_C(0x7fff)) + 1;

	return (t == TAKUM16_NAR) ? TAKUM16_NAR : out.value;
}

static inline takum32
takum32_inversion(takum32 t)
{
	union takum_internal_takum32_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT32_C(0x7fffffff)) + 1;

	return (t == TAKUM32_NAR) ? TAKUM32_NAR : out.value;
}

static inline takum64
takum64_inversion(takum64 t)
{
	union takum_internal_takum64_union out = {
		.value = t,
	};

	out.bits = (out.bits ^ UINT64_C(0x7fffffffffffffff)) + 1;

	return (t == TAKUM64_NAR) ? TAKUM64_NAR : out.value;
}

takum_linear8 takum_linear8_inversion(takum_linear8);
takum_linear16 takum_linear16_inversion(takum_linear16);
takum_linear32 takum_linear32_inversion(takum_linear32);
takum_linear64 takum_linear64_inversion(takum_linear64);

/* Binary Logarithm (following ISO 80000) */
takum8 takum8_lb(takum8);
takum16 takum16_lb(takum16);
takum32 takum32_lb(takum32);
takum64 takum64_lb(takum64);

takum_linear8 takum_linear8_lb(takum_linear8);
takum_linear16 takum_linear16_lb(takum_linear16);
takum_linear32 takum_linear32_lb(takum_linear32);
takum_linear64 takum_linear64_lb(takum_linear64);

/* Binary Logarithm 1 Plus (following ISO 80000) */
takum8 takum8_lb_1_plus(takum8);
takum16 takum16_lb_1_plus(takum16);
takum32 takum32_lb_1_plus(takum32);
takum64 takum64_lb_1_plus(takum64);

takum_linear8 takum_linear8_lb_1_plus(takum_linear8);
takum_linear16 takum_linear16_lb_1_plus(takum_linear16);
takum_linear32 takum_linear32_lb_1_plus(takum_linear32);
takum_linear64 takum_linear64_lb_1_plus(takum_linear64);

/* Decadic Logarithm (following ISO 80000) */
takum8 takum8_lg(takum8);
takum16 takum16_lg(takum16);
takum32 takum32_lg(takum32);
takum64 takum64_lg(takum64);

takum_linear8 takum_linear8_lg(takum_linear8);
takum_linear16 takum_linear16_lg(takum_linear16);
takum_linear32 takum_linear32_lg(takum_linear32);
takum_linear64 takum_linear64_lg(takum_linear64);

/* Decadic Logarithm 1 Plus (following ISO 80000) */
takum8 takum8_lg_1_plus(takum8);
takum16 takum16_lg_1_plus(takum16);
takum32 takum32_lg_1_plus(takum32);
takum64 takum64_lg_1_plus(takum64);

takum_linear8 takum_linear8_lg_1_plus(takum_linear8);
takum_linear16 takum_linear16_lg_1_plus(takum_linear16);
takum_linear32 takum_linear32_lg_1_plus(takum_linear32);
takum_linear64 takum_linear64_lg_1_plus(takum_linear64);

/* Natural Logarithm (following ISO 80000) */
takum8 takum8_ln(takum8);
takum16 takum16_ln(takum16);
takum32 takum32_ln(takum32);
takum64 takum64_ln(takum64);

takum_linear8 takum_linear8_ln(takum_linear8);
takum_linear16 takum_linear16_ln(takum_linear16);
takum_linear32 takum_linear32_ln(takum_linear32);
takum_linear64 takum_linear64_ln(takum_linear64);

/* Natural Logarithm 1 Plus (following ISO 80000) */
takum8 takum8_ln_1_plus(takum8);
takum16 takum16_ln_1_plus(takum16);
takum32 takum32_ln_1_plus(takum32);
takum64 takum64_ln_1_plus(takum64);

takum_linear8 takum_linear8_ln_1_plus(takum_linear8);
takum_linear16 takum_linear16_ln_1_plus(takum_linear16);
takum_linear32 takum_linear32_ln_1_plus(takum_linear32);
takum_linear64 takum_linear64_ln_1_plus(takum_linear64);

/* Multiplication */
takum8 takum8_multiplication(takum8, takum8);
takum16 takum16_multiplication(takum16, takum16);
takum32 takum32_multiplication(takum32, takum32);
takum64 takum64_multiplication(takum64, takum64);

takum_linear8 takum_linear8_multiplication(takum_linear8, takum_linear8);
takum_linear16 takum_linear16_multiplication(takum_linear16, takum_linear16);
takum_linear32 takum_linear32_multiplication(takum_linear32, takum_linear32);
takum_linear64 takum_linear64_multiplication(takum_linear64, takum_linear64);

/* Power */
takum8 takum8_power(takum8, takum8);
takum16 takum16_power(takum16, takum16);
takum32 takum32_power(takum32, takum32);
takum64 takum64_power(takum64, takum64);

takum_linear8 takum_linear8_power(takum_linear8, takum_linear8);
takum_linear16 takum_linear16_power(takum_linear16, takum_linear16);
takum_linear32 takum_linear32_power(takum_linear32, takum_linear32);
takum_linear64 takum_linear64_power(takum_linear64, takum_linear64);

/* Precision */
uint8_t takum8_precision(takum8);
uint8_t takum16_precision(takum16);
uint8_t takum32_precision(takum32);
uint8_t takum64_precision(takum64);

uint8_t takum_linear8_precision(takum_linear8);
uint8_t takum_linear16_precision(takum_linear16);
uint8_t takum_linear32_precision(takum_linear32);
uint8_t takum_linear64_precision(takum_linear64);

/* Secant */
takum8 takum8_sec(takum8);
takum16 takum16_sec(takum16);
takum32 takum32_sec(takum32);
takum64 takum64_sec(takum64);

takum_linear8 takum_linear8_sec(takum_linear8);
takum_linear16 takum_linear16_sec(takum_linear16);
takum_linear32 takum_linear32_sec(takum_linear32);
takum_linear64 takum_linear64_sec(takum_linear64);

/* Secant π Times */
takum8 takum8_sec_pi_times(takum8);
takum16 takum16_sec_pi_times(takum16);
takum32 takum32_sec_pi_times(takum32);
takum64 takum64_sec_pi_times(takum64);

takum_linear8 takum_linear8_sec_pi_times(takum_linear8);
takum_linear16 takum_linear16_sec_pi_times(takum_linear16);
takum_linear32 takum_linear32_sec_pi_times(takum_linear32);
takum_linear64 takum_linear64_sec_pi_times(takum_linear64);

/* Hyperbolic Secant */
takum8 takum8_sech(takum8);
takum16 takum16_sech(takum16);
takum32 takum32_sech(takum32);
takum64 takum64_sech(takum64);

takum_linear8 takum_linear8_sech(takum_linear8);
takum_linear16 takum_linear16_sech(takum_linear16);
takum_linear32 takum_linear32_sech(takum_linear32);
takum_linear64 takum_linear64_sech(takum_linear64);

/* Sign */
static inline takum8
takum8_sign(takum8 t)
{
	if (t == TAKUM8_NAR) {
		return TAKUM8_NAR;
	} else {
		return (t != 0) *
		       ((t < 0) * UINT8_C(0xc0) + (t >= 0) * UINT8_C(0x40));
	}
}

static inline takum16
takum16_sign(takum16 t)
{
	if (t == TAKUM16_NAR) {
		return TAKUM16_NAR;
	} else {
		return (t != 0) * ((t < 0) * UINT16_C(0xc000) +
		                   (t >= 0) * UINT16_C(0x4000));
	}
}

static inline takum32
takum32_sign(takum32 t)
{
	if (t == TAKUM32_NAR) {
		return TAKUM32_NAR;
	} else {
		return (t != 0) * ((t < 0) * UINT32_C(0xc0000000) +
		                   (t >= 0) * UINT32_C(0x40000000));
	}
}

static inline takum64
takum64_sign(takum64 t)
{
	if (t == TAKUM64_NAR) {
		return TAKUM64_NAR;
	} else {
		return (t != 0) * ((t < 0) * UINT64_C(0xc000000000000000) +
		                   (t >= 0) * UINT64_C(0x4000000000000000));
	}
}

static inline takum_linear8
takum_linear8_sign(takum_linear8 t)
{
	if (t == TAKUM_LINEAR8_NAR) {
		return TAKUM_LINEAR8_NAR;
	} else {
		return (t != 0) *
		       ((t < 0) * UINT8_C(0xc0) + (t >= 0) * UINT8_C(0x40));
	}
}

static inline takum_linear16
takum_linear16_sign(takum_linear16 t)
{
	if (t == TAKUM_LINEAR16_NAR) {
		return TAKUM_LINEAR16_NAR;
	} else {
		return (t != 0) * ((t < 0) * UINT16_C(0xc000) +
		                   (t >= 0) * UINT16_C(0x4000));
	}
}

static inline takum_linear32
takum_linear32_sign(takum_linear32 t)
{
	if (t == TAKUM_LINEAR32_NAR) {
		return TAKUM_LINEAR32_NAR;
	} else {
		return (t != 0) * ((t < 0) * UINT32_C(0xc0000000) +
		                   (t >= 0) * UINT32_C(0x40000000));
	}
}

static inline takum_linear64
takum_linear64_sign(takum_linear64 t)
{
	if (t == TAKUM_LINEAR64_NAR) {
		return TAKUM_LINEAR64_NAR;
	} else {
		return (t != 0) * ((t < 0) * UINT64_C(0xc000000000000000) +
		                   (t >= 0) * UINT64_C(0x4000000000000000));
	}
}

/* Sine */
takum8 takum8_sin(takum8);
takum16 takum16_sin(takum16);
takum32 takum32_sin(takum32);
takum64 takum64_sin(takum64);

takum_linear8 takum_linear8_sin(takum_linear8);
takum_linear16 takum_linear16_sin(takum_linear16);
takum_linear32 takum_linear32_sin(takum_linear32);
takum_linear64 takum_linear64_sin(takum_linear64);

/* Sine π Times */
takum8 takum8_sin_pi_times(takum8);
takum16 takum16_sin_pi_times(takum16);
takum32 takum32_sin_pi_times(takum32);
takum64 takum64_sin_pi_times(takum64);

takum_linear8 takum_linear8_sin_pi_times(takum_linear8);
takum_linear16 takum_linear16_sin_pi_times(takum_linear16);
takum_linear32 takum_linear32_sin_pi_times(takum_linear32);
takum_linear64 takum_linear64_sin_pi_times(takum_linear64);

/* Hyperbolic Sine */
takum8 takum8_sinh(takum8);
takum16 takum16_sinh(takum16);
takum32 takum32_sinh(takum32);
takum64 takum64_sinh(takum64);

takum_linear8 takum_linear8_sinh(takum_linear8);
takum_linear16 takum_linear16_sinh(takum_linear16);
takum_linear32 takum_linear32_sinh(takum_linear32);
takum_linear64 takum_linear64_sinh(takum_linear64);

/* Square Root */
takum8 takum8_square_root(takum8);
takum16 takum16_square_root(takum16);
takum32 takum32_square_root(takum32);
takum64 takum64_square_root(takum64);

takum_linear8 takum_linear8_square_root(takum_linear8);
takum_linear16 takum_linear16_square_root(takum_linear16);
takum_linear32 takum_linear32_square_root(takum_linear32);
takum_linear64 takum_linear64_square_root(takum_linear64);

/* Subtraction */
takum8 takum8_subtraction(takum8, takum8);
takum16 takum16_subtraction(takum16, takum16);
takum32 takum32_subtraction(takum32, takum32);
takum64 takum64_subtraction(takum64, takum64);

takum_linear8 takum_linear8_subtraction(takum_linear8, takum_linear8);
takum_linear16 takum_linear16_subtraction(takum_linear16, takum_linear16);
takum_linear32 takum_linear32_subtraction(takum_linear32, takum_linear32);
takum_linear64 takum_linear64_subtraction(takum_linear64, takum_linear64);

/* Tangent */
takum8 takum8_tan(takum8);
takum16 takum16_tan(takum16);
takum32 takum32_tan(takum32);
takum64 takum64_tan(takum64);

takum_linear8 takum_linear8_tan(takum_linear8);
takum_linear16 takum_linear16_tan(takum_linear16);
takum_linear32 takum_linear32_tan(takum_linear32);
takum_linear64 takum_linear64_tan(takum_linear64);

/* Tangent π Times */
takum8 takum8_tan_pi_times(takum8);
takum16 takum16_tan_pi_times(takum16);
takum32 takum32_tan_pi_times(takum32);
takum64 takum64_tan_pi_times(takum64);

takum_linear8 takum_linear8_tan_pi_times(takum_linear8);
takum_linear16 takum_linear16_tan_pi_times(takum_linear16);
takum_linear32 takum_linear32_tan_pi_times(takum_linear32);
takum_linear64 takum_linear64_tan_pi_times(takum_linear64);

/* Hyperbolic Tangent */
takum8 takum8_tanh(takum8);
takum16 takum16_tanh(takum16);
takum32 takum32_tanh(takum32);
takum64 takum64_tanh(takum64);

takum_linear8 takum_linear8_tanh(takum_linear8);
takum_linear16 takum_linear16_tanh(takum_linear16);
takum_linear32 takum_linear32_tanh(takum_linear32);
takum_linear64 takum_linear64_tanh(takum_linear64);

/* Conversion to extended float */
long double takum8_to_extended_float(takum8);
long double takum16_to_extended_float(takum16);
long double takum32_to_extended_float(takum32);
long double takum64_to_extended_float(takum64);

long double takum_linear8_to_extended_float(takum_linear8);
long double takum_linear16_to_extended_float(takum_linear16);
long double takum_linear32_to_extended_float(takum_linear32);
long double takum_linear64_to_extended_float(takum_linear64);

/* Conversion to float32 */
float takum8_to_float32(takum8);
float takum16_to_float32(takum16);
float takum32_to_float32(takum32);
float takum64_to_float32(takum64);

float takum_linear8_to_float32(takum_linear8);
float takum_linear16_to_float32(takum_linear16);
float takum_linear32_to_float32(takum_linear32);
float takum_linear64_to_float32(takum_linear64);

/* Conversion to float64 */
double takum8_to_float64(takum8);
double takum16_to_float64(takum16);
double takum32_to_float64(takum32);
double takum64_to_float64(takum64);

double takum_linear8_to_float64(takum_linear8);
double takum_linear16_to_float64(takum_linear16);
double takum_linear32_to_float64(takum_linear32);
double takum_linear64_to_float64(takum_linear64);

#endif /* TAKUM_H */
