#include "som_c.h"

/* C05D33 clear_message_queue_line   [class A, 19 bytes, 12 instructions]
 * Source: src/rom/clear_message_queue_line.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void clear_message_queue_line(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t x1 = 0x0F;
    uint16_t y1 = y;
    for (;;) {
        RAM16_SET(0xFE00 + y1, 0);
        x1 = (uint16_t)(x1 - 1);
        y1 = (uint16_t)(y1 + 2);
        if (!(x1 != 0)) break;
    }
    r->a = 0;
    r->x = x;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05D33, SOM_RTS, "gen", clear_message_queue_line, 0, L_B | L_X | L_Y | L_C | L_V, 4, 0, 0, 19, 12)
