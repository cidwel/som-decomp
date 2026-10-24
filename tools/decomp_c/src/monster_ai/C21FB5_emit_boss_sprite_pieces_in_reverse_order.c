#include "som_c.h"

/* C21FB5 emit_boss_sprite_pieces_in_reverse_order   [class B, 80 bytes, 41 instructions]
 * Source: src/rom/emit_boss_sprite_pieces_in_reverse_order.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: X.
 */
static void emit_boss_sprite_pieces_in_reverse_order(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM16_SET(0x0291, (uint16_t)(((RAM16(0x0066 + x) >> 1) ^ 0xFFFF) + RAM16(0x0291)));
    uint16_t value3 = RAM16(0x0285);
    RAM16_SET(0x0297, (uint16_t)(value3 - 1));
    uint16_t value4 = RAM16(0x0279);
    RAM16_SET(0x0279, (uint16_t)((uint16_t)((uint16_t)(value3 - 1) << 2) + value4));
    uint16_t value5 = RAM16(0x0070 + x);
    if ((value5 & 8) != 0) {
        uint8_t a_hi1 = value5 >> 8;
        uint16_t x1 = x;
        bool carry1 = (uint16_t)((uint16_t)(value3 - 1) << 2) + value4 > 0xFFFF;
        for (;;) {
            r->a = (a_hi1 << 8) | (uint8_t)a;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0x0200;
            JSR(c, 0x1FEF, 0xC22081); /* emit_background_boss_sprite_piece */
            uint16_t x_ret = r->x;
            bool carry_ret = r->c;
            if (!carry_ret) {
                RAM16_SET(0x0295, (uint16_t)(RAM16(0x0295) + 1));
                RAM16_SET(0x0266, (uint16_t)(RAM16(0x0266) + 1));
            }
            RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) - 4));
            uint16_t value7 = RAM16(0x0266);
            uint16_t value8 = RAM16(0x0285);
            a_hi1 = value7 >> 8;
            x1 = x_ret;
            carry1 = value7 >= value8;
            if (!(value7 < value8)) break;
        }
        r->x = x1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        RETURN_RTS(c);
    }
    uint8_t a_hi2 = value5 >> 8;
    uint16_t x2 = x;
    bool carry2 = (uint16_t)((uint16_t)(value3 - 1) << 2) + value4 > 0xFFFF;
    for (;;) {
        r->a = (a_hi2 << 8) | (uint8_t)a;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        JSR(c, 0x1FD7, 0xC2206D); /* emit_normal_boss_sprite_piece */
        uint16_t x_ret2 = r->x;
        bool carry_ret2 = r->c;
        if (!carry_ret2) {
            RAM16_SET(0x0295, (uint16_t)(RAM16(0x0295) + 1));
            RAM16_SET(0x0266, (uint16_t)(RAM16(0x0266) + 1));
        }
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) - 4));
        uint16_t value10 = RAM16(0x0266);
        uint16_t value11 = RAM16(0x0285);
        a_hi2 = value10 >> 8;
        x2 = x_ret2;
        carry2 = value10 >= value11;
        if (!(value10 < value11)) break;
    }
    r->x = x2;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21FB5, SOM_RTS, "gen", emit_boss_sprite_pieces_in_reverse_order, 0, L_X, 1, 0, 0, 80, 41)
