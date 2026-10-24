#include "som_c.h"

/* C0E382 advance_actor_sprite_visibility_timer   [class A, 12 bytes, 8 instructions]
 * Source: src/rom/advance_actor_sprite_visibility_timer.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void advance_actor_sprite_visibility_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    RAM8(0xE00F + x) = (uint8_t)(a - 2);
    if ((uint8_t)(a - 2) & 0x80) {
        SET_A8(r, (uint8_t)(a - 2));
        r->c = 0;
        RETURN_RTS(c);
    }
    SET_A8(r, (uint8_t)(a - 2));
    r->c = (uint8_t)(a - 2) >= 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0E382, SOM_RTS, "gen", advance_actor_sprite_visibility_timer, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 12, 8)
