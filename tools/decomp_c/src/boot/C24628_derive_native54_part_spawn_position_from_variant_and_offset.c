#include "som_c.h"

/* C24628 derive_native54_part_spawn_position_from_variant_and_offset   [class A, 27 bytes, 14 instructions]
 * Source: src/rom/derive_native54_part_spawn_position_from_variant_and_offset.s
 * Documented in docs/boss-native54-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXV.
 */
static void derive_native54_part_spawn_position_from_variant_and_offset(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM16_SET(0x0295, a);
    uint16_t value = RAM16(0x0042 + x);
    uint16_t value2 = RAM16(0x0295);
    uint16_t value3 = BUS16(c, 0xC24643 + (uint16_t)((uint16_t)(value << 3) + value2));
    RAM16_SET(0x0295, value3);
    uint16_t value4 = BUS16(c, 0xC24645 + (uint16_t)((uint16_t)(value << 3) + value2));
    RAM16_SET(0x0297, value4);
    uint16_t value5 = RAM16(0x0287);
    r->a = value4;
    r->x = value5;
    r->v = (((uint16_t)(value << 3) ^ (uint16_t)((uint16_t)(value << 3) + value2)) & (value2 ^ (uint16_t)((uint16_t)(value << 3) + value2)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24628, SOM_RTS, "gen", derive_native54_part_spawn_position_from_variant_and_offset, 0, L_B | L_X | L_V, 1, 0, 0, 27, 14)
