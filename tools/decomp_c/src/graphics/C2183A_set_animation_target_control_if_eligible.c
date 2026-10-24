#include "som_c.h"

/* C2183A set_animation_target_control_if_eligible   [class B, 50 bytes, 26 instructions]
 * Source: src/rom/set_animation_target_control_if_eligible.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void set_animation_target_control_if_eligible(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00A9 + value);
    uint16_t value3 = RAM16(0x0190 + (uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000));
    if ((value3 & 0xC568) != 0) {
        r->a = value3 & 0xC568;
        r->x = value;
        r->y = (uint16_t)(y + 1);
        r->c = (uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
        r->z = value == 0;
        r->n = value & 0x8000;
        r->v = (((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value4 = RAM16(0x0060 + (uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000));
    if ((value4 & 0xFF) != 0) {
        r->a = value4 & 0xFF;
        r->x = value;
        r->y = (uint16_t)(y + 1);
        r->c = (uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
        r->z = value == 0;
        r->n = value & 0x8000;
        r->v = (((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value5;
    BUS16_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y, value5);
    RAM8(0x01E5 + (uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000)) = (uint8_t)value5;
    uint16_t value6 = RAM16(0x0287);
    r->a = value5;
    r->x = value6;
    r->y = (uint16_t)(y + 1);
    r->c = (uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
    r->z = value6 == 0;
    r->n = value6 & 0x8000;
    r->v = (((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((value2 & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2183A, SOM_RTS, "hand", set_animation_target_control_if_eligible, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 50, 26)
