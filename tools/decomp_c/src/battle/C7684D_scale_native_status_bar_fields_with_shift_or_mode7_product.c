#include "som_c.h"

/* C7684D scale_native_status_bar_fields_with_shift_or_mode7_product   [class D, 67 bytes, 38 instructions]
 * Source: src/rom/scale_native_status_bar_fields_with_shift_or_mode7_product.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void scale_native_status_bar_fields_with_shift_or_mode7_product(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xA175);
    uint8_t a_hi3;
    uint16_t y3;
    bool carry3;
    if (value == 5) {
        BUS8_SET(c, 0x00211B, (uint8_t)y);
        BUS8_SET(c, 0x00211B, a_hi);
        BUS8_SET(c, 0x00211C, 0x0A);
        uint16_t value2 = BUS16(c, 0x002134);
        BUS8_SET(c, 0x00211C, 0x10);
        r->a = ((uint8_t)y << 8) | 0x10;
        r->y = value2;
        r->c = value >= 5;
        r->db = 0;
        r->sp -= 1;
        JSR(c, 0x688D, 0xC76BA5); /* divide_native_status_field_and_return_hardware_quotient */
        r->sp += 1;
        uint16_t y_ret = r->y;
        a_hi3 = (uint8_t)y;
        y3 = y_ret;
        carry3 = value >= 5;
    } else {
        uint8_t a_hi2;
        uint16_t y2;
        bool carry2;
        if (value == 7) {
            a_hi2 = (uint16_t)(y - 1) >> 3 >> 8;
            y2 = (uint16_t)(y - 1) >> 3;
            carry2 = (uint16_t)(y - 1) >> 2 & 0x01;
        } else {
            uint8_t a_hi1;
            uint16_t y1;
            bool carry1;
            if (value != 9) {
                a_hi1 = a_hi;
                y1 = y;
                carry1 = value >= 9;
            } else {
                a_hi1 = (uint16_t)(y - 1) >> 3 >> 8;
                y1 = (uint16_t)(y - 1) >> 3;
                carry1 = (uint16_t)(y - 1) >> 2 & 0x01;
            }
            a_hi2 = a_hi1;
            y2 = y1;
            carry2 = carry1;
        }
        a_hi3 = a_hi2;
        y3 = y2;
        carry3 = carry2;
    }
    r->a = (a_hi3 << 8) | a;
    r->y = y3;
    r->c = carry3;
    r->mf = true;
    r->xf = false;
    r->db = 0x7E;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7684D, SOM_RTS, "hand", scale_native_status_bar_fields_with_shift_or_mode7_product, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 67, 38)
