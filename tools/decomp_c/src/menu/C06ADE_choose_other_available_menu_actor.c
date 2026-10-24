#include "som_c.h"

/* C06ADE choose_other_available_menu_actor   [class B, 37 bytes, 18 instructions]
 * Source: src/rom/choose_other_available_menu_actor.s
 * Documented in docs/event-menu-actor-cycle.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: Y.
 */
static void choose_other_available_menu_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    RAM8(0x1820) = x;
    uint8_t value = RAM8(0x1820);
    if (y != value) {
        uint8_t value2 = RAM8(0x1877);
        r->a = (a_hi << 8) | value2;
        r->x = (uint8_t)((a_hi << 8) | value2);
        r->c = y >= value;
        JSR(c, 0x6AF1, 0xC06B0A); /* test_available_living_menu_actor_mask */
        uint16_t a_all = r->a;
        uint8_t x_ret = r->x;
        uint8_t y_ret = r->y;
        bool zero_ret = r->z;
        uint8_t a2;
        uint8_t a_hi1;
        uint8_t y1;
        if (!zero_ret) {
            a2 = (uint8_t)a_all;
            a_hi1 = a_all >> 8;
            y1 = y_ret;
        } else {
            r->x = (uint8_t)(x_ret + 1);
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0x6AF7, 0xC06B0A); /* test_available_living_menu_actor_mask */
            uint16_t a_all2 = r->a;
            uint8_t x_ret2 = r->x;
            uint8_t y_ret2 = r->y;
            bool zero_ret2 = r->z;
            uint8_t a1;
            if (!zero_ret2) {
                a1 = (uint8_t)a_all2;
            } else {
                uint8_t value3 = BUS8(c, 0xC06B47 + x_ret2);
                a1 = value3;
            }
            a2 = a1;
            a_hi1 = a_all2 >> 8;
            y1 = y_ret2;
        }
        RAM8(RING_OWNER) = a2 >> 1;
        r->y = y1;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06ADE, SOM_RTS, "gen", choose_other_available_menu_actor, 0, L_Y, 1, 1, 1, 37, 18)
