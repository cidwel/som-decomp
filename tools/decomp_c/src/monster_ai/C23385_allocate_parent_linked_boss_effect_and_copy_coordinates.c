#include "som_c.h"

/* C23385 allocate_parent_linked_boss_effect_and_copy_coordinates   [class B, 57 bytes, 23 instructions]
 * Source: src/rom/allocate_parent_linked_boss_effect_and_copy_coordinates.s
 * Documented in docs/boss-descriptor-zero-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void allocate_parent_linked_boss_effect_and_copy_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM16_SET(0x00A7 + x, a);
    RAM16_SET(0x001E + x, a);
    RAM16_SET(0x0295, a);
    RAM16_SET(0x0297, RAM16(0x002B + x));
    RAM16_SET(0x0299, RAM16(0x0032 + x));
    uint16_t value3 = RAM16(0x0098 + x);
    r->a = (value3 & 7) | 0x2800;
    r->x = 0x311D;
    r->y = (value3 & 7) | 0x2800;
    JSR(c, 0x33A6, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    RAM16_SET(0x00B0 + x_ret, RAM16(0x0287));
    RAM16_SET(0x00A7 + x_ret, RAM16(0x0295));
    RAM16_SET(0x002B + x_ret, RAM16(0x0297));
    RAM16_SET(0x0032 + x_ret, RAM16(0x0299));
    r->a = RAM16(0x0287);
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23385, SOM_RTS, "gen", allocate_parent_linked_boss_effect_and_copy_coordinates, 0, L_B | L_Y | L_C | L_V, 1, 0, 0, 57, 23)
