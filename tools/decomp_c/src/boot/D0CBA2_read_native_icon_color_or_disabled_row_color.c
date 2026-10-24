#include "som_c.h"
#include "som_hand_b.h"

/* D0CBA2 read_native_icon_color_or_disabled_row_color   [class C, 42 bytes, 23 instructions]
 * Source: src/rom/read_native_icon_color_or_disabled_row_color.s
 * Documented in docs/event-menu-icon-palette.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void read_native_icon_color_or_disabled_row_color(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->a = BUS16(c, 0xD2C900u + r->x);
    hand_nz16(r, r->a);
    i_phx(c);
    i_pha(c);
    r->x = RAM16(0x1820);
    uint16_t row_flags = BUS16(c, r->x); /* LDA $00,X: direct page 0, wraps at 16 bits */
    r->a = row_flags & 0x4000;
    hand_nz16(r, r->a);
    if (r->a != 0) {
        /* Disabled row: replace the saved colour (at 1,S) by the dimmed table entry indexed by the saved X (at 3,S). */
        r->x = RAM16(r->sp + 3);
        uint16_t dim = BUS16(c, 0xD0CBCCu + r->x);
        RAM16_SET(r->sp + 1, dim);
    }
    i_pla(c);
    i_plx(c);
    r->x++;
    r->x++;
    hand_nz16(r, r->x);
    i_phx(c);
    r->x = RAM16(0x1822);
    bus16_set_once(c, r->x, r->a);
    r->x++;
    r->x++;
    hand_nz16(r, r->x);
    RAM16_SET(0x1822, r->x);
    i_plx(c);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CBA2, SOM_RTS, "hand", read_native_icon_color_or_disabled_row_color, 0, L_B | L_X | L_Y | L_C | L_V, 4, 0, 0, 42, 23)
