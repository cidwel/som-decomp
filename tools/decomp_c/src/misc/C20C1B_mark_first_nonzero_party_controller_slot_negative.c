#include "som_c.h"

/* C20C1B mark_first_nonzero_party_controller_slot_negative   [class B, 24 bytes, 12 instructions]
 * Source: src/rom/mark_first_nonzero_party_controller_slot_negative.s
 * Documented in docs/boss-native-linked-death-dependencies.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void mark_first_nonzero_party_controller_slot_negative(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 0;
    bool carry1 = carry;
    for (;;) {
        uint8_t value = RAM8(0x00D9 + x1);
        uint8_t x2;
        bool carry2;
        if (value == 0) {
            if ((uint8_t)(x1 + 1) < 3) {
                uint8_t x1_next = (uint8_t)(x1 + 1);
                bool carry1_next = (uint8_t)(x1 + 1) >= 3;
                x1 = x1_next;
                carry1 = carry1_next;
                continue;
            }
            x2 = (uint8_t)(x1 + 1);
            carry2 = (uint8_t)(x1 + 1) >= 3;
        } else {
            RAM8(0x00D9 + x1) = value | 0x80;
            x2 = x1;
            carry2 = carry1;
        }
        x1 = x2;
        carry1 = carry2;
        break;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x1;
    r->y = (uint8_t)y;
    r->c = carry1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20C1B, SOM_RTS, "gen", mark_first_nonzero_party_controller_slot_negative, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 24, 12)
