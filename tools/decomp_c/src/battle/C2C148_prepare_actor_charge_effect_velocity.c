#include "som_c.h"

/* C2C148 prepare_actor_charge_effect_velocity   [class A, 41 bytes, 20 instructions]
 * Source: src/rom/prepare_actor_charge_effect_velocity.s
 * Documented in docs/actor-animation-special-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYV.
 */
static void prepare_actor_charge_effect_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(ACTOR_CHARGE_STAGE + x);
    RAM8(0xD00A + y) = (uint8_t)((value ^ 0xFF) + 0x0F);
    RAM8(0xD008 + y) = 0;
    uint8_t value2 = RAM8(0xD000 + y);
    uint8_t a2;
    if ((uint8_t)(value2 - 1) == 0) {
        a2 = 0x50;
    } else {
        uint8_t a1;
        if ((uint8_t)(value2 - 2) == 0) {
            a1 = 0x30;
        } else {
            a1 = 0;
        }
        a2 = a1;
    }
    RAM8(0xD009 + y) = a2;
    r->v = ((value ^ 0xFF ^ (uint8_t)((value ^ 0xFF) + 0x0F)) & ((uint8_t)((value ^ 0xFF) + 0x0F) ^ 0x0E) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C148, SOM_RTS, "gen", prepare_actor_charge_effect_velocity, 0, L_X | L_Y | L_V, 1, 1, 0, 41, 20)
