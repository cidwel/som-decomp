#include "som_c.h"

/* CC0AA1 publish_scrolling_dialogue_sprite_graphics   [class B, 95 bytes, 41 instructions]
 * Source: src/rom/publish_scrolling_dialogue_sprite_graphics.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void publish_scrolling_dialogue_sprite_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    { const uint16_t sp_call = r->sp; JSL(c, 0x0AA4, 0xC10030); GUARD_JSL(c, sp_call, 0x0AA4); } /* initialize_scrolling_dialogue_sprite_workspace_long */
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    BUS8_SET(c, (db_ret << 0x10) + 0xA161, 0);
    BUS8_SET(c, (db_ret << 0x10) + 0xA175, 4);
    uint8_t a1 = 4;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t a2 = 0x20;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        for (;;) {
            uint8_t value = BUS8(c, 0xDCFF80 + x2);
            BUS8_SET(c, (db_ret << 0x10) + 0x9400 + y2, value);
            a2 = (uint8_t)(a2 - 1);
            a_hi2 = value;
            x2 = (uint16_t)(x2 + 1);
            y2 = (uint16_t)(y2 + 1);
            if (!(a2 != 0)) break;
        }
        RAM8(0x0000 + sp0) = x2 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x2;
        uint16_t x3 = 0x20;
        uint16_t y3 = y2;
        for (;;) {
            BUS8_SET(c, (db_ret << 0x10) + 0x9400 + y3, 0);
            x3 = (uint16_t)(x3 - 1);
            y3 = (uint16_t)(y3 + 1);
            if (!(x3 != 0)) break;
        }
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xA175);
        BUS8_SET(c, (db_ret << 0x10) + 0xA175, (uint8_t)(value4 - 1));
        a1 = 0;
        a_hi1 = a_hi2;
        x1 = (value3 << 8) | value2;
        y1 = y3;
        if (!((uint8_t)(value4 - 1) != a1)) break;
    }
    BUS8_SET(c, (db_ret << 0x10) + 0x9400 + y1, a1);
    BUS8_SET(c, (db_ret << 0x10) + 0x1D11, 5);
    RAM8(0x1D04) |= 4;
    uint16_t value6 = RAM16(0x1D01);
    RAM16_SET(0x1D01, (uint16_t)(value6 + 2));
    BUS8_SET(c, (db_ret << 0x10) + 0xA170, 0);
    RAM8(0x1D11) = 4;
    r->a = ((uint16_t)(value6 + 2) >> 8 << 8) | 4;
    r->x = x1;
    r->y = y1;
    r->c = carry_ret;
    r->z = 0;
    r->n = 0;
    r->v = overflow_ret;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC0AA1, SOM_RTS, "gen", publish_scrolling_dialogue_sprite_graphics, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 95, 41)
