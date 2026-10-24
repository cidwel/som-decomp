#include "som_c.h"

/* C270C5 choose_descriptor_seven_horizontal_vertical_state   [class B, 75 bytes, 36 instructions]
 * Source: src/rom/choose_descriptor_seven_horizontal_vertical_state.s
 * Documented in docs/boss-descriptor-seven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_seven_horizontal_vertical_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x70C7, 0xC27303); /* select_alive_hero_nearest_on_vertical_axis */
    uint16_t x_ret = r->x;
    uint16_t value = RAM16(0x00A9 + x_ret);
    RAM16_SET(0x0297, RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)));
    uint16_t value3 = RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    RAM16_SET(0x0295, value3);
    if (!((uint16_t)(value3 - RAM16(0x002B + x_ret)) & 0x8000)) {
        uint16_t value5 = RAM16(0x0032 + x_ret);
        uint16_t value6 = RAM16(0x0297);
        RAM16_SET(0x0299, (uint16_t)(value5 - value6));
        if ((uint16_t)(value5 - value6) & 0x8000) {
            r->a = 0xEB71;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
            r->c = value5 >= value6;
            r->z = 0;
            r->n = 1;
            r->v = ((value5 ^ value6) & (value5 ^ (uint16_t)(value5 - value6)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if ((uint16_t)(value5 - value6) >= 0x20) {
            r->a = 0xEB71;
            r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
            r->c = (uint16_t)(value5 - value6) >= 0x20;
            r->z = 0;
            r->n = 1;
            r->v = ((value5 ^ value6) & (value5 ^ (uint16_t)(value5 - value6)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xEB6D;
        r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
        r->c = (uint16_t)(value5 - value6) >= 0x20;
        r->z = 0;
        r->n = 1;
        r->v = ((value5 ^ value6) & (value5 ^ (uint16_t)(value5 - value6)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value7 = RAM16(0x0032 + x_ret);
    uint16_t value8 = RAM16(0x0297);
    RAM16_SET(0x0299, (uint16_t)(value7 - value8));
    if ((uint16_t)(value7 - value8) & 0x8000) {
        r->a = 0xEB73;
        r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
        r->c = value7 >= value8;
        r->z = 0;
        r->n = 1;
        r->v = ((value7 ^ value8) & (value7 ^ (uint16_t)(value7 - value8)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if ((uint16_t)(value7 - value8) >= 0x20) {
        r->a = 0xEB73;
        r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
        r->c = (uint16_t)(value7 - value8) >= 0x20;
        r->z = 0;
        r->n = 1;
        r->v = ((value7 ^ value8) & (value7 ^ (uint16_t)(value7 - value8)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0xEB6F;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = (uint16_t)(value7 - value8) >= 0x20;
    r->z = 0;
    r->n = 1;
    r->v = ((value7 ^ value8) & (value7 ^ (uint16_t)(value7 - value8)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC270C5, SOM_RTS, "gen", choose_descriptor_seven_horizontal_vertical_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 75, 36)
