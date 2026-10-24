#include "som_c.h"

/* C2B6CD gate_one_controller_input_and_publish_native_running_velocity   [class B, 145 bytes, 64 instructions]
 * Source: src/rom/gate_one_controller_input_and_publish_native_running_velocity.s
 * Documented in docs/hero-controller-action-gates.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: BXCV.
 */
static void gate_one_controller_input_and_publish_native_running_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0xE190 + x);
    if ((value & 0xC160) != 0) {
        RAM8(0x0000) &= 0x42;
        RAM8(0x0001) = 0;
        RAM8(0x0002) = 0;
        r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
        RETURN_RTS(c);
    }
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xE060 + x);
    if (value3 != 0) {
        RAM8(0x0000) &= 0x42;
        RAM8(0x0001) = 0;
        RAM8(0x0002) = 0;
        r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
        RETURN_RTS(c);
    }
    uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0xE1ED + x);
    uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0xE01C + x);
    uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0xE00A + x);
    if ((value5 | value6 | value7) != 0) {
        uint8_t value8 = BUS8_RDP(c, (db << 0x10) + 0xE063 + x);
        BUS8_SET(c, (db << 0x10) + 0xE063 + x, value8 & 0xF0);
        RAM8(0x0000) &= 0x7F;
        RAM8(0x0001) &= 0x7F;
        r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
        RETURN_RTS(c);
    }
    uint8_t value11 = RAM8(0x0000);
    RAM8(0x0000) &= 0x7F;
    if ((value11 & 0x80) == 0) {
        r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
        RETURN_RTS(c);
    }
    uint8_t value12 = BUS8_RDP(c, (db << 0x10) + 0xE01A + x);
    uint8_t value13 = BUS8_RDP(c, (db << 0x10) + 0xE01B + x);
    if ((value12 | value13) != 0) {
        r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
        RETURN_RTS(c);
    }
    uint8_t value14 = BUS8_RDP(c, (db << 0x10) + 0xE063 + x);
    BUS8_SET(c, (db << 0x10) + 0xE063 + x, value14 | 1);
    BUS8_SET(c, (db << 0x10) + 0xE011 + x, 2);
    uint8_t value15 = BUS8_RDP(c, (db << 0x10) + 0xE006 + x);
    if (value15 != 0) {
        BUS8_SET(c, (db << 0x10) + 0xE006 + x, (value15 & 0x80) | 3);
    }
    uint8_t value16 = BUS8_RDP(c, (db << 0x10) + 0xE007 + x);
    uint8_t a1;
    if (value16 == 0) {
        a1 = value16;
    } else {
        BUS8_SET(c, (db << 0x10) + 0xE007 + x, (value16 & 0x80) | 3);
        a1 = (value16 & 0x80) | 3;
    }
    uint8_t value17 = BUS8_RDP(c, (db << 0x10) + 0xE006 + x);
    if ((a1 | value17) != 0) {
        r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
        RETURN_RTS(c);
    }
    uint8_t value18 = BUS8_RDP(c, (db << 0x10) + 0xE010 + x);
    uint16_t y3;
    if (value18 == 0) {
        y3 = 0x8300;
    } else {
        uint16_t y2;
        if ((uint8_t)(value18 - 1) == 0) {
            y2 = 0x0300;
        } else {
            uint16_t y1;
            if ((uint8_t)(value18 - 2) == 0) {
                y1 = 3;
            } else {
                y1 = 0x83;
            }
            y2 = y1;
        }
        y3 = y2;
    }
    RAM8(0x0000 + sp0) = y3 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)y3;
    BUS8_SET(c, (db << 0x10) + 0xE006 + x, (uint8_t)y3);
    BUS8_SET(c, (db << 0x10) + 0xE007 + x, RAM8(0x0000 + sp0));
    r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2B6CD, SOM_RTS, "gen", gate_one_controller_input_and_publish_native_running_velocity, 0, L_B | L_X | L_C | L_V, 2, 1, 0, 145, 64)
