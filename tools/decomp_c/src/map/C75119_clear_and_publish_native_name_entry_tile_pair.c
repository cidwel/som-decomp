#include "som_c.h"

/* C75119 clear_and_publish_native_name_entry_tile_pair   [class B, 47 bytes, 21 instructions]
 * Source: src/rom/clear_and_publish_native_name_entry_tile_pair.s
 * Documented in docs/event-menu-name-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void clear_and_publish_native_name_entry_tile_pair(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0xA1A0, 0);
    RAM16_SET(0xA1A2, 0);
    uint16_t value = RAM16(0xA156);
    uint16_t value2 = RAM16(0xA157);
    RAM16_SET(0x9000 + (uint16_t)(((((value & 0xFF) << 8) | 0) >> 2) + value2), RAM16(0xA1A0));
    uint16_t value4 = RAM16(0xA1A2);
    RAM16_SET(0x9040 + (uint16_t)(((((value & 0xFF) << 8) | 0) >> 2) + value2), value4);
    RAM8(0xA20A) |= 2;
    r->a = (value4 >> 8 << 8) | 2;
    r->x = (uint16_t)(((value & 0xFF) << 8 >> 2) + value2);
    r->c = ((value & 0xFF) << 8 >> 2) + value2 > 0xFFFF;
    r->v = ((((value & 0xFF) << 8 >> 2) ^ (uint16_t)(((value & 0xFF) << 8 >> 2) + value2)) & (value2 ^ (uint16_t)(((value & 0xFF) << 8 >> 2) + value2)) & 0x8000) != 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC75119, SOM_RTL, "gen", clear_and_publish_native_name_entry_tile_pair, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 47, 21)
