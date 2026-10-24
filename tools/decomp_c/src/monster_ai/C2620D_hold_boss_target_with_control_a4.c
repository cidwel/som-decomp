#include "som_c.h"

/* C2620D hold_boss_target_with_control_a4   [class B, 53 bytes, 24 instructions]
 * Source: src/rom/hold_boss_target_with_control_a4.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: XY.
 */
static void hold_boss_target_with_control_a4(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0xA9 + x);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x60 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    if (value2 == 0) {
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x11 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
        if (value3 == 0xA4) {
            uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x0E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
            if (value4 == 0) {
                uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x0E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
                BUS8_SET(c, (db << 0x10) + 0x0E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), value5 | 0x80);
                uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0x0190 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
                BUS8_SET(c, (db << 0x10) + 0x0190 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), value6 | 1);
                BUS8_SET(c, (db << 0x10) + 0x01B4 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), 0x20);
            }
        }
    }
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2620D, SOM_RTS, "gen", hold_boss_target_with_control_a4, 0, L_X | L_Y, 1, 0, 0, 53, 24)
