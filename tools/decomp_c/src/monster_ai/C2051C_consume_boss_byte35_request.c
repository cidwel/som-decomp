#include "som_c.h"

/* C2051C consume_boss_byte35_request   [class A, 18 bytes, 10 instructions]
 * Source: src/rom/consume_boss_byte35_request.s
 * Documented in docs/boss-actor-controller.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void consume_boss_byte35_request(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0x0035 + x);
    if (value == 0) {
        r->a = (a >> 8 << 8) | value;
        r->c = 0;
        RETURN_RTS(c);
    }
    RAM8(0x0035 + x) = 0;
    r->a = (a >> 8 << 8) | value;
    r->c = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2051C, SOM_RTS, "gen", consume_boss_byte35_request, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 18, 10)
