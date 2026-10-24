#include "som_c.h"

/* C276E3 immobilize_idle_descriptor_ten_target_with_status_and_timer   [class B, 51 bytes, 23 instructions]
 * Source: src/rom/immobilize_idle_descriptor_ten_target_with_status_and_timer.s
 * Documented in docs/boss-descriptor-axis-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void immobilize_idle_descriptor_ten_target_with_status_and_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00A9 + x);
    uint8_t value2 = RAM8(0x0060 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    uint8_t a2;
    bool zero2;
    bool negative2;
    if (value2 != 0) {
        a2 = value2;
        zero2 = value2 == 0;
        negative2 = value2 & 0x80;
    } else {
        uint8_t value3 = RAM8(0x000E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
        uint8_t a1;
        bool zero1;
        bool negative1;
        if (value3 != 0) {
            a1 = value3;
            zero1 = value3 == 0;
            negative1 = value3 & 0x80;
        } else {
            RAM8(0x01E5 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = 0x24;
            RAM8(0x000E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) |= 0x80;
            RAM8(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) |= 1;
            RAM8(0x01B4 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = 0x20;
            a1 = 0x20;
            zero1 = 0;
            negative1 = 0;
        }
        a2 = a1;
        zero2 = zero1;
        negative2 = negative1;
    }
    r->a = ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) >> 8 << 8) | a2;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = (uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000 > 0xFFFF;
    r->z = zero2;
    r->n = negative2;
    r->v = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC276E3, SOM_RTS, "gen", immobilize_idle_descriptor_ten_target_with_status_and_timer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 51, 23)
