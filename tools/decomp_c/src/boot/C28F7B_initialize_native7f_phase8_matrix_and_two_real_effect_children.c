#include "som_c.h"

/* C28F7B initialize_native7f_phase8_matrix_and_two_real_effect_children   [class D, 56 bytes, 21 instructions]
 * Source: src/rom/initialize_native7f_phase8_matrix_and_two_real_effect_children.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void initialize_native7f_phase8_matrix_and_two_real_effect_children(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    r->x = battle_defence_work;
    r->z = battle_defence_work == 0;
    r->n = battle_defence_work & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8F7F, 0xC20CE0); GUARD_JSR(c, sp_call, 0x8F7F); } /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x0000 + battle_defence_work, 1);
    RAM16_SET(OBJECT_PHASE + battle_defence_work, 8);
    RAM16_SET(0x000B + battle_defence_work, 2);
    BUS8_SET(c, 0x00211A, 0xC0);
    r->a = 0xC0;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8F9E, 0xC2979F); GUARD_JSR(c, sp_call, 0x8F9E); } /* derive_isotropic_native7f_mode7_matrix_from_scale_and_angle */
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x986D;
    r->y = 0x3921;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8FA7, 0xC20D53); GUARD_JSR(c, sp_call, 0x8FA7); } /* allocate_boss_object_pool_slot */
    r->x = 0x3D34;
    r->y = 0x2A20;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8FB0, 0xC20D53); GUARD_JSR(c, sp_call, 0x8FB0); } /* allocate_boss_object_pool_slot */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28F7B, SOM_RTS, "gen", initialize_native7f_phase8_matrix_and_two_real_effect_children, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 56, 21)
