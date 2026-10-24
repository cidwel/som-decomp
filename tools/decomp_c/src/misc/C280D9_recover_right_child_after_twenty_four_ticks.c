#include "som_c.h"

/* C280D9 recover_right_child_after_twenty_four_ticks   [class B, 45 bytes, 20 instructions]
 * Source: src/rom/recover_right_child_after_twenty_four_ticks.s
 * Documented in docs/boss-native58-right-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void recover_right_child_after_twenty_four_ticks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(OBJECT_AGE + battle_defence_work);
    if (value < 0x18) {
        r->a = value;
        r->x = battle_defence_work;
        r->c = 0;
        r->z = value == 0x18;
        r->n = (uint16_t)(value - 0x18) & 0x8000;
        RETURN_RTS(c);
    }
    if (RAM16(0x0190 + battle_defence_work) & 0x8000) {
        RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
        r->a = 0;
        r->x = battle_defence_work;
        r->c = value >= 0x18;
        { const uint16_t sp_call = r->sp; JSR(c, 0x80FE, 0xC21394); GUARD_JSR(c, sp_call, 0x80FE); } /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) - 1));
    r->a = 0x0118;
    r->x = battle_defence_work;
    r->c = value >= 0x18;
    { const uint16_t sp_call = r->sp; JSR(c, 0x80F0, 0xC21394); GUARD_JSR(c, sp_call, 0x80F0); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC280D9, SOM_RTS, "gen", recover_right_child_after_twenty_four_ticks, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 45, 20)
