#include "som_c.h"

/* C21F80 emit_boss_sprite_piece_list   [class B, 53 bytes, 27 instructions]
 * Source: src/rom/emit_boss_sprite_piece_list.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: X.
 */
static void emit_boss_sprite_piece_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x1F84, 0xC22005); /* prepare_boss_sprite_screen_position */
    RAM16_SET(0x0279, (uint16_t)(((uint16_t)(RAM16(0x0287) - 0xE600) >> 2) + 0xF800));
    uint16_t value3 = BUS16(c, RAM16(0x0279) + 0x7E0000);
    if ((value3 & 0xFF) == 0) {
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0285, value3 & 0xFF);
    RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
    RAM16_SET(0x0266, 0);
    RAM16_SET(0x028D, RAM16(0x0098 + value));
    uint16_t value5 = RAM16(0x027F);
    RAM16_SET(0x0295, value5);
    r->a = value5;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x1FAB, 0xC21FB5); /* emit_boss_sprite_pieces_in_reverse_order */
    RAM16_SET(0x027F, (uint16_t)(RAM16(0x027F) + RAM16(0x0285)));
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21F80, SOM_RTS, "gen", emit_boss_sprite_piece_list, 0, L_X, 1, 0, 0, 53, 27)
