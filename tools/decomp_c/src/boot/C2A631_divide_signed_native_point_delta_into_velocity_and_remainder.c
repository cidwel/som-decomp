#include "som_c.h"

/* C2A631 divide_signed_native_point_delta_into_velocity_and_remainder   [class B, 104 bytes, 51 instructions]
 * Source: src/rom/divide_signed_native_point_delta_into_velocity_and_remainder.s
 * Documented in docs/actor-visual-effect-point-producer.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void divide_signed_native_point_delta_into_velocity_and_remainder(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x0000);
    RAM8(0x0000) = (uint8_t)((uint8_t)a - value);
    uint8_t a1;
    if (!((uint8_t)((uint8_t)a - value) & 0x80)) {
        a1 = (uint8_t)((uint8_t)a - value);
    } else {
        a1 = (uint8_t)(((uint8_t)((uint8_t)a - value) ^ 0xFF) + 1);
    }
    BUS8_SET(c, 0x004204, a1);
    BUS8_SET(c, 0x004205, 0);
    uint8_t value2 = RAM8(0x0008);
    BUS8_SET(c, 0x004206, value2);
    uint8_t value3 = RAM8(0x0001);
    RAM8(0x0001) = (uint8_t)((a >> 8) - value3);
    uint8_t a2;
    if (!((uint8_t)((a >> 8) - value3) & 0x80)) {
        a2 = (uint8_t)((a >> 8) - value3);
    } else {
        a2 = (uint8_t)(((uint8_t)((a >> 8) - value3) ^ 0xFF) + 1);
    }
    uint8_t value4 = BUS8(c, 0x004214);
    RAM8(0x0004) = value4;
    uint8_t value5 = BUS8(c, 0x004216);
    RAM8(0x0002) = value5;
    BUS8_SET(c, 0x004204, a2);
    BUS8_SET(c, 0x004205, 0);
    BUS8_SET(c, 0x004206, value2);
    uint8_t value6 = RAM8(0x0004);
    uint8_t value7 = RAM8(0x0000);
    uint8_t a3;
    if (!(value7 & 0x80)) {
        a3 = value6;
    } else {
        a3 = (uint8_t)((value6 ^ 0xFF) + 1);
    }
    uint8_t value8 = BUS8(c, 0x004216);
    RAM8(0x0003) = value8;
    uint8_t value9 = BUS8(c, 0x004214);
    uint8_t value10 = RAM8(0x0001);
    uint8_t a4;
    if (!(value10 & 0x80)) {
        a4 = value9;
    } else {
        a4 = (uint8_t)((value9 ^ 0xFF) + 1);
    }
    r->a = (a4 << 8) | a3;
    r->c = a >> 8 >= value3;
    r->v = value10 & 0x40;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A631, SOM_RTS, "gen", divide_signed_native_point_delta_into_velocity_and_remainder, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 104, 51)
