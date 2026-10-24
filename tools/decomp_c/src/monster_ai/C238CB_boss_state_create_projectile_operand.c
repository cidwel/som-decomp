#include "som_c.h"

/* C238CB boss_state_create_projectile_operand   [class B, 68 bytes, 35 instructions]
 * Source: src/rom/boss_state_create_projectile_operand.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void boss_state_create_projectile_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    uint16_t current_object_dp0 = RAM16(CURRENT_OBJECT_DP0 + dp);
    RAM8(OBJECT_AGE + dp) = 0;
    RAM8(0x0098 + dp) = 0;
    RAM8(0x009A + dp) = 0;
    uint8_t value;
    BUS8_PTR(c, (RAM8(0x0032 + dp) << 0x10) + RAM16(0x0030 + dp) + y, RAM8(0x0032 + dp), value);
    RAM8(0x0099 + dp) = value;
    uint8_t value2;
    BUS8_PTR(c, (RAM8(0x0032 + dp) << 0x10) + RAM16(0x0030 + dp) + (uint16_t)(y + 1), RAM8(0x0032 + dp), value2);
    RAM8(0x0095 + dp) = value2;
    if (value2 & 0x80) {
        RAM8(OBJECT_AGE + dp) = 0xFF;
    }
    uint8_t value3;
    BUS8_PTR(c, (RAM8(0x0032 + dp) << 0x10) + RAM16(0x0030 + dp) + (uint16_t)(y + 2), RAM8(0x0032 + dp), value3);
    RAM8(0x0097 + dp) = value3;
    if (value3 & 0x80) {
        RAM8(0x0098 + dp) = 0xFF;
    }
    uint16_t value4 = RAM16(0x00A9 + current_object_dp0);
    uint16_t value5 = RAM16(0x0098 + current_object_dp0);
    uint8_t a_hi1;
    if ((value5 & 0x40) == 0) {
        a_hi1 = value5 >> 8;
    } else {
        uint16_t value6 = RAM16(0x0095 + dp);
        RAM16_SET(0x0095 + dp, (uint16_t)((value6 ^ 0xFFFF) + 1));
        a_hi1 = (uint16_t)((value6 ^ 0xFFFF) + 1) >> 8;
    }
    r->a = RAM16(0x0099 + dp);
    r->x = current_object_dp0;
    r->y = value4;
    r->mf = 0;
    r->sp -= 2;
    JSR(c, 0x390A, 0xC233BE); /* create_boss_projectile_with_graphics_and_palette */
    r->sp += 2;
    uint16_t current_object_dp02 = RAM16(CURRENT_OBJECT_DP0 + dp);
    r->x = current_object_dp02;
    r->y = (uint16_t)(y + 3);
    r->z = current_object_dp02 == 0;
    r->n = current_object_dp02 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC238CB, SOM_RTS, "hand", boss_state_create_projectile_operand, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 68, 35)
