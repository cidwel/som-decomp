#include "som_c.h"

/* C266A0 initialize_descriptor_thirteen_height_and_two_linked_children   [class B, 57 bytes, 21 instructions]
 * Source: src/rom/initialize_descriptor_thirteen_height_and_two_linked_children.s
 * Documented in docs/boss-descriptor-thirteen.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_thirteen_height_and_two_linked_children(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    JSR(c, 0x66A2, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x0066 + x, 0x80);
    RAM16_SET(0x007E + x, 0);
    RAM16_SET(0x0295, x);
    r->a = 0x80;
    r->x = 0x6A11;
    r->y = 0x3821;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x66B6, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    uint16_t value = RAM16(0x0295);
    RAM16_SET(0x00B0 + x_ret, value);
    RAM16_SET(0x00B2 + x_ret, 0);
    r->a = value;
    r->x = 0x6A11;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x66C7, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x00B0 + x_ret2, RAM16(0x0295));
    RAM16_SET(0x00B2 + x_ret2, 1);
    uint16_t value3 = RAM16(0x02C7);
    RAM16_SET(0x0362, value3);
    r->a = value3;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC266A0, SOM_RTS, "gen", initialize_descriptor_thirteen_height_and_two_linked_children, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 57, 21)
