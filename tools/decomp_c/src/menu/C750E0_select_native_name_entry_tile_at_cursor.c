#include "som_c.h"

/* C750E0 select_native_name_entry_tile_at_cursor   [class B, 57 bytes, 31 instructions]
 * Source: src/rom/select_native_name_entry_tile_at_cursor.s
 * Documented in docs/event-menu-name-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void select_native_name_entry_tile_at_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0xA173, ((uint8_t)(RAM8(0xA15A) - 0x48) & 0xF8) << 1 << 1 << 1);
    uint16_t value2 = RAM16(0xA159);
    uint16_t value3 = RAM16(0xA173);
    uint16_t value4 = RAM16(0x9246 + (uint16_t)((((uint16_t)((value2 & 0xFF) - 0x10) & 0xF8) >> 2) + value3));
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    if (value4 == 0) {
        a1 = (uint8_t)value4;
        a_hi1 = value4 >> 8;
        carry1 = 1;
    } else {
        RAM16_SET(0xA1A0, value4);
        RAM16_SET(0xA1A2, (uint16_t)(value4 + 2));
        a1 = (uint8_t)(value4 + 2);
        a_hi1 = (uint16_t)(value4 + 2) >> 8;
        carry1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = (uint16_t)((((uint16_t)((value2 & 0xFF) - 0x10) & 0xF8) >> 2) + value3);
    r->c = carry1;
    r->v = (((((uint16_t)((value2 & 0xFF) - 0x10) & 0xF8) >> 2) ^ (uint16_t)((((uint16_t)((value2 & 0xFF) - 0x10) & 0xF8) >> 2) + value3)) & (value3 ^ (uint16_t)((((uint16_t)((value2 & 0xFF) - 0x10) & 0xF8) >> 2) + value3)) & 0x8000) != 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC750E0, SOM_RTL, "gen", select_native_name_entry_tile_at_cursor, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 57, 31)
