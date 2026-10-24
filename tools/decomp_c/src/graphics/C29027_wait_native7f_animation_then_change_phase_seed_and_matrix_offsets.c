#include "som_c.h"

/* C29027 wait_native7f_animation_then_change_phase_seed_and_matrix_offsets   [class A, 39 bytes, 15 instructions]
 * Source: src/rom/wait_native7f_animation_then_change_phase_seed_and_matrix_offsets.s
 * Documented in docs/boss-native7f-entrance-chain.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void wait_native7f_animation_then_change_phase_seed_and_matrix_offsets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x009E + battle_defence_work);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value != 0) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
        zero1 = value == 0;
        negative1 = value & 0x8000;
    } else {
        RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
        RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
        RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
        r->a = 0x0112;
        r->x = battle_defence_work;
        { const uint16_t sp_call = r->sp; JSR(c, 0x903C, 0xC21394); GUARD_JSR(c, sp_call, 0x903C); } /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(0x02D5, 0x0C);
        RAM16_SET(0x02D7, 6);
        a1 = 6;
        a_hi1 = 0;
        zero1 = 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x904B, 0xC2979F); GUARD_JSR(c, sp_call, 0x904B); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29027, SOM_RTS, "gen", wait_native7f_animation_then_change_phase_seed_and_matrix_offsets, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 39, 15)
