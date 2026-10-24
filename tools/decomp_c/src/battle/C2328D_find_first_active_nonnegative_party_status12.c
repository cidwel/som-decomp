#include "som_c.h"

/* C2328D find_first_active_nonnegative_party_status12   [class B, 47 bytes, 23 instructions]
 * Source: src/rom/find_first_active_nonnegative_party_status12.s
 * Documented in docs/boss-target-status-queries.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void find_first_active_nonnegative_party_status12(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
        if ((value & 0xFF) != 1) {
            if ((uint16_t)(y1 + 1) != 3) {
                uint8_t a_hi1_next = 0;
                uint16_t x1_next = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
                uint16_t y1_next = (uint16_t)(y1 + 1);
                bool carry1_next = (uint16_t)(y1 + 1) >= 3;
                bool overflow1_next = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                y1 = y1_next;
                carry1 = carry1_next;
                overflow1 = overflow1_next;
                continue;
            }
            uint8_t a_hi1_next6 = 0;
            uint16_t x1_next6 = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
            uint16_t y1_next6 = (uint16_t)(y1 + 1);
            bool carry1_next6 = (uint16_t)(y1 + 1) >= 3;
            bool overflow1_next6 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            a_hi1 = a_hi1_next6;
            x1 = x1_next6;
            y1 = y1_next6;
            carry1 = carry1_next6;
            overflow1 = overflow1_next6;
            break;
        }
        uint16_t value2 = RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000));
        if (value2 & 0x8000) {
            if ((uint16_t)(y1 + 1) != 3) {
                uint8_t a_hi1_next2 = value2 >> 8;
                uint16_t x1_next2 = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
                uint16_t y1_next2 = (uint16_t)(y1 + 1);
                bool carry1_next2 = (uint16_t)(y1 + 1) >= 3;
                bool overflow1_next2 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                a_hi1 = a_hi1_next2;
                x1 = x1_next2;
                y1 = y1_next2;
                carry1 = carry1_next2;
                overflow1 = overflow1_next2;
                continue;
            }
            uint8_t a_hi1_next5 = value2 >> 8;
            uint16_t x1_next5 = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
            uint16_t y1_next5 = (uint16_t)(y1 + 1);
            bool carry1_next5 = (uint16_t)(y1 + 1) >= 3;
            bool overflow1_next5 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            a_hi1 = a_hi1_next5;
            x1 = x1_next5;
            y1 = y1_next5;
            carry1 = carry1_next5;
            overflow1 = overflow1_next5;
            break;
        }
        if ((value2 & 0x12) == 0) {
            if ((uint16_t)(y1 + 1) != 3) {
                uint8_t a_hi1_next3 = value2 >> 8;
                uint16_t x1_next3 = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
                uint16_t y1_next3 = (uint16_t)(y1 + 1);
                bool carry1_next3 = (uint16_t)(y1 + 1) >= 3;
                bool overflow1_next3 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
                a_hi1 = a_hi1_next3;
                x1 = x1_next3;
                y1 = y1_next3;
                carry1 = carry1_next3;
                overflow1 = overflow1_next3;
                continue;
            }
            uint8_t a_hi1_next4 = value2 >> 8;
            uint16_t x1_next4 = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
            uint16_t y1_next4 = (uint16_t)(y1 + 1);
            bool carry1_next4 = (uint16_t)(y1 + 1) >= 3;
            bool overflow1_next4 = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
            a_hi1 = a_hi1_next4;
            x1 = x1_next4;
            y1 = y1_next4;
            carry1 = carry1_next4;
            overflow1 = overflow1_next4;
            break;
        }
        r->a = y1;
        r->x = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000);
        r->y = y1;
        r->c = (value & 0xFF) >= 1;
        r->z = y1 == 0;
        r->n = y1 & 0x8000;
        r->v = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    r->a = 0xFFFF;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = 0;
    r->n = 1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2328D, SOM_RTS, "gen", find_first_active_nonnegative_party_status12, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 47, 23)
