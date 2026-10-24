#include "som_c.h"

/* C02556 expand_native_menu_top_border   [class A, 32 bytes, 16 instructions]
 * Source: src/rom/expand_native_menu_top_border.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void expand_native_menu_top_border(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x9000 + x, 0x2020);
    r->a = 0x2024;
    r->x = (uint16_t)(x + 2);
    r->mf = 0;
    r->sp -= 2;
    JSR(c, 0x2566, 0xC02596); /* expand_native_menu_border_interior_columns */
    r->sp += 2;
    uint16_t x_ret = r->x;
    RAM16_SET(0x9000 + x_ret, 0x6020);
    r->x = (uint16_t)(x + 0x40);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02556, SOM_RTS, "gen", expand_native_menu_top_border, 0, L_X, 2, 1, 0, 32, 16)
