#include "som_c.h"

/* 7EA241 release_vertical_irq_use   [class D, 37 bytes, 20 instructions]
 * Source: src/boot/release_vertical_irq_use.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: nothing.
 */
static void release_vertical_irq_use(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    if (RAM8(0x1008C) == 0) {
        uint8_t value2 = RAM8(0x10090);
        RAM8(0x10090) = value2 & 0xDF;
        BUS8_SET(c, 0x004200, value2 & 0xDF);
    } else {
        RAM8(0x1008C)--;
        if (RAM8(0x1008C) == 0) {
            uint8_t value3 = RAM8(0x10090);
            RAM8(0x10090) = value3 & 0xDF;
            BUS8_SET(c, 0x004200, value3 & 0xDF);
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA241, SOM_RTS, "gen", release_vertical_irq_use, 0, 0, 5, 0, 0, 37, 20)
