#include "som_c.h"

/* C05C2A append_rom_message_text   [class A, 14 bytes, 7 instructions]
 * Source: src/rom/append_rom_message_text.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCV.
 */
static void append_rom_message_text(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    for (;;) {
        uint8_t value = BUS8(c, 0xC00000 + x1);
        if (value != 0) {
            RAM8(0xFE00 + y1) = value;
            a1 = value;
            x1 = (uint16_t)(x1 + 1);
            y1 = (uint16_t)(y1 + 1);
            continue;
        }
        a1 = value;
        break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05C2A, SOM_RTS, "gen", append_rom_message_text, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 14, 7)
