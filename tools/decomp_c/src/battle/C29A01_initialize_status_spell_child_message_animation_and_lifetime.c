#include "som_c.h"

/* C29A01 initialize_status_spell_child_message_animation_and_lifetime   [class B, 42 bytes, 17 instructions]
 * Source: src/rom/initialize_status_spell_child_message_animation_and_lifetime.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_status_spell_child_message_animation_and_lifetime(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value2 = RAM16(0x00B4 + RAM16(0x0287));
    r->a = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    JSL(c, 0x9A09, 0xC00027); /* boss_attack_notice_public_jump */
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x00B4 + value3);
    uint16_t value5 = BUS16(c, 0xDCE6FF + (uint16_t)(value4 << 1));
    r->a = value5;
    r->x = value3;
    r->c = value4 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A19, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A1C, 0xC29A2B); /* request_status_spell_start_sound */
    uint16_t x_ret2 = r->x;
    RAM16_SET(OBJECT_PHASE + x_ret2, (uint16_t)(RAM16(OBJECT_PHASE + x_ret2) + 1));
    RAM16_SET(0x0022 + x_ret2, 0x07FF);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A28, 0xC298DA); /* activate_spell_child_and_clear_fractional_height */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29A01, SOM_RTS, "gen", initialize_status_spell_child_message_animation_and_lifetime, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 42, 17)
