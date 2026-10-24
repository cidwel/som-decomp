#include "som_c.h"

/* C02533 expand_native_menu_interior_sequential_tiles   [class A, 35 bytes, 18 instructions]
 * Source: src/rom/expand_native_menu_interior_sequential_tiles.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void expand_native_menu_interior_sequential_tiles_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0xA1C7);
    uint8_t a1 = (uint8_t)value;
    uint8_t a_hi1 = value >> 8;
    uint16_t x1 = x;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            RAM16_SET(0x9000 + x1, (a_hi1 << 8) | a1);
            RAM16_SET(0x9040 + x1, (uint16_t)(((a_hi1 << 8) | a1) + 2));
            RAM8(0xA164)--;
            if (RAM8(0xA164) != 0) {
                uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) + 4);
                uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) + 4) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 2);
                a1 = a1_next;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                first_pass = false;
                continue;
            }
            uint8_t a1_next2 = (uint8_t)(((a_hi1 << 8) | a1) + 4);
            uint8_t a_hi1_next2 = (uint16_t)(((a_hi1 << 8) | a1) + 4) >> 8;
            uint16_t x1_next2 = (uint16_t)(x1 + 2);
            a1 = a1_next2;
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            break;
        } else {
            RAM16_SET(0x9000 + x1, (a_hi1 << 8) | a1);
            RAM16_SET(0x9040 + x1, (uint16_t)(((a_hi1 << 8) | a1) + 2));
            RAM8(0xA164)--;
            if (RAM8(0xA164) != 0) {
                uint8_t a1_next3 = (uint8_t)(((a_hi1 << 8) | a1) + 4);
                uint8_t a_hi1_next3 = (uint16_t)(((a_hi1 << 8) | a1) + 4) >> 8;
                uint16_t x1_next3 = (uint16_t)(x1 + 2);
                a1 = a1_next3;
                a_hi1 = a_hi1_next3;
                x1 = x1_next3;
                continue;
            }
            uint8_t a1_next4 = (uint8_t)(((a_hi1 << 8) | a1) + 4);
            uint8_t a_hi1_next4 = (uint16_t)(((a_hi1 << 8) | a1) + 4) >> 8;
            uint16_t x1_next4 = (uint16_t)(x1 + 2);
            a1 = a1_next4;
            a_hi1 = a_hi1_next4;
            x1 = x1_next4;
            break;
        }
    }
    RAM16_SET(0xA1C7, (a_hi1 << 8) | a1 | 0x2000);
    r->x = x1;
    r->mf = 1;
    RETURN_RTS(c);
}

/* C02533 expand_native_menu_interior_sequential_tiles   [class A, 35 bytes, 18 instructions]
 * Source: src/rom/expand_native_menu_interior_sequential_tiles.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void expand_native_menu_interior_sequential_tiles_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t a1 = RAM8(0xA1C7);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    do {
        RAM16_SET(0x9000 + x1, (a_hi1 << 8) | a1);
        RAM16_SET(0x9040 + x1, (uint16_t)(((a_hi1 << 8) | a1) + 2));
        RAM8(0xA164)--;
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) + 4);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) + 4) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 2);
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
    } while (RAM8(0xA164) != 0);
    RAM16_SET(0xA1C7, (a_hi1 << 8) | a1 | 0x2000);
    r->x = x1;
    RETURN_RTS(c);
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void expand_native_menu_interior_sequential_tiles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { expand_native_menu_interior_sequential_tiles_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { expand_native_menu_interior_sequential_tiles_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC02533, SOM_RTS, "gen", expand_native_menu_interior_sequential_tiles, 0, L_X, 1, -1, -1, 35, 18)
