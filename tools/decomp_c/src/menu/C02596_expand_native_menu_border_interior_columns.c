#include "som_c.h"

/* C02596 expand_native_menu_border_interior_columns   [class A, 23 bytes, 11 instructions]
 * Source: src/rom/expand_native_menu_border_interior_columns.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void expand_native_menu_border_interior_columns_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint16_t x1 = x;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            RAM16_SET(0x9000 + x1, a);
            RAM8(0xA164)--;
            if (RAM8(0xA164) != 0) {
                x1 = (uint16_t)(x1 + 2);
                first_pass = false;
                continue;
            }
            x1 = (uint16_t)(x1 + 2);
            break;
        } else {
            RAM16_SET(0x9000 + x1, a);
            RAM8(0xA164)--;
            if (RAM8(0xA164) != 0) {
                x1 = (uint16_t)(x1 + 2);
                continue;
            }
            x1 = (uint16_t)(x1 + 2);
            break;
        }
    }
    RAM8(0xA164) = RAM8(0xA16C);
    r->x = x1;
    RETURN_RTS(c);
}

/* C02596 expand_native_menu_border_interior_columns   [class A, 23 bytes, 11 instructions]
 * Source: src/rom/expand_native_menu_border_interior_columns.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void expand_native_menu_border_interior_columns_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint16_t x1 = x;
    do {
        RAM16_SET(0x9000 + x1, (a_hi << 8) | a);
        RAM8(0xA164)--;
        x1 = (uint16_t)(x1 + 2);
    } while (RAM8(0xA164) != 0);
    RAM8(0xA164) = RAM8(0xA16C);
    r->x = x1;
    r->mf = 0;
    RETURN_RTS(c);
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void expand_native_menu_border_interior_columns(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { expand_native_menu_border_interior_columns_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { expand_native_menu_border_interior_columns_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC02596, SOM_RTS, "gen", expand_native_menu_border_interior_columns, 0, L_X, 1, -1, -1, 23, 11)
