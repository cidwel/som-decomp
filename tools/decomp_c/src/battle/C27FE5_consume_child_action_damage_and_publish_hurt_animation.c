#include "som_c.h"

/* C27FE5 consume_child_action_damage_and_publish_hurt_animation   [class B, 36 bytes, 15 instructions]
 * Source: src/rom/consume_child_action_damage_and_publish_hurt_animation.s
 * Documented in docs/boss-native58-left-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYC.
 */
static void consume_child_action_damage_and_publish_hurt_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    JSR(c, 0x7FE7, 0xC2051C); /* consume_boss_byte35_request */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7FEA, 0xC20501); /* consume_boss_byte34_bit0_or_return_negative_status */
    bool carry_ret2 = r->c;
    uint16_t x1;
    bool carry1;
    if (!carry_ret2) {
        x1 = x;
        carry1 = carry_ret2;
    } else {
        uint16_t value = RAM16(0x0287);
        RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
        r->a = 0x012E;
        r->x = value;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x7FF7, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        RAM16_SET(OBJECT_AGE + value, 0);
        RAM8(0x0380) &= 0x7F;
        x1 = value;
        carry1 = 1;
    }
    r->x = x1;
    r->c = carry1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27FE5, SOM_RTS, "gen", consume_child_action_damage_and_publish_hurt_animation, 0, L_X | L_Y | L_C, 1, 0, 0, 36, 15)
