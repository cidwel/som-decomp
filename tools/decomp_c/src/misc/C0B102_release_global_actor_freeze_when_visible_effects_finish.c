#include "som_c.h"

/* C0B102 release_global_actor_freeze_when_visible_effects_finish   [class B, 52 bytes, 25 instructions]
 * Source: src/rom/release_global_actor_freeze_when_visible_effects_finish.s
 * Documented in docs/actor-freeze-attack-gates.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: BXYCV.
 */
static void release_global_actor_freeze_when_visible_effects_finish(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x00F1);
    if (value & 0x40) {
        uint8_t value2 = RAM8(0x00ED);
        uint16_t x1;
        if (value2 & 0x80) {
            x1 = 0x0A00;
        } else {
            x1 = 0x0400;
        }
        uint8_t a_hi1 = a_hi;
        uint16_t x2 = x1;
        bool overflow1 = value2 & 0x40;
        for (;;) {
            uint8_t value3 = RAM8(0xE000 + x2);
            if (value3 == 0) {
                if (!((uint16_t)(x2 - 0x0200) & 0x8000)) {
                    uint8_t a_hi1_next = (uint16_t)(x2 - 0x0200) >> 8;
                    uint16_t x2_next = (uint16_t)(x2 - 0x0200);
                    bool overflow1_next = ((x2 ^ 0x0200) & (x2 ^ (uint16_t)(x2 - 0x0200)) & 0x8000) != 0;
                    a_hi1 = a_hi1_next;
                    x2 = x2_next;
                    overflow1 = overflow1_next;
                    continue;
                }
                RAM8(0x00F1) &= 0xBF;
                r->a = ((uint16_t)(x2 - 0x0200) >> 8 << 8) | 0x40;
                r->x = (uint16_t)(x2 - 0x0200);
                r->y = y;
                r->c = x2 >= 0x0200;
                r->v = ((x2 ^ 0x0200) & (x2 ^ (uint16_t)(x2 - 0x0200)) & 0x8000) != 0;
                RETURN_RTS(c);
            }
            if (value3 & 0x80) {
                if (!((uint16_t)(x2 - 0x0200) & 0x8000)) {
                    uint8_t a_hi1_next2 = (uint16_t)(x2 - 0x0200) >> 8;
                    uint16_t x2_next2 = (uint16_t)(x2 - 0x0200);
                    bool overflow1_next2 = ((x2 ^ 0x0200) & (x2 ^ (uint16_t)(x2 - 0x0200)) & 0x8000) != 0;
                    a_hi1 = a_hi1_next2;
                    x2 = x2_next2;
                    overflow1 = overflow1_next2;
                    continue;
                }
                RAM8(0x00F1) &= 0xBF;
                r->a = ((uint16_t)(x2 - 0x0200) >> 8 << 8) | 0x40;
                r->x = (uint16_t)(x2 - 0x0200);
                r->y = y;
                r->c = x2 >= 0x0200;
                r->v = ((x2 ^ 0x0200) & (x2 ^ (uint16_t)(x2 - 0x0200)) & 0x8000) != 0;
                RETURN_RTS(c);
            }
            uint8_t value6 = RAM8(0xE060 + x2);
            if (value6 >= 0xC0) {
                r->a = (a_hi1 << 8) | value6;
                r->x = x2;
                r->y = y;
                r->c = value6 >= 0xC0;
                r->v = overflow1;
                RETURN_RTS(c);
            }
            if (!((uint16_t)(x2 - 0x0200) & 0x8000)) {
                uint8_t a_hi1_next3 = (uint16_t)(x2 - 0x0200) >> 8;
                uint16_t x2_next3 = (uint16_t)(x2 - 0x0200);
                bool overflow1_next3 = ((x2 ^ 0x0200) & (x2 ^ (uint16_t)(x2 - 0x0200)) & 0x8000) != 0;
                a_hi1 = a_hi1_next3;
                x2 = x2_next3;
                overflow1 = overflow1_next3;
                continue;
            }
            RAM8(0x00F1) &= 0xBF;
            r->a = ((uint16_t)(x2 - 0x0200) >> 8 << 8) | 0x40;
            r->x = (uint16_t)(x2 - 0x0200);
            r->y = y;
            r->c = x2 >= 0x0200;
            r->v = ((x2 ^ 0x0200) & (x2 ^ (uint16_t)(x2 - 0x0200)) & 0x8000) != 0;
            RETURN_RTS(c);
        }
    }
    r->v = value & 0x40;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0B102, SOM_RTS, "gen", release_global_actor_freeze_when_visible_effects_finish, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 52, 25)
