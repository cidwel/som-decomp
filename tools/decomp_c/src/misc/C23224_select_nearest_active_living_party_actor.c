#include "som_c.h"

/* C23224 select_nearest_active_living_party_actor   [class B, 54 bytes, 26 instructions]
 * Source: src/rom/select_nearest_active_living_party_actor.s
 * Documented in docs/boss-descriptor-four.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void select_nearest_active_living_party_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x021A, 0x7FFF);
    RAM16_SET(0x021C, 0);
    uint8_t a_hi1 = 0x7F;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
        uint8_t a_hi3;
        uint16_t x3;
        bool overflow3;
        if ((value & 0xFF) != 1) {
            a_hi3 = 0;
            x3 = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
            overflow3 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        } else {
            uint16_t value2 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
            uint8_t a_hi2;
            uint16_t x2;
            bool overflow2;
            if (value2 & 0x8000) {
                a_hi2 = value2 >> 8;
                x2 = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
                overflow2 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            } else {
                r->a = value2;
                r->x = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
                r->y = y1;
                r->mf = 0;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0x0200;
                JSR(c, 0x3248, 0xC208F1); /* derive_actor_manhattan_distance_from_selected_boss */
                uint16_t a_all = r->a;
                uint16_t x_ret = r->x;
                bool overflow_ret = r->v;
                if (a_all < RAM16(0x021A)) {
                    RAM16_SET(0x021A, a_all);
                    RAM16_SET(0x021C, y1);
                }
                a_hi2 = a_all >> 8;
                x2 = x_ret;
                overflow2 = overflow_ret;
            }
            a_hi3 = a_hi2;
            x3 = x2;
            overflow3 = overflow2;
        }
        uint8_t a_hi1_next = a_hi3;
        uint16_t x1_next = x3;
        uint16_t y1_next = (uint16_t)(y1 + 1);
        bool carry1_next = (uint16_t)(y1 + 1) >= 3;
        bool overflow1_next = overflow3;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!(y1 != 3)) break;
    }
    r->a = RAM16(0x021C);
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23224, SOM_RTS, "gen", select_nearest_active_living_party_actor, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 54, 26)
