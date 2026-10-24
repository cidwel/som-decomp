#include "som_c.h"

/* C02523 skip_native_menu_interior_tile_columns   [class A, 16 bytes, 8 instructions]
 * Source: src/rom/skip_native_menu_interior_tile_columns.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void skip_native_menu_interior_tile_columns(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0xA16C);
    RAM16_SET(0xA173, x);
    r->x = (uint16_t)(((value & 0xFF) << 1) + RAM16(0xA173));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02523, SOM_RTS, "gen", skip_native_menu_interior_tile_columns, 0, L_X, 1, 0, 0, 16, 8)
