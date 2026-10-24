#include "som_c.h"

/* C25150 initialize_descriptor_fourteen_attack_row_and_two_children   [class B, 67 bytes, 24 instructions]
 * Source: src/rom/initialize_descriptor_fourteen_attack_row_and_two_children.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_fourteen_attack_row_and_two_children(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5152, 0xC20CE0); GUARD_JSR(c, sp_call, 0x5152); } /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x00A5 + x, 0x2A);
    RAM16_SET(0x001E + x, 0x11);
    r->a = 0x5F;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5165, 0xC0006C); GUARD_JSL(c, sp_call, 0x5165); } /* boss_attack_row_public_jump */
    if (r->xf != 0) { c->fail = 3; return; }
    RAM16_SET(0x0295, RAM16(0x0287));
    r->x = 0x5354;
    r->y = 0x3801;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5172, 0xC20D53); GUARD_JSR(c, sp_call, 0x5172); } /* allocate_boss_object_pool_slot */
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x00B0 + x_ret2, RAM16(0x0295));
    RAM16_SET(0x00B2 + x_ret2, 0);
    r->a = 0;
    r->x = 0x5354;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5186, 0xC20D53); GUARD_JSR(c, sp_call, 0x5186); } /* allocate_boss_object_pool_slot */
    uint16_t x_ret3 = r->x;
    RAM16_SET(0x00B0 + x_ret3, RAM16(0x0295));
    RAM16_SET(0x00B2 + x_ret3, 1);
    r->a = 1;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25150, SOM_RTS, "gen", initialize_descriptor_fourteen_attack_row_and_two_children, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 67, 24)
