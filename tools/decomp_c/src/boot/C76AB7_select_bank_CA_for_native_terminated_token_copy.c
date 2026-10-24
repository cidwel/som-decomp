#include "som_c.h"

/* C76AB7 select_bank_CA_for_native_terminated_token_copy   [class A, 27 bytes, 17 instructions]
 * Source: src/rom/select_bank_CA_for_native_terminated_token_copy.s
 * Documented in docs/ui-native-spell-item-detail.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void select_bank_CA_for_native_terminated_token_copy(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = 0xCA;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    for (;;) {
        uint8_t value = BUS8(c, 0xCA0000 + y1);
        if (value != 0) {
            RAM8(0x9C00 + x1) = value;
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
SOM_REGISTER(0xC76AB7, SOM_RTS, "gen", select_bank_CA_for_native_terminated_token_copy, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 27, 17)
