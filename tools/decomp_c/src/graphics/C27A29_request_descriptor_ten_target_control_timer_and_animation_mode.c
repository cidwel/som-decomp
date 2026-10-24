#include "som_c.h"

/* C27A29 request_descriptor_ten_target_control_timer_and_animation_mode   [class B, 45 bytes, 21 instructions]
 * Source: src/rom/request_descriptor_ten_target_control_timer_and_animation_mode.s
 * Documented in docs/boss-descriptor-ten-target-control.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void request_descriptor_ten_target_control_timer_and_animation_mode(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00A9 + value);
    if (RAM8(0x0060 + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) == 0) {
        if (!(RAM8(0x0190 + value) & 0x80)) {
            RAM8(0x01E5 + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) = 0x0E;
        }
    }
    RAM8(0x01B4 + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) = 1;
    uint8_t value5 = RAM8(0x000E + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000));
    RAM8(0x000E + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) = value5 & 0x7F;
    r->a = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000) >> 8 << 8 | (value5 & 0x7F);
    r->x = value;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000);
    r->c = (uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000 > 0xFFFF;
    r->z = (value5 & 0x7F) == 0;
    r->n = value5 & 0x7F & 0x80;
    r->v = (((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27A29, SOM_RTS, "gen", request_descriptor_ten_target_control_timer_and_animation_mode, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 45, 21)
