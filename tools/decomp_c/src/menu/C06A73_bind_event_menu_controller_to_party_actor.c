#include "som_c.h"

/* C06A73 bind_event_menu_controller_to_party_actor   [class A, 50 bytes, 30 instructions]
 * Source: src/rom/bind_event_menu_controller_to_party_actor.s
 * Documented in docs/event-menu-actor-selection.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: Y.
 */
static void bind_event_menu_controller_to_party_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    uint8_t value = RAM8(0x00D9);
    uint8_t x2;
    if ((value & 7) == a) {
        x2 = 1;
    } else {
        uint8_t value2 = RAM8(0x00DA);
        uint8_t x1;
        if ((value2 & 7) == a) {
            x1 = 2;
        } else {
            x1 = 4;
        }
        x2 = x1;
    }
    RAM8(0x1802) = (RAM8(0x1802) & 0x1F) | (uint8_t)(x2 << 5);
    RAM8(0x1836) = x2 >> 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06A73, SOM_RTS, "gen", bind_event_menu_controller_to_party_actor, 0, L_Y, 1, 1, 1, 50, 30)
