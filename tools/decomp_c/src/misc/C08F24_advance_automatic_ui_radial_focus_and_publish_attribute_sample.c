#include "som_c.h"

/* C08F24 advance_automatic_ui_radial_focus_and_publish_attribute_sample   [class B, 207 bytes, 109 instructions]
 * Source: src/rom/advance_automatic_ui_radial_focus_and_publish_attribute_sample.s
 * Documented in docs/ui-native-ui-frame-radial.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void advance_automatic_ui_radial_focus_and_publish_attribute_sample(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint16_t value = RAM16(0x00F6);
    uint16_t x1;
    uint16_t y1;
    if ((value & 0x0100) == 0) {
        x1 = (value & 0xFF) << 1;
        y1 = (((value & 0xFF) << 1) ^ 0x01FE) + 2;
    } else {
        RAM8(0x0000 + sp0) = (((value & 0xFF) << 1) ^ 0x01FE) + 2 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((((value & 0xFF) << 1) ^ 0x01FE) + 2);
        RAM8(0x0000 + sp0 - 2) = (value & 0xFF) << 1 >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)((value & 0xFF) << 1);
        x1 = (((value & 0xFF) << 1) ^ 0x01FE) + 2;
        y1 = (value & 0xFF) << 1;
    }
    uint16_t value2 = BUS16(c, 0x00FD22 + x1);
    RAM16_SET(0x0000, value2);
    uint16_t value3 = BUS16(c, 0x00FD22 + y1);
    RAM16_SET(0x0002, value3);
    uint8_t value4 = RAM8(0x008E);
    if ((value4 & 7) == 0) {
        RAM8(0x00F8)--;
    }
    if ((value4 & 7) == 0) {
        uint8_t value5 = RAM8(0x0086);
        if (value5 != 0) {
            RAM8(0x0086) = (uint8_t)(value5 - 1);
            if ((uint8_t)(value5 - 1) == 0x10) {
                RAM8(0x00F2) = 1;
                RAM8(0x0051) = 0x0E;
            }
        }
    }
    uint8_t value6 = RAM8(0x0086);
    BUS8_SET(c, 0x004202, value6);
    uint8_t value7 = RAM8(0x0001);
    uint8_t a1;
    if (value7 == 0) {
        BUS8_SET(c, 0x004203, RAM8(0x0000));
        uint8_t value9 = BUS8(c, 0x004217);
        a1 = value9;
    } else {
        a1 = value6;
    }
    RAM8(0x0000) = a1;
    uint8_t value10 = RAM8(0x0003);
    uint8_t a2;
    if (value10 == 0) {
        BUS8_SET(c, 0x004203, RAM8(0x0002));
        uint8_t value12 = BUS8(c, 0x004217);
        a2 = value12;
    } else {
        a2 = value6;
    }
    RAM8(0x0002) = a2;
    RAM8(0x0001) = 0;
    RAM8(0x0003) = 0;
    uint16_t value13 = RAM16(0x00F6);
    uint8_t a_hi3;
    if ((value13 & 0x0300) == 0) {
        a_hi3 = (value13 & 0x0300) >> 8;
    } else {
        uint8_t a_hi2;
        if ((value13 & 0x0300) != 0x0100) {
            uint8_t a_hi1;
            if ((value13 & 0x0300) != 0x0300) {
                RAM16_SET(0x0002, (uint16_t)((RAM16(0x0002) ^ 0xFFFF) + 1));
                uint16_t value15 = RAM16(0x0000);
                RAM16_SET(0x0000, (uint16_t)((value15 ^ 0xFFFF) + 1));
                a_hi1 = (uint16_t)((value15 ^ 0xFFFF) + 1) >> 8;
            } else {
                uint16_t value16 = RAM16(0x0000);
                RAM16_SET(0x0000, (uint16_t)((value16 ^ 0xFFFF) + 1));
                a_hi1 = (uint16_t)((value16 ^ 0xFFFF) + 1) >> 8;
            }
            a_hi2 = a_hi1;
        } else {
            uint16_t value17 = RAM16(0x0002);
            RAM16_SET(0x0002, (uint16_t)((value17 ^ 0xFFFF) + 1));
            a_hi2 = (uint16_t)((value17 ^ 0xFFFF) + 1) >> 8;
        }
        a_hi3 = a_hi2;
    }
    RAM16_SET(0x00FA, (uint16_t)(RAM16(0x0084) + RAM16(0x0000)));
    RAM16_SET(0x00FC, (uint16_t)(RAM16(0x0088) + RAM16(0x0002)));
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    r->y = y1;
    r->xf = 0;
    r->db = 0x7E;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8FF0, 0xC08FF3); GUARD_JSR(c, sp_call, 0x8FF0); } /* advance_ui_attribute_sample_cursor_and_copy_native_buffer_byte */
    r->sp += 1;
    uint8_t value22 = RAM8(0x0000 + sp0);
    r->mf = 1;
    r->xf = 0;
    r->db = value22;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08F24, SOM_RTS, "gen", advance_automatic_ui_radial_focus_and_publish_attribute_sample, 0, L_X | L_Y, 4, 1, 1, 207, 109)
