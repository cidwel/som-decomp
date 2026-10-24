#include "som_c.h"

/* C75EC8 native_menu_party_icon_alternative_entry_block   [class C, 88 bytes, 38 instructions]
 * Source: src/rom/native_menu_party_icon_alternative_entry_block.s
 * Documented in docs/event-menu-party-icons.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void native_menu_party_icon_alternative_entry_block(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 0;
    JSR(c, 0x5EE0, 0xC75F20); /* select_native_menu_icon_position_and_tile_cursor */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5F15, 0xC76D17); /* append_native_menu_four_tile_icon_group */
    RAM8(0xA159)++;
    RAM8(0xA15A)--;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x5F1E, 0xC76D17); /* append_native_menu_four_tile_icon_group */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75EC8, SOM_RTS, "gen", native_menu_party_icon_alternative_entry_block, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 88, 38)
