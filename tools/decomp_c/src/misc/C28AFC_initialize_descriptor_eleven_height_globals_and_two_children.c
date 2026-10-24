#include "som_c.h"

/* C28AFC initialize_descriptor_eleven_height_globals_and_two_children   [class B, 53 bytes, 19 instructions]
 * Source: src/rom/initialize_descriptor_eleven_height_globals_and_two_children.s
 * Documented in docs/boss-descriptor-eleven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_eleven_height_globals_and_two_children(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0066 + x, 0x60);
    RAM16_SET(0x035A, 0x60);
    RAM16_SET(0x0358, 0);
    RAM16_SET(0x035C, 0);
    RAM16_SET(0x007E + x, 0);
    RAM16_SET(0x00A5 + x, 0x20);
    r->a = 0x20;
    r->x = 0x8DCA;
    r->y = 0x3901;
    JSR(c, 0x8B1C, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x00B0 + x_ret, value);
    r->a = value;
    r->x = 0x8E38;
    r->y = 0x2909;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8B2A, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret2 = r->x;
    uint16_t value2 = RAM16(0x0287);
    RAM16_SET(0x00B0 + x_ret2, value2);
    r->a = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28AFC, SOM_RTS, "gen", initialize_descriptor_eleven_height_globals_and_two_children, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 53, 19)
