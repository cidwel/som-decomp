#include "som_c.h"

/* C01F18 select_native_menu_actor_sprite_span   [class A, 30 bytes, 15 instructions]
 * Source: src/rom/select_native_menu_actor_sprite_span.s
 * Documented in docs/event-menu-controller.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void select_native_menu_actor_sprite_span(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0xA212);
    uint8_t a1;
    if ((value & 0x20) == 0) {
        a1 = RAM8(0x19FE);
    } else {
        a1 = 3;
    }
    uint8_t value3 = BUS8(c, 0xC02A58 + ((a_hi << 8) | (uint8_t)(a1 << 1)));
    uint8_t value4 = BUS8(c, 0xC02A59 + ((a_hi << 8) | (uint8_t)(a1 << 1)));
    r->x = (a_hi << 8) | value3;
    r->y = (a_hi << 8) | value4;
    r->c = a1 & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01F18, SOM_RTS, "gen", select_native_menu_actor_sprite_span, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 30, 15)
