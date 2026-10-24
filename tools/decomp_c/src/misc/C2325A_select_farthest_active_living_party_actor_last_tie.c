#include "som_c.h"

/* C2325A select_farthest_active_living_party_actor_last_tie   [class B, 51 bytes, 25 instructions]
 * Source: src/rom/select_farthest_active_living_party_actor_last_tie.s
 * Documented in docs/boss-native58-action-helpers.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void select_farthest_active_living_party_actor_last_tie(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x021A, 0);
    RAM16_SET(0x021C, 0);
    uint8_t a_hi1 = a >> 8;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
        uint8_t a_hi3;
        bool overflow3;
        if ((value & 0xFF) != 1) {
            a_hi3 = 0;
            overflow3 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        } else {
            uint16_t value2 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
            uint8_t a_hi2;
            bool overflow2;
            if (value2 & 0x8000) {
                a_hi2 = value2 >> 8;
                overflow2 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            } else {
                r->a = value2;
                r->x = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
                r->y = y1;
                r->mf = 0;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0x0200;
                JSR(c, 0x327B, 0xC208F1); /* derive_actor_manhattan_distance_from_selected_boss */
                uint16_t a_all = r->a;
                bool overflow_ret = r->v;
                if (a_all >= RAM16(0x021A)) {
                    RAM16_SET(0x021A, a_all);
                    RAM16_SET(0x021C, y1);
                }
                a_hi2 = a_all >> 8;
                overflow2 = overflow_ret;
            }
            a_hi3 = a_hi2;
            overflow3 = overflow2;
        }
        uint8_t a_hi1_next = a_hi3;
        uint16_t y1_next = (uint16_t)(y1 + 1);
        bool carry1_next = (uint16_t)(y1 + 1) >= 3;
        bool overflow1_next = overflow3;
        a_hi1 = a_hi1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!(y1 != 3)) break;
    }
    r->a = RAM16(0x021C);
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2325A, SOM_RTS, "gen", select_farthest_active_living_party_actor_last_tie, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 51, 25)
