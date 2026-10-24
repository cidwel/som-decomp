#include "som_c.h"
#include "som_hand_d.h"
/* SOM_PLAIN_CALLS: every memory access below goes through the live DB / D registers, so a callee that returns with another data
 * bank is followed exactly and needs no data-bank check. */
#undef JSR
#undef JSL
#define JSR(c, retpc, target) CALL_JSR((c), (retpc), (target))
#define JSL(c, retpc, target) CALL_JSL((c), (retpc), (target))

/* C002BD publish_dialogue_window_tile_row_and_advance_frame_phase   [class B, 139 bytes, 60 instructions]
 * Source: src/rom/publish_dialogue_window_tile_row_and_advance_frame_phase.s
 * Documented in docs/event-dialogue-window-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_dialogue_window_tile_row_and_advance_frame_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
L_C002BD:;
    LDA(c, ABS, 0xa16c);
    i_lsra(r);
    a_adc(r, 0x0);
    i_inca(r);
    STA(c, ABS, 0xa164);
    LDX(c, ABS, 0xa1a2);
    STX(c, ABS, 0xa1a0);
    a_ldx(r, 0x0);
    a_ldy(r, 0x0);
    LDA(c, ABS, 0xa162);
    a_cmp(r, 0x1);
    if (!r->z) goto L_C002E4;
    LDA(c, ABS, 0xa15c);
    a_cmp(r, 0x5);
    if (r->c) goto L_C002E4;
    JSR(c, 0x2e3, 0xC00435);
L_C002E4:;
    REQUIRE_M8(c);
    a_lda(r, 0x0);
    i_xba(r);
    LDA(c, ABS, 0xa15c);
    REQUIRE_M8(c);
    a_cmp(r, 0x1);
    if (r->z) goto L_C002F5;
    REQUIRE_M8(c);
    a_cmp(r, 0x5);
    if (r->z) goto L_C002F5;
    REQUIRE_M8(c);
    a_lda(r, 0x2);
    i_xba(r);
L_C002F5:;
    i_xba(r);
    TSB(c, ABS, 0xa186);
    REQUIRE_M8(c);
    a_lda(r, 0xff);
    STA(c, ABS, 0xa171);
    JSR(c, 0x300, 0xC00478);
    LDA(c, ABS, 0xa15c);
    REQUIRE_M8(c);
    a_cmp(r, 0x5);
    if (!r->c) goto L_C0030C;
    i_tyx(r);
    JSR(c, 0x30b, 0xC00435);
L_C0030C:;
    JSR(c, 0x30e, 0xC00D7F);
    i_rep(r, 0x20);
    a_lda(r, 0x180);
    STA(c, ABL, 0x1d18);
    LDA(c, ABS, 0xa15c);
    a_and(r, 0xff);
    i_deca(r);
    i_asla(r);
    i_tax(r);
    LDA(c, ALX, 0xc01102);
    STA(c, ABL, 0x1d06);
    i_sep(r, 0x20);
    a_lda(r, 0x7);
    JSR(c, 0x32f, 0xC00FFA);
    LDA(c, ABS, 0xa15c);
    REQUIRE_M8(c);
    a_cmp(r, 0x4);
    if (!r->z) goto L_C00344;
    LDX(c, ABS, 0xa1a0);
    i_dex(r);
    i_dex(r);
    STX(c, ABS, 0xa1a2);
    REQUIRE_M8(c);
    a_lda(r, 0x1);
    STA(c, ABS, 0xa186);
L_C00344:;
    INC(c, ABS, 0xa15c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC002BD, SOM_RTS, "hand", publish_dialogue_window_tile_row_and_advance_frame_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 139, 60)
