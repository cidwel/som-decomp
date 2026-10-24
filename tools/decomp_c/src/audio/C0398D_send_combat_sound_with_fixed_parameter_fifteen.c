#include "som_c.h"

/* C0398D send_combat_sound_with_fixed_parameter_fifteen   [class A, 23 bytes, 9 instructions]
 * Source: src/rom/send_combat_sound_with_fixed_parameter_fifteen.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void send_combat_sound_with_fixed_parameter_fifteen(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x1E01) = a;
    RAM8(0x1E00) = 2;
    RAM8(0x1E02) = 0x0F;
    RAM8(0x1E03) = 0;
    r->a = (a_hi << 8) | 0;
    r->z = 1;
    r->n = 0;
    JSL(c, 0x39A2, 0xC30004); /* audio_command_sender_public_jump */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0398D, SOM_RTS, "gen", send_combat_sound_with_fixed_parameter_fifteen, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 23, 9)
