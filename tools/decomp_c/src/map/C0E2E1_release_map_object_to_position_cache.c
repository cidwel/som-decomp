#include "som_c.h"

/* C0E2E1 release_map_object_to_position_cache   [class B, 67 bytes, 36 instructions]
 * Source: src/rom/release_map_object_to_position_cache.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void release_map_object_to_position_cache(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0000, (RAM16(0xE002 + x) >> 4) & 0x7F);
    uint16_t value2 = RAM16(0xE004 + x);
    uint16_t value3 = RAM16(0x0000);
    uint16_t value4 = RAM16(0xE034 + x);
    RAM16_SET(0xC80A + value4, ((((uint8_t)(value2 >> 4) << 8) | (value2 >> 4 >> 8)) & 0x7F00) | value3);
    uint8_t value5 = RAM8(0xE00B + x);
    RAM8(0x0000) = (value5 & 0x80) >> 4;
    RAM8(0xC80C + value4) = (RAM8(0xC80C + value4) & 0xF7) | RAM8(0x0000);
    RAM8(0xC800 + value4) &= 0x7F;
    r->c = (value5 & 0x80) >> 3 & 0x01;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0E2E1, SOM_RTS, "gen", release_map_object_to_position_cache, 0, L_X | L_Y | L_C | L_V, 2, 1, 0, 67, 36)
