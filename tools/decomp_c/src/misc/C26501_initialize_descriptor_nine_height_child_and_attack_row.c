#include "som_c.h"

/* C26501 initialize_descriptor_nine_height_child_and_attack_row   [class A, 31 bytes, 11 instructions]
 * Source: src/rom/initialize_descriptor_nine_height_child_and_attack_row.s
 * Documented in docs/boss-descriptor-nine.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_nine_height_child_and_attack_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0066 + x, 0x3F);
    r->a = 0x3F;
    r->x = 0x6610;
    r->y = 0xB901;
    JSR(c, 0x650F, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    RAM16_SET(0x00B0 + x_ret, RAM16(0x0287));
    RAM16_SET(0x007E + x_ret, 0);
    r->a = 0x64;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    JSL(c, 0x651E, 0xC0006C); /* boss_attack_row_public_jump */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26501, SOM_RTS, "gen", initialize_descriptor_nine_height_child_and_attack_row, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 31, 11)
