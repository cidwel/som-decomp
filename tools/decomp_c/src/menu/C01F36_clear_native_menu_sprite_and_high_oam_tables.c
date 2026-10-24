#include "som_c.h"

/* C01F36 clear_native_menu_sprite_and_high_oam_tables   [class B, 37 bytes, 19 instructions]
 * Source: src/rom/clear_native_menu_sprite_and_high_oam_tables.s
 * Documented in docs/event-menu-controller.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZV.
 */
static void clear_native_menu_sprite_and_high_oam_tables(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t x1 = 0;
    uint16_t y1 = 0x80;
    for (;;) {
        RAM16_SET(0x9C00 + x1, 0xF8F8);
        RAM16_SET(0x9C00 + (uint16_t)(x1 + 2), 0);
        x1 = (uint16_t)(x1 + 4);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    uint16_t x2 = x1;
    uint16_t y2 = 0x20;
    bool zero1 = 0;
    for (;;) {
        RAM8(0x9C00 + x2) = 0;
        uint16_t x2_next = (uint16_t)(x2 + 1);
        uint16_t y2_next = (uint16_t)(y2 - 1);
        bool zero1_next = (uint16_t)(y2 - 1) == 0;
        x2 = x2_next;
        y2 = y2_next;
        zero1 = zero1_next;
        if (!(y2 != 0)) break;
    }
    r->a = 0xF8F8;
    r->x = x2;
    r->y = y2;
    r->c = carry;
    r->z = zero1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01F36, SOM_RTS, "gen", clear_native_menu_sprite_and_high_oam_tables, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 37, 19)
