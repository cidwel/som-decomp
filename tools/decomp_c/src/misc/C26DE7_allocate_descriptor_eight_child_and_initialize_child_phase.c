#include "som_c.h"

/* C26DE7 allocate_descriptor_eight_child_and_initialize_child_phase   [class A, 20 bytes, 8 instructions]
 * Source: src/rom/allocate_descriptor_eight_child_and_initialize_child_phase.s
 * Documented in docs/boss-descriptor-eight.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void allocate_descriptor_eight_child_and_initialize_child_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0295, x);
    r->x = 0x6F9C;
    r->y = 0x2909;
    JSR(c, 0x6DF1, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    uint16_t value = RAM16(0x0295);
    RAM16_SET(0x00B0 + x_ret, value);
    RAM16_SET(0x007E + x_ret, 0);
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26DE7, SOM_RTS, "gen", allocate_descriptor_eight_child_and_initialize_child_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 20, 8)
