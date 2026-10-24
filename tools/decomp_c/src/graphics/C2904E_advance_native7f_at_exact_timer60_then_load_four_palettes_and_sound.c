#include "som_c.h"
#include "som_hand_d.h"

/* C2904E advance_native7f_at_exact_timer60_then_load_four_palettes_and_sound   [class B, 94 bytes, 34 instructions]
 * Source: src/rom/advance_native7f_at_exact_timer60_then_load_four_palettes_and_sound.s
 * Documented in docs/boss-native7f-entrance-chain.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_native7f_at_exact_timer60_then_load_four_palettes_and_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
L_C2904E:;
    LDX(c, DP, 0x87);
    LDA(c, ABX, 0x96);
    a_cmp(r, 0x3c);
    if (!r->z) goto L_C290A7;
    STZ(c, ABX, 0x96);
    INC(c, ABX, 0x94);
    STZ(c, ABX, 0x96);
    a_lda(r, 0x300);
    STA(c, ABX, 0xb0);
    a_lda(r, 0x116);
    JSR(c, 0x906c, 0xC21394);
    REQUIRE_M16(c);
    a_lda(r, 0x18);
    STA(c, ABS, 0x2d5);
    REQUIRE_M16(c);
    a_lda(r, 0x18);
    STA(c, ABS, 0x2d7);
    REQUIRE_M16(c);
    a_lda(r, 0x62);
    REQUIRE_X16(c);
    a_ldx(r, 0x4);
    JSR(c, 0x9081, 0xC22700);
    REQUIRE_M16(c);
    a_lda(r, 0x63);
    REQUIRE_X16(c);
    a_ldx(r, 0x5);
    JSR(c, 0x908a, 0xC22700);
    REQUIRE_M16(c);
    a_lda(r, 0x64);
    REQUIRE_X16(c);
    a_ldx(r, 0x6);
    JSR(c, 0x9093, 0xC22700);
    REQUIRE_M16(c);
    a_lda(r, 0x65);
    REQUIRE_X16(c);
    a_ldx(r, 0x7);
    JSR(c, 0x909c, 0xC22700);
    LDX(c, DP, 0x87);
    REQUIRE_M16(c);
    a_lda(r, 0xd6);
    JSR(c, 0x90a4, 0xC230E3);
    LDX(c, DP, 0x87);
L_C290A7:;
    JSR(c, 0x90a9, 0xC2979F);
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2904E, SOM_RTS, "hand", advance_native7f_at_exact_timer60_then_load_four_palettes_and_sound, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 94, 34)
