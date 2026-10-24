#include "som_c.h"

/* C0DD55 copy_map_object_record_to_cache   [class B, 54 bytes, 29 instructions]
 * Source: src/rom/copy_map_object_record_to_cache.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void copy_map_object_record_to_cache(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value;
    BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D), value);
    RAM16_SET(0xC808 + x, value);
    uint16_t value2;
    BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + 2, value2);
    RAM16_SET(0xC80A + x, value2);
    uint16_t value3;
    BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + 4, value3);
    RAM16_SET(0xC80C + x, value3);
    uint16_t value4;
    BUS16_OK(c, (RAM8(0x000F) << 0x10) + RAM16(0x000D) + 6, value4);
    RAM16_SET(0xC80E + x, value4);
    RAM8(0x0000) = (uint8_t)value2 >> 1;
    RAM8(0xC807 + x) = (((value2 >> 8) & 0x80) | RAM8(0x0000)) & 0xC0;
    RAM8(0xC800 + x) = 1;
    r->y = 6;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DD55, SOM_RTS, "hand", copy_map_object_record_to_cache, 0, L_X | L_Y, 2, 1, 0, 54, 29)
