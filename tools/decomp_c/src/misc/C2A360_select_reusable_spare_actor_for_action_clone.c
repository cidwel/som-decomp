#include "som_c.h"

/* C2A360 select_reusable_spare_actor_for_action_clone   [class B, 63 bytes, 30 instructions]
 * Source: src/rom/select_reusable_spare_actor_for_action_clone.s
 * Documented in docs/actor-action-spare-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void select_reusable_spare_actor_for_action_clone(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0x00ED);
    if (!(value & 0x80)) {
        r->c = 0;
        r->v = value & 0x40;
        RETURN_RTL(c);
    }
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = 0x0A00;
    bool overflow1 = value & 0x40;
    for (;;) {
        uint8_t value2 = RAM8(0xE000 + y1);
        if (value2 == 0) {
            r->a = (a_hi1 << 8) | value2;
            r->x = x;
            r->y = y1;
            r->c = 1;
            r->v = overflow1;
            RETURN_RTL(c);
        }
        RAM16_SET(0x0000, x);
        if (y1 == RAM16(0x0000)) {
            if ((uint16_t)(y1 - 0x0200) >= 0x0600) {
                uint8_t a_hi1_next = (uint16_t)(y1 - 0x0200) >> 8;
                uint16_t y1_next = (uint16_t)(y1 - 0x0200);
                bool overflow1_next = ((y1 ^ 0x0200) & (y1 ^ (uint16_t)(y1 - 0x0200)) & 0x8000) != 0;
                a_hi1 = a_hi1_next;
                y1 = y1_next;
                overflow1 = overflow1_next;
                continue;
            }
            r->a = (uint16_t)(y1 - 0x0200);
            r->x = x;
            r->y = (uint16_t)(y1 - 0x0200);
            r->c = (uint16_t)(y1 - 0x0200) >= 0x0600;
            r->v = ((y1 ^ 0x0200) & (y1 ^ (uint16_t)(y1 - 0x0200)) & 0x8000) != 0;
            RETURN_RTL(c);
        }
        uint16_t value4 = RAM16(0xE020 + y1);
        if (value4 < 0x0120) {
            uint16_t value5 = RAM16(0xE022 + y1);
            if (value5 < 0x0100) {
                if ((uint16_t)(y1 - 0x0200) >= 0x0600) {
                    uint8_t a_hi1_next2 = (uint16_t)(y1 - 0x0200) >> 8;
                    uint16_t y1_next2 = (uint16_t)(y1 - 0x0200);
                    bool overflow1_next2 = ((y1 ^ 0x0200) & (y1 ^ (uint16_t)(y1 - 0x0200)) & 0x8000) != 0;
                    a_hi1 = a_hi1_next2;
                    y1 = y1_next2;
                    overflow1 = overflow1_next2;
                    continue;
                }
                r->a = (uint16_t)(y1 - 0x0200);
                r->x = x;
                r->y = (uint16_t)(y1 - 0x0200);
                r->c = (uint16_t)(y1 - 0x0200) >= 0x0600;
                r->v = ((y1 ^ 0x0200) & (y1 ^ (uint16_t)(y1 - 0x0200)) & 0x8000) != 0;
                RETURN_RTL(c);
            }
            if (value5 < 0xFFE0) {
                r->a = value5;
                r->x = x;
                r->y = y1;
                r->c = 1;
                r->v = overflow1;
                r->mf = 0;
                RETURN_RTL(c);
            }
            if ((uint16_t)(y1 - 0x0200) >= 0x0600) {
                uint8_t a_hi1_next3 = (uint16_t)(y1 - 0x0200) >> 8;
                uint16_t y1_next3 = (uint16_t)(y1 - 0x0200);
                bool overflow1_next3 = ((y1 ^ 0x0200) & (y1 ^ (uint16_t)(y1 - 0x0200)) & 0x8000) != 0;
                a_hi1 = a_hi1_next3;
                y1 = y1_next3;
                overflow1 = overflow1_next3;
                continue;
            }
            r->a = (uint16_t)(y1 - 0x0200);
            r->x = x;
            r->y = (uint16_t)(y1 - 0x0200);
            r->c = (uint16_t)(y1 - 0x0200) >= 0x0600;
            r->v = ((y1 ^ 0x0200) & (y1 ^ (uint16_t)(y1 - 0x0200)) & 0x8000) != 0;
            RETURN_RTL(c);
        }
        if (value4 < 0xFFE0) {
            r->a = value4;
            r->x = x;
            r->y = y1;
            r->c = 1;
            r->v = overflow1;
            r->mf = 0;
            RETURN_RTL(c);
        }
        uint16_t value6 = RAM16(0xE022 + y1);
        if (value6 < 0x0100) {
            if ((uint16_t)(y1 - 0x0200) >= 0x0600) {
                uint8_t a_hi1_next4 = (uint16_t)(y1 - 0x0200) >> 8;
                uint16_t y1_next4 = (uint16_t)(y1 - 0x0200);
                bool overflow1_next4 = ((y1 ^ 0x0200) & (y1 ^ (uint16_t)(y1 - 0x0200)) & 0x8000) != 0;
                a_hi1 = a_hi1_next4;
                y1 = y1_next4;
                overflow1 = overflow1_next4;
                continue;
            }
            r->a = (uint16_t)(y1 - 0x0200);
            r->x = x;
            r->y = (uint16_t)(y1 - 0x0200);
            r->c = (uint16_t)(y1 - 0x0200) >= 0x0600;
            r->v = ((y1 ^ 0x0200) & (y1 ^ (uint16_t)(y1 - 0x0200)) & 0x8000) != 0;
            RETURN_RTL(c);
        }
        if (value6 < 0xFFE0) {
            r->a = value6;
            r->x = x;
            r->y = y1;
            r->c = 1;
            r->v = overflow1;
            r->mf = 0;
            RETURN_RTL(c);
        }
        if ((uint16_t)(y1 - 0x0200) >= 0x0600) {
            uint8_t a_hi1_next5 = (uint16_t)(y1 - 0x0200) >> 8;
            uint16_t y1_next5 = (uint16_t)(y1 - 0x0200);
            bool overflow1_next5 = ((y1 ^ 0x0200) & (y1 ^ (uint16_t)(y1 - 0x0200)) & 0x8000) != 0;
            a_hi1 = a_hi1_next5;
            y1 = y1_next5;
            overflow1 = overflow1_next5;
            continue;
        }
        r->a = (uint16_t)(y1 - 0x0200);
        r->x = x;
        r->y = (uint16_t)(y1 - 0x0200);
        r->c = (uint16_t)(y1 - 0x0200) >= 0x0600;
        r->v = ((y1 ^ 0x0200) & (y1 ^ (uint16_t)(y1 - 0x0200)) & 0x8000) != 0;
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0xC2A360, SOM_RTL, "gen", select_reusable_spare_actor_for_action_clone, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 63, 30)
