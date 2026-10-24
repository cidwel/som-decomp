#include "som_c.h"

/* C0D1FE dispatch_live_map_actor_motion_pool   [class B, 43 bytes, 23 instructions]
 * Source: src/rom/dispatch_live_map_actor_motion_pool.s
 * Documented in docs/map-actor-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void dispatch_live_map_actor_motion_pool(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t value = RAM8(0x005C);
    if (!(value & 0x80)) {
        uint8_t a1 = a;
        uint8_t a_hi1 = a_hi;
        uint16_t x1 = 0x0600;
        uint16_t y1 = y;
        bool carry1 = carry;
        bool overflow1 = value & 0x40;
        for (;;) {
            r->x = x1;
            r->y = y1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 2;
            JSR(c, 0xD20D, 0xC0D229); /* move_live_map_actor_through_ground_effect_and_terrain */
            r->sp += 2;
            uint16_t y_ret = r->y;
            uint8_t value2 = RAM8(0x00ED);
            if (value2 & 0x80) {
                if ((uint16_t)(x1 + 0x0200) < 0x0C00) {
                    uint8_t a1_next = (uint8_t)(x1 + 0x0200);
                    uint8_t a_hi1_next = (uint16_t)(x1 + 0x0200) >> 8;
                    uint16_t x1_next = (uint16_t)(x1 + 0x0200);
                    uint16_t y1_next = y_ret;
                    bool carry1_next = (uint16_t)(x1 + 0x0200) >= 0x0C00;
                    bool overflow1_next = value2 & 0x40;
                    a1 = a1_next;
                    a_hi1 = a_hi1_next;
                    x1 = x1_next;
                    y1 = y1_next;
                    carry1 = carry1_next;
                    overflow1 = overflow1_next;
                    continue;
                }
                uint8_t a1_next3 = (uint8_t)(x1 + 0x0200);
                uint8_t a_hi1_next3 = (uint16_t)(x1 + 0x0200) >> 8;
                uint16_t x1_next3 = (uint16_t)(x1 + 0x0200);
                uint16_t y1_next3 = y_ret;
                bool carry1_next3 = (uint16_t)(x1 + 0x0200) >= 0x0C00;
                bool overflow1_next3 = value2 & 0x40;
                a1 = a1_next3;
                a_hi1 = a_hi1_next3;
                x1 = x1_next3;
                y1 = y1_next3;
                carry1 = carry1_next3;
                overflow1 = overflow1_next3;
                break;
            }
            if ((uint16_t)(x1 + 0x0200) < 0x1800) {
                uint8_t a1_next2 = (uint8_t)(x1 + 0x0200);
                uint8_t a_hi1_next2 = (uint16_t)(x1 + 0x0200) >> 8;
                uint16_t x1_next2 = (uint16_t)(x1 + 0x0200);
                uint16_t y1_next2 = y_ret;
                bool carry1_next2 = (uint16_t)(x1 + 0x0200) >= 0x1800;
                bool overflow1_next2 = value2 & 0x40;
                a1 = a1_next2;
                a_hi1 = a_hi1_next2;
                x1 = x1_next2;
                y1 = y1_next2;
                carry1 = carry1_next2;
                overflow1 = overflow1_next2;
                continue;
            }
            r->a = (uint16_t)(x1 + 0x0200);
            r->x = (uint16_t)(x1 + 0x0200);
            r->c = (uint16_t)(x1 + 0x0200) >= 0x1800;
            r->v = value2 & 0x40;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        RETURN_RTS(c);
    }
    r->v = value & 0x40;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0D1FE, SOM_RTS, "gen", dispatch_live_map_actor_motion_pool, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 43, 23)
