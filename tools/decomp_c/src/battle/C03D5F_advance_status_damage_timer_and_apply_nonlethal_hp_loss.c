#include "som_c.h"

/* C03D5F advance_status_damage_timer_and_apply_nonlethal_hp_loss   [class B, 50 bytes, 23 instructions]
 * Source: src/rom/advance_status_damage_timer_and_apply_nonlethal_hp_loss.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void advance_status_damage_timer_and_apply_nonlethal_hp_loss(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if ((RAM8(ACTOR_STATUS_HIGH + x) & 0x60) == 0) {
        RETURN_RTS(c);
    }
    RAM8(ACTOR_STATUS_DAMAGE_TIMER + x)--;
    if (RAM8(ACTOR_STATUS_DAMAGE_TIMER + x) == 0) {
        RAM8(ACTOR_STATUS_HIGH + x) &= 0x9F;
        RETURN_RTS(c);
    }
    RAM8(0x0380) |= 0x40;
    uint16_t value4 = RAM16(ACTOR_HP + x);
    if (value4 == 0) {
        RAM8(ACTOR_STATUS_HIGH + x) &= 0x9F;
        r->a = (r->a & 0x00FF) | ((value4 >> 8) << 8);
        RETURN_RTS(c);
    }
    if ((uint16_t)(value4 - 1) == 0) {
        RAM8(ACTOR_STATUS_HIGH + x) &= 0x9F;
        r->a = (r->a & 0x00FF) | (((uint16_t)(value4 - 1) >> 8) << 8);
        RETURN_RTS(c);
    }
    RAM16_SET(ACTOR_HP + x, (uint16_t)(value4 - 1));
    r->a = ((uint16_t)(value4 - 1) >> 8 << 8) | 0x39;
    JSR(c, 0x3D84, 0xC0398D); /* send_combat_sound_with_fixed_parameter_fifteen */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03D5F, SOM_RTS, "gen", advance_status_damage_timer_and_apply_nonlethal_hp_loss, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 50, 23)
