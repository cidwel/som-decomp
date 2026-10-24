#include "som_c.h"
#include "som_hand_d.h"

/* C252B7 place_boss_target_at_boss_and_set_control_if_idle   [class B, 56 bytes, 22 instructions]
 * Source: src/rom/place_boss_target_at_boss_and_set_control_if_idle.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=any D=any (the callee C2620D is assembled for a 16-bit accumulator: with M=8 it decodes
 * `adc #$E000` as `adc #$00 / cpx`, so M=8 is not an executable contract).  Callers read: ABXYCZNV.
 */
#define ABSX(off) ((((uint32_t)r->db << 16) + (off) + r->x) & 0xFFFFFF)
#define ABSY(off) ((((uint32_t)r->db << 16) + (off) + r->y) & 0xFFFFFF)

static void place_boss_target_at_boss_and_set_control_if_idle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    REQUIRE_M16(c);
L_C252B7:;
    JSR(c, 0x52b9, 0xC2620D);
    LDA(c, ABX, 0x2b);
    STA(c, ABY, 0x2);
    LDA(c, ABX, 0x32);
    STA(c, ABY, 0x4);
    LDA(c, ABY, 0x190);
    if (!r->z) goto L_C252EE;
    i_sep(r, 0x20);
    LDA(c, ABY, 0x60);
    if (!r->z) goto L_C252EC;
    LDA(c, ABY, 0xe);
    if (!r->z) goto L_C252EC;
    LDA(c, ABY, 0x1e5);
    a_lda(r, 0x24);
    STA(c, ABY, 0x1e5);
    a_lda(r, 0x1);
    ORA(c, ABY, 0x190);
    STA(c, ABY, 0x190);
    a_lda(r, 0x20);
    STA(c, ABY, 0x1b4);
L_C252EC:;
    i_rep(r, 0x20);
L_C252EE:;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC252B7, SOM_RTS, "hand", place_boss_target_at_boss_and_set_control_if_idle, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 56, 22)
