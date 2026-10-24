#include "som_c.h"

/* C28FB3 expand_native7f_scale_then_seed_animation_and_matrix_offsets   [class B, 58 bytes, 22 instructions]
 * Source: src/rom/expand_native7f_scale_then_seed_animation_and_matrix_offsets.s
 * Documented in docs/boss-native7f-entrance-chain.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void expand_native7f_scale_then_seed_animation_and_matrix_offsets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x00B0 + battle_defence_work);
    RAM16_SET(0x00B0 + battle_defence_work, (uint16_t)(value + 0x20));
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if ((uint16_t)(value + 0x20) < 0x0800) {
        a1 = (uint8_t)(value + 0x20);
        a_hi1 = (uint16_t)(value + 0x20) >> 8;
        zero1 = (uint16_t)(value + 0x20) == 0x0800;
        negative1 = (uint16_t)((uint16_t)(value + 0x20) - 0x0800) & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
        RAM16_SET(0x0000 + battle_defence_work, 0);
        RAM16_SET(OBJECT_AGE + battle_defence_work, 0);
        RAM16_SET(0x0090 + battle_defence_work, 0);
        RAM16_SET(0x00B0 + battle_defence_work, 0x0200);
        r->a = 0x0111;
        r->x = battle_defence_work;
        r->c = (uint16_t)(value + 0x20) >= 0x0800;
        r->v = ((value ^ (uint16_t)(value + 0x20)) & ((uint16_t)(value + 0x20) ^ 0x20) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8FDB, 0xC21394); GUARD_JSR(c, sp_call, 0x8FDB); } /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(0x02D5, 0x0E);
        RAM16_SET(0x02D7, 0x0A);
        a1 = 0x0A;
        a_hi1 = 0;
        zero1 = 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = (uint16_t)(value + 0x20) >= 0x0800;
    r->v = ((value ^ (uint16_t)(value + 0x20)) & ((uint16_t)(value + 0x20) ^ 0x20) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8FEA, 0xC2979F); GUARD_JSR(c, sp_call, 0x8FEA); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    r->c = 0;
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28FB3, SOM_RTS, "gen", expand_native7f_scale_then_seed_animation_and_matrix_offsets, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 58, 22)
