#include "som_c.h"

/* C04157 send_actor_impact_sound_with_facing_volume   [class A, 32 bytes, 13 instructions]
 * Source: src/rom/send_actor_impact_sound_with_facing_volume.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void send_actor_impact_sound_with_facing_volume(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM8(0x1E00) = 2;
    RAM8(0x1E01) = RAM8(ACTOR_HIT_SOUND + x);
    RAM8(0x1E02) = 0x0F;
    uint8_t value2 = RAM8(0xE020 + x);
    uint8_t a1;
    bool zero1;
    bool negative1;
    if ((value2 & 0xF0) != 0) {
        a1 = value2 & 0xF0;
        zero1 = (value2 & 0xF0) == 0;
        negative1 = value2 & 0xF0 & 0x80;
    } else {
        a1 = (uint8_t)((value2 & 0xF0) + 1);
        zero1 = (uint8_t)((value2 & 0xF0) + 1) == 0;
        negative1 = (uint8_t)((value2 & 0xF0) + 1) & 0x80;
    }
    RAM8(0x1E03) = a1;
    r->a = (a_hi << 8) | a1;
    r->z = zero1;
    r->n = negative1;
    JSL(c, 0x4175, 0xC30004); /* audio_command_sender_public_jump */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04157, SOM_RTS, "gen", send_actor_impact_sound_with_facing_volume, 0, L_X | L_Y, 1, 1, 0, 32, 13)
