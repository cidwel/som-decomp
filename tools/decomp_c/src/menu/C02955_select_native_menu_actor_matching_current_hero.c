#include "som_c.h"

/* C02955 select_native_menu_actor_matching_current_hero   [class A, 48 bytes, 24 instructions]
 * Source: src/rom/select_native_menu_actor_matching_current_hero.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void select_native_menu_actor_matching_current_hero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = db;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    uint8_t value = RAM8(0x19FE);
    uint8_t a1;
    if ((uint8_t)(value << 1) != 0) {
        a1 = (uint8_t)(value << 1);
    } else {
        a1 = (uint8_t)((uint8_t)(value << 1) + 1);
    }
    RAM8(0xA173) = a1;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    bool carry1 = value & 0x80;
    for (;;) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp + 0xD9 + x1));
        uint8_t value3 = RAM8(0xA173);
        uint16_t x2;
        bool carry2;
        if ((value2 & 0x7F) == value3) {
            x2 = x1;
            carry2 = (value2 & 0x7F) >= value3;
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
    RAM8(0xA221) = 0;
    r->a = (a_hi1 << 8) | 0;
    r->x = x1;
    r->y = y;
    r->c = carry1;
    r->z = db == 0;
    r->n = db & 0x80;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02955, SOM_RTS, "gen", select_native_menu_actor_matching_current_hero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 48, 24)
