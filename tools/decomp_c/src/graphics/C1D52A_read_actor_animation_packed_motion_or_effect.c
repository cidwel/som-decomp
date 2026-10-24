#include "som_c.h"

/* C1D52A read_actor_animation_packed_motion_or_effect   [class D, 150 bytes, 76 instructions]
 * Source: src/rom/read_actor_animation_packed_motion_or_effect.s
 * Documented in docs/actor-animation-operands.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void read_actor_animation_packed_motion_or_effect(SomCtx *c)
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
    uint16_t value2 = RAM16(0x0000);
    RAM16_SET(0x0000, (uint16_t)(value2 + 3));
    if (a != 0xF0) {
        if (a != 0xF1) {
            BUS8_SET(c, 0x00212D, RAM8(0x0022) & 0xF8);
            uint8_t value4 = RAM8(0x000D);
            BUS8_SET(c, 0x002131, (value4 & 0x80) | 0x23);
            BUS8_SET(c, 0x002132, RAM8(0x000C));
            RAM8(0x105A) = (value4 & 0x7F) + 1;
            RAM8(0x00E2) |= 0x10;
            r->a = (r->a & 0x00FF) | (((uint16_t)(value2 + 3) >> 8) << 8);
            r->y = 1;
            RETURN_RTL(c);
        }
        RAM8(0xE05D + x)++;
        RAM16_SET(0xE05E + x, RAM16(0x0000));
        uint16_t value8 = RAM16(0x000C);
        RAM16_SET(0x0000, value8);
        r->a = value8;
        r->y = 1;
        r->mf = 0;
        RETURN_RTL(c);
    }
    uint8_t value9 = RAM8(0x000D);
    uint8_t a1;
    if ((value9 & 0x0F) < 8) {
        a1 = value9 & 0x0F;
    } else {
        a1 = (uint8_t)(((value9 & 0x0F) ^ 0xF7) + 1);
    }
    RAM8(0xE008 + x) = a1;
    RAM8(0x000F) = RAM8(0xE010 + x) & 0x80;
    uint8_t value11 = RAM8(0x000C);
    uint8_t a2;
    if ((value11 & 0x0F) < 8) {
        a2 = value11 & 0x0F;
    } else {
        a2 = (uint8_t)(((value11 & 0x0F) ^ 0x87) + 1) & 0x87;
    }
    uint8_t value12 = RAM8(0x000F);
    uint8_t a3;
    if ((a2 ^ value12) != 0x80) {
        a3 = a2 ^ value12;
    } else {
        a3 = 0;
    }
    RAM8(0xE006 + x) = a3;
    uint8_t value13 = RAM8(0x000C);
    uint8_t a4;
    if (value13 >> 4 < 8) {
        a4 = value13 >> 4;
    } else {
        a4 = (uint8_t)(((value13 >> 4) ^ 0x87) + 1) & 0x87;
    }
    uint8_t a5;
    if (a4 != 0x80) {
        a5 = a4;
    } else {
        a5 = 0;
    }
    RAM8(0xE007 + x) = a5;
    r->a = (r->a & 0x00FF) | (((uint16_t)(value2 + 3) >> 8) << 8);
    r->y = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1D52A, SOM_RTL, "hand", read_actor_animation_packed_motion_or_effect, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 150, 76)
