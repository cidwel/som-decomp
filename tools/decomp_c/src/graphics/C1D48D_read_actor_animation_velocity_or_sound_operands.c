#include "som_c.h"

/* C1D48D read_actor_animation_velocity_or_sound_operands   [class B, 118 bytes, 57 instructions]
 * Source: src/rom/read_actor_animation_velocity_or_sound_operands.s
 * Documented in docs/actor-animation-operands.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void read_actor_animation_velocity_or_sound_operands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    uint16_t value;
    BUS16_OK(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000) + 1, value);
    RAM16_SET(0x000C, value);
    uint16_t value2;
    BUS16_OK(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000) + 2, value2);
    RAM16_SET(0x000D, value2);
    uint16_t value3 = RAM16(0x0000);
    RAM16_SET(0x0000, (uint16_t)(value3 + 4));
    if (a != 0xF8) {
        if (a != 0xF9) {
            r->a = (r->a & 0x00FF) | (((uint16_t)(value3 + 4) >> 8) << 8);
            r->y = 2;
            r->v = ((value3 ^ (uint16_t)(value3 + 4)) & ((uint16_t)(value3 + 4) ^ 4) & 0x8000) != 0;
            RETURN_RTL(c);
        }
        RAM8(0x1E00) = 2;
        RAM8(0x1E01) = RAM8(0x000C);
        uint8_t value5 = RAM8(0x000D);
        RAM8(0x1E02) = value5;
        r->a = ((uint16_t)(value3 + 4) >> 8 << 8) | value5;
        r->y = 2;
        r->z = value5 == 0;
        r->v = ((value3 ^ (uint16_t)(value3 + 4)) & ((uint16_t)(value3 + 4) ^ 4) & 0x8000) != 0;
        JSR(c, 0xD4F3, 0xC1D503); /* derive_actor_animation_sound_volume */
        uint16_t a_all = r->a;
        RAM8(0x1E03) = (uint8_t)a_all;
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) - 1));
        uint16_t value6 = RAM16(0x0000);
        r->z = value6 == 0;
        r->n = value6 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        JSL(c, 0xD500, 0xC30004); /* audio_command_sender_public_jump */
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    RAM8(0xE008 + x) = RAM8(0x000E);
    RAM8(0x000F) = RAM8(0xE010 + x) & 0x80;
    uint8_t value9 = RAM8(0x000D);
    uint8_t a1;
    if (!(value9 & 0x80)) {
        a1 = value9;
    } else {
        a1 = (uint8_t)((value9 ^ 0x7F) + 1) | 0x80;
    }
    uint8_t value10 = RAM8(0x000F);
    uint8_t a2;
    if ((a1 ^ value10) != 0x80) {
        a2 = a1 ^ value10;
    } else {
        a2 = 0;
    }
    RAM8(0xE006 + x) = a2;
    uint8_t value11 = RAM8(0x000C);
    uint8_t a3;
    if (!(value11 & 0x80)) {
        a3 = value11;
    } else {
        a3 = (uint8_t)((value11 ^ 0xFF) + 1) | 0x80;
    }
    uint8_t a4;
    if (a3 != 0x80) {
        a4 = a3;
    } else {
        a4 = 0;
    }
    RAM8(0xE007 + x) = a4;
    r->a = (r->a & 0x00FF) | (((uint16_t)(value3 + 4) >> 8) << 8);
    r->y = 2;
    r->v = ((value3 ^ (uint16_t)(value3 + 4)) & ((uint16_t)(value3 + 4) ^ 4) & 0x8000) != 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1D48D, SOM_RTL, "hand", read_actor_animation_velocity_or_sound_operands, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 118, 57)
