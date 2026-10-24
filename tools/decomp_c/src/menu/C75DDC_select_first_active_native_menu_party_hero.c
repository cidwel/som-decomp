#include "som_c.h"

/* C75DDC select_first_active_native_menu_party_hero   [class A, 29 bytes, 12 instructions]
 * Source: src/rom/select_first_active_native_menu_party_hero.s
 * Documented in docs/event-menu-page-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void select_first_active_native_menu_party_hero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    bool carry1 = carry;
    for (;;) {
        uint8_t value = BUS8(c, 0x0000D9 + x1);
        uint16_t x2;
        bool carry2;
        if ((value & 0x80) != 0) {
            x2 = x1;
            carry2 = carry1;
        } else {
            if ((uint16_t)(x1 + 1) != 3) {
                uint16_t x1_next = (uint16_t)(x1 + 1);
                bool carry1_next = (uint16_t)(x1 + 1) >= 3;
                x1 = x1_next;
                carry1 = carry1_next;
                continue;
            }
            x2 = 0;
            carry2 = (uint16_t)(x1 + 1) >= 3;
        }
        x1 = x2;
        carry1 = carry2;
        break;
    }
    RAM8(0xA220) = (uint8_t)x1;
    RAM8(0x19FD) = (uint8_t)x1;
    r->a = (a_hi1 << 8) | (uint8_t)x1;
    r->x = x1;
    r->y = y;
    r->c = carry1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75DDC, SOM_RTS, "gen", select_first_active_native_menu_party_hero, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 29, 12)
