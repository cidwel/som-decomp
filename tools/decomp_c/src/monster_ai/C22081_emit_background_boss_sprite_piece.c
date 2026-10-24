#include "som_c.h"

/* C22081 emit_background_boss_sprite_piece   [class B, 20 bytes, 11 instructions]
 * Source: src/rom/emit_background_boss_sprite_piece.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XC.
 */
static void emit_background_boss_sprite_piece(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0295);
    r->a = (uint16_t)(value << 2);
    r->x = (uint16_t)(value << 2);
    JSR(c, 0x2088, 0xC22095); /* clip_boss_sprite_horizontal */
    bool carry_ret = r->c;
    uint16_t x2;
    bool carry2;
    if (carry_ret) {
        x2 = (uint16_t)(value << 2);
        carry2 = carry_ret;
    } else {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x208D, 0xC220C0); /* clip_boss_sprite_vertical */
        bool carry_ret2 = r->c;
        uint16_t x1;
        bool carry1;
        if (carry_ret2) {
            x1 = (uint16_t)(value << 2);
            carry1 = carry_ret2;
        } else {
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x2092, 0xC22150); /* write_background_boss_sprite_attributes */
            uint16_t x_ret = r->x;
            x1 = x_ret;
            carry1 = 0;
        }
        x2 = x1;
        carry2 = carry1;
    }
    r->x = x2;
    r->c = carry2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22081, SOM_RTS, "gen", emit_background_boss_sprite_piece, 0, L_X | L_C, 1, 0, 0, 20, 11)
