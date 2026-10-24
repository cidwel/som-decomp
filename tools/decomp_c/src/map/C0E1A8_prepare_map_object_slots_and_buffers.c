#include "som_c.h"
#include "som_hand_d.h"

/* C0E1A8 prepare_map_object_slots_and_buffers   [class B, 256 bytes, 96 instructions]
 * Source: src/rom/prepare_map_object_slots_and_buffers.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: ABXYCV.
 */
static void prepare_map_object_slots_and_buffers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
L_C0E1A8:;
    i_rep(r, 0x30);
    LDA(c, ABS, 0xe802);
    STA(c, DP, 0xd);
    a_lda(r, 0x0);
    a_ldx(r, 0x11fe);
L_C0E1B5:;
    STA(c, ABX, 0xe600);
    STA(c, ABX, 0xe600);
    i_dex(r);
    i_dex(r);
    if (!r->n) goto L_C0E1B5;
    a_ldx(r, 0xfe);
L_C0E1C2:;
    STA(c, ABX, 0xc800);
    STA(c, ABX, 0xc900);
    STA(c, ABX, 0xca00);
    i_dex(r);
    i_dex(r);
    if (!r->n) goto L_C0E1C2;
    a_ldx(r, 0x3e);
L_C0E1D2:;
    STA(c, ABX, 0xcb00);
    i_dex(r);
    i_dex(r);
    if (!r->n) goto L_C0E1D2;
    i_sep(r, 0x20);
    BIT(c, DP, 0xed);
    i_rep(r, 0x20);
    if (!r->n) goto L_C0E238;
    a_lda(r, 0xe60);
    STA(c, ABS, 0xe66e);
    a_lda(r, 0xec0);
    STA(c, ABS, 0xe86e);
    a_lda(r, 0xf20);
    STA(c, ABS, 0xea6e);
    a_lda(r, 0xd60);
    STA(c, ABS, 0xe66c);
    a_lda(r, 0xdb0);
    STA(c, ABS, 0xe86c);
    a_lda(r, 0xe00);
    STA(c, ABS, 0xea6c);
    a_lda(r, 0xa40);
    EOR(c, DP, 0x98);
    STA(c, ABS, 0xe68a);
    a_lda(r, 0x8c8);
    EOR(c, DP, 0x98);
    STA(c, ABS, 0xe686);
    a_lda(r, 0xc68);
    EOR(c, DP, 0x98);
    STA(c, ABS, 0xe88a);
    a_lda(r, 0x8ec);
    EOR(c, DP, 0x98);
    STA(c, ABS, 0xe886);
    a_lda(r, 0xea0);
    EOR(c, DP, 0x98);
    STA(c, ABS, 0xea8a);
    a_lda(r, 0x920);
    EOR(c, DP, 0x98);
    STA(c, ABS, 0xea86);
    TAIL_CALL(c, 0xC0E2A8, SOM_RTS);
L_C0E238:;
    a_lda(r, 0xe60);
    STA(c, ABS, 0xe66e);
    a_lda(r, 0xe80);
    STA(c, ABS, 0xe86e);
    a_lda(r, 0xea0);
    STA(c, ABS, 0xea6e);
    a_lda(r, 0xec0);
    STA(c, ABS, 0xec6e);
    a_lda(r, 0xee0);
    STA(c, ABS, 0xee6e);
    a_lda(r, 0xf00);
    STA(c, ABS, 0xf06e);
    a_lda(r, 0xf20);
    STA(c, ABS, 0xf26e);
    a_lda(r, 0xf40);
    STA(c, ABS, 0xf46e);
    a_lda(r, 0xf60);
    STA(c, ABS, 0xf66e);
    a_lda(r, 0x840);
    EOR(c, DP, 0x98);
    STA(c, ABS, 0xe68a);
    r->c = 0;
    a_adc(r, 0x8);
    STA(c, ABS, 0xe88a);
    a_adc(r, 0x18);
    STA(c, ABS, 0xea8a);
    a_adc(r, 0x8);
    STA(c, ABS, 0xec8a);
    a_adc(r, 0x18);
    STA(c, ABS, 0xee8a);
    a_adc(r, 0x8);
    STA(c, ABS, 0xf08a);
    a_adc(r, 0x18);
    STA(c, ABS, 0xf28a);
    a_adc(r, 0x8);
    STA(c, ABS, 0xf48a);
    a_adc(r, 0x18);
    STA(c, ABS, 0xf68a);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0E1A8, SOM_RTS, "hand", prepare_map_object_slots_and_buffers, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 256, 96)
