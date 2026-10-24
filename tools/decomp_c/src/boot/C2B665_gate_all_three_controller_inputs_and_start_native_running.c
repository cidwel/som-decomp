#include "som_c.h"

/* C2B665 gate_all_three_controller_inputs_and_start_native_running   [class B, 104 bytes, 56 instructions]
 * Source: src/rom/gate_all_three_controller_inputs_and_start_native_running.s
 * Documented in docs/hero-controller-action-gates.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void gate_all_three_controller_inputs_and_start_native_running(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    uint8_t value = RAM8(0x00D9);
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    if (value == 0) {
        a_hi2 = a_hi;
        x2 = x;
        y2 = y;
    } else {
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        if (value & 0x80) {
            a_hi1 = a_hi;
            x1 = x;
            y1 = y;
        } else {
            RAM16_SET(0x0001, RAM16(0x0042));
            RAM8(0x0000) = RAM8(0x00CC);
            r->x = ((value & 6) << 8) | 0;
            r->xf = 0;
            r->db = 0x7E;
            r->sp -= 1;
            JSR(c, 0xB684, 0xC2B6CD); /* gate_one_controller_input_and_publish_native_running_velocity */
            r->sp += 1;
            uint16_t a_all = r->a;
            RAM8(0x00CC) = RAM8(0x0000);
            uint16_t value5 = RAM16(0x0001);
            RAM16_SET(0x0042, value5);
            a_hi1 = a_all >> 8;
            x1 = ((value & 6) << 8) | 0;
            y1 = value5;
        }
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
    }
    uint8_t value6 = RAM8(0x00DA);
    uint8_t a_hi4;
    uint16_t x4;
    uint16_t y4;
    if (value6 == 0) {
        a_hi4 = a_hi2;
        x4 = x2;
        y4 = y2;
    } else {
        uint8_t a_hi3;
        uint16_t x3;
        uint16_t y3;
        if (value6 & 0x80) {
            a_hi3 = a_hi2;
            x3 = x2;
            y3 = y2;
        } else {
            RAM16_SET(0x0001, RAM16(0x0044));
            RAM8(0x0000) = RAM8(0x00CD);
            r->x = ((value6 & 6) << 8) | 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->sp -= 1;
            JSR(c, 0xB6A3, 0xC2B6CD); /* gate_one_controller_input_and_publish_native_running_velocity */
            r->sp += 1;
            uint16_t a_all2 = r->a;
            RAM8(0x00CD) = RAM8(0x0000);
            uint16_t value10 = RAM16(0x0001);
            RAM16_SET(0x0044, value10);
            a_hi3 = a_all2 >> 8;
            x3 = ((value6 & 6) << 8) | 0;
            y3 = value10;
        }
        a_hi4 = a_hi3;
        x4 = x3;
        y4 = y3;
    }
    uint8_t value11 = RAM8(0x00DB);
    uint8_t a_hi6;
    uint16_t x6;
    uint16_t y6;
    if (value11 == 0) {
        a_hi6 = a_hi4;
        x6 = x4;
        y6 = y4;
    } else {
        uint8_t a_hi5;
        uint16_t x5;
        uint16_t y5;
        if (value11 & 0x80) {
            a_hi5 = a_hi4;
            x5 = x4;
            y5 = y4;
        } else {
            RAM16_SET(0x0001, RAM16(0x0046));
            RAM8(0x0000) = RAM8(0x00CE);
            r->x = ((value11 & 6) << 8) | 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->sp -= 1;
            JSR(c, 0xB6C2, 0xC2B6CD); /* gate_one_controller_input_and_publish_native_running_velocity */
            r->sp += 1;
            uint16_t a_all3 = r->a;
            RAM8(0x00CE) = RAM8(0x0000);
            uint16_t value15 = RAM16(0x0001);
            RAM16_SET(0x0046, value15);
            a_hi5 = a_all3 >> 8;
            x5 = ((value11 & 6) << 8) | 0;
            y5 = value15;
        }
        a_hi6 = a_hi5;
        x6 = x5;
        y6 = y5;
    }
    r->a = (a_hi6 << 8) | a;
    r->x = x6;
    r->y = y6;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2B665, SOM_RTL, "gen", gate_all_three_controller_inputs_and_start_native_running, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 104, 56)
