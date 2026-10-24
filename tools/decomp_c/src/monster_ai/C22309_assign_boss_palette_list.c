#include "som_c.h"

/* C22309 assign_boss_palette_list   [class B, 66 bytes, 32 instructions]
 * Source: src/rom/assign_boss_palette_list.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 */
static void assign_boss_palette_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    RAM16_SET(0x0234, 0xC100);
    uint16_t value = BUS16(c, 0xCABE00 + (uint16_t)((uint16_t)(a - 0x54) << 1));
    RAM16_SET(0x0233, value);
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(0x0FA4);
    RAM16_SET(0x00A3 + value2, value3);
    RAM16_SET(0x0224, value3);
    uint8_t a_hi1 = value3 >> 8;
    uint16_t x1 = value2;
    uint16_t y1 = y;
    bool overflow1 = ((a ^ 0x54) & (a ^ (uint16_t)(a - 0x54)) & 0x8000) != 0;
    for (;;) {
        uint16_t value4 = BUS16(c, (RAM8(0x0235) << 0x10) + RAM16(0x0233));
        RAM16_SET(0x0233, (uint16_t)(RAM16(0x0233) + 1));
        if ((value4 & 0xFF) != 0xFF) {
            uint8_t value5 = RAM8(0x0224);
            RAM8(0x0018 + x1) = (uint8_t)((value4 & 0xFF) + value5);
            uint16_t value6 = BUS16(c, (RAM8(0x0235) << 0x10) + RAM16(0x0233));
            RAM16_SET(0x0233, (uint16_t)(RAM16(0x0233) + 1));
            r->a = value6 & 0xFF;
            r->x = (uint8_t)((value4 & 0xFF) + value5);
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0x0200;
            r->sp -= 2;
            JSR(c, 0x2346, 0xC226AC); /* load_boss_palette_through_wram_dma */
            r->sp += 2;
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            bool overflow_ret = r->v;
            a_hi1 = a_all >> 8;
            x1 = (uint16_t)(x1 + 1);
            y1 = y_ret;
            overflow1 = overflow_ret;
            continue;
        }
        a_hi1 = 0;
        break;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->y = y1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22309, SOM_RTS, "gen", assign_boss_palette_list, 0, L_B | L_Y | L_V, 2, 0, 0, 66, 32)
