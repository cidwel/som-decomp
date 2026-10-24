#include "som_c.h"

/* C8E2CB actor_selected_effect_hp_or_damage_and_message   [class B, 43 bytes, 18 instructions]
 * Source: src/rom/actor_selected_effect_hp_or_damage_and_message.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void actor_selected_effect_hp_or_damage_and_message(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    r->x = battle_defender_ptr;
    r->z = battle_defender_ptr == 0;
    r->n = battle_defender_ptr & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE2D0, 0xC0389C); GUARD_JSL(c, sp_call, 0xE2D0); } /* random_byte_long_wrapper */
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (((uint8_t)a_all & 7) != 0) {
        RAM8(ACTOR_HP + x_ret2) = 1;
        RAM8(0xE183 + x_ret2) = 0;
        uint8_t value = RAM8(0x0380);
        RAM8(0x0380) = value | 0x40;
        r->a = (a_all >> 8 << 8) | (value | 0x40);
        r->z = (value | 0x40) == 0;
        r->n = (value | 0x40) & 0x80;
        { const uint16_t sp_call = r->sp; JSL(c, 0xE2F4, 0xC05BC0); GUARD_JSL(c, sp_call, 0xE2F4); } /* queue_selected_effect_hp_message */
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    uint16_t value2 = RAM16(ACTOR_HP + x_ret2);
    RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x_ret2, value2);
    RAM16_SET(ACTOR_PENDING_HP_HEAL + x_ret2, 0);
    r->a = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E2CB, SOM_RTS, "gen", actor_selected_effect_hp_or_damage_and_message, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 43, 18)
