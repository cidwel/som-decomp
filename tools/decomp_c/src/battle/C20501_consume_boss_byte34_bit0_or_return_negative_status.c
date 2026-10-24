#include "som_c.h"

/* C20501 consume_boss_byte34_bit0_or_return_negative_status   [class B, 27 bytes, 14 instructions]
 * Source: src/rom/consume_boss_byte34_bit0_or_return_negative_status.s
 * Documented in docs/boss-native-linked-parent-update.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void consume_boss_byte34_bit0_or_return_negative_status(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0x0191 + x);
    if (value & 0x80) {
        r->a = (a >> 8 << 8) | value;
        r->c = 1;
        RETURN_RTS(c);
    }
    uint8_t value2 = RAM8(0x0034 + x);
    if ((value2 & 1) == 0) {
        r->a = (a >> 8 << 8) | value2;
        r->c = 0;
        RETURN_RTS(c);
    }
    RAM8(0x0034 + x) = value2 & 0xFE;
    r->a = a >> 8 << 8 | (value2 & 0xFE);
    r->c = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20501, SOM_RTS, "gen", consume_boss_byte34_bit0_or_return_negative_status, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 27, 14)
