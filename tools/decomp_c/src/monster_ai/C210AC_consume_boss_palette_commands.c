#include "som_c.h"

/* C210AC consume_boss_palette_commands   [class B, 38 bytes, 20 instructions]
 * Source: src/rom/consume_boss_palette_commands.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void consume_boss_palette_commands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x0100 + x);
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y1;
    bool overflow2;
    if (value == 0) {
        a_hi2 = a >> 8;
        x2 = x;
        y1 = y;
        overflow2 = overflow;
    } else {
        uint8_t value2 = RAM8(0x0102 + x);
        uint8_t a_hi1;
        uint16_t x1;
        bool overflow1;
        if (value2 == 0) {
            a_hi1 = a >> 8;
            x1 = x;
            overflow1 = overflow;
        } else {
            r->a = (RAM8(0x0103 + x) << 8) | value2;
            r->y = (uint16_t)(x + 2);
            r->mf = 1;
            JSR(c, 0x10C2, 0xC210D2); /* dispatch_boss_palette_command */
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            bool overflow_ret = r->v;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            overflow1 = overflow_ret;
        }
        r->a = (RAM8(0x0101 + x1) << 8) | RAM8(0x0100 + x1);
        r->x = x1;
        r->y = x1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x10CE, 0xC210D2); /* dispatch_boss_palette_command */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool overflow_ret2 = r->v;
        a_hi2 = a_all2 >> 8;
        x2 = x_ret2;
        y1 = y_ret2;
        overflow2 = overflow_ret2;
    }
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->x = x2;
    r->y = y1;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC210AC, SOM_RTS, "gen", consume_boss_palette_commands, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 38, 20)
