#include "som_c.h"

/* C25CF1 integrate_linked_child_tip_velocity_with_parent_status_gate   [class B, 60 bytes, 28 instructions]
 * Source: src/rom/integrate_linked_child_tip_velocity_with_parent_status_gate.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void integrate_linked_child_tip_velocity_with_parent_status_gate(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B0 + value);
    uint16_t value3 = RAM16(0x0060 + value2);
    if ((value3 & 0xFF) == 0x40) {
        uint8_t a_hi1 = 0;
        uint16_t x1 = value;
        uint16_t y1 = 2;
        bool overflow1 = overflow;
        for (;;) {
            uint16_t value4 = RAM16(0x00BC + x1);
            uint16_t value5 = RAM16(0x00B8 + x1);
            RAM16_SET(0x0200, (uint16_t)(value4 + value5));
            uint8_t a1;
            uint8_t a_hi2;
            if (!((uint16_t)(value4 + value5) & 0x8000)) {
                a1 = (uint8_t)(value4 + value5);
                a_hi2 = (uint16_t)(value4 + value5) >> 8;
            } else {
                a1 = (uint8_t)(((uint16_t)(value4 + value5) ^ 0xFFFF) + 1);
                a_hi2 = (uint16_t)(((uint16_t)(value4 + value5) ^ 0xFFFF) + 1) >> 8;
            }
            uint8_t a_hi3;
            if (((a_hi2 << 8) | a1) >= 0x5000) {
                a_hi3 = a_hi2;
            } else {
                uint16_t value6 = RAM16(0x0200);
                RAM16_SET(0x00B8 + x1, value6);
                a_hi3 = value6 >> 8;
            }
            a_hi1 = a_hi3;
            x1 = (uint16_t)(x1 + 2);
            y1 = (uint16_t)(y1 - 1);
            overflow1 = ((value4 ^ (uint16_t)(value4 + value5)) & (value5 ^ (uint16_t)(value4 + value5)) & 0x8000) != 0;
            if (!(y1 != 0)) break;
        }
        uint16_t value7 = RAM16(0x0287);
        r->a = (a_hi1 << 8) | (uint8_t)a;
        r->x = value7;
        r->y = y1;
        r->v = overflow1;
        RETURN_RTS(c);
    }
    if ((value3 & 0xE0) == 0) {
        uint8_t a_hi4 = 0;
        uint16_t x2 = value;
        uint16_t y2 = 2;
        bool overflow2 = overflow;
        for (;;) {
            uint16_t value8 = RAM16(0x00BC + x2);
            uint16_t value9 = RAM16(0x00B8 + x2);
            RAM16_SET(0x0200, (uint16_t)(value8 + value9));
            uint8_t a2;
            uint8_t a_hi5;
            if (!((uint16_t)(value8 + value9) & 0x8000)) {
                a2 = (uint8_t)(value8 + value9);
                a_hi5 = (uint16_t)(value8 + value9) >> 8;
            } else {
                a2 = (uint8_t)(((uint16_t)(value8 + value9) ^ 0xFFFF) + 1);
                a_hi5 = (uint16_t)(((uint16_t)(value8 + value9) ^ 0xFFFF) + 1) >> 8;
            }
            uint8_t a_hi6;
            if (((a_hi5 << 8) | a2) >= 0x5000) {
                a_hi6 = a_hi5;
            } else {
                uint16_t value10 = RAM16(0x0200);
                RAM16_SET(0x00B8 + x2, value10);
                a_hi6 = value10 >> 8;
            }
            a_hi4 = a_hi6;
            x2 = (uint16_t)(x2 + 2);
            y2 = (uint16_t)(y2 - 1);
            overflow2 = ((value8 ^ (uint16_t)(value8 + value9)) & (value9 ^ (uint16_t)(value8 + value9)) & 0x8000) != 0;
            if (!(y2 != 0)) break;
        }
        uint16_t value11 = RAM16(0x0287);
        r->a = (a_hi4 << 8) | (uint8_t)a;
        r->x = value11;
        r->y = y2;
        r->v = overflow2;
        RETURN_RTS(c);
    }
    r->a = value3 & 0xFF;
    r->x = value;
    r->y = value2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25CF1, SOM_RTS, "gen", integrate_linked_child_tip_velocity_with_parent_status_gate, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 60, 28)
