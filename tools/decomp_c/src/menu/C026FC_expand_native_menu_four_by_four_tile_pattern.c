#include "som_c.h"

/* C026FC expand_native_menu_four_by_four_tile_pattern   [class B, 47 bytes, 26 instructions]
 * Source: src/rom/expand_native_menu_four_by_four_tile_pattern.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void expand_native_menu_four_by_four_tile_pattern(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    RAM8(0xA175) = 4;
    uint8_t a_hi1 = a;
    uint16_t x1 = x;
    do {
        RAM8(0x0000 + sp0) = x1 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x1;
        RAM8(0xA176) = 4;
        uint8_t a1 = 0x26;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        do {
            RAM8(0x9000 + x2) = a1;
            RAM8(0x9000 + (uint16_t)(x2 + 1)) = a_hi2;
            RAM8(0xA176)--;
            x2 = (uint16_t)(x2 + 2);
        } while (RAM8(0xA176) != 0);
        uint8_t value = RAM8(0x0000 + sp0 - 1);
        uint8_t value2 = RAM8(0x0000 + sp0);
        RAM8(0xA175)--;
        a_hi1 = a_hi2;
        x1 = (uint16_t)(((value2 << 8) | value) + 0x40);
    } while (RAM8(0xA175) != 0);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC026FC, SOM_RTS, "gen", expand_native_menu_four_by_four_tile_pattern, 0, 0, 2, 1, 0, 47, 26)
