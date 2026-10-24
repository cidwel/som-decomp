#include "som_c.h"

/* D0CB11 initialize_twelve_native_icon_rows_and_publish_upper_palette   [class C, 145 bytes, 68 instructions]
 * Source: src/rom/initialize_twelve_native_icon_rows_and_publish_upper_palette.s
 * Documented in docs/event-menu-descriptor-order.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: YV.
 */
static void initialize_twelve_native_icon_rows_and_publish_upper_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const bool overflow = r->v;
    RAM8(RING_ENTRY_COUNT) = 0x0C;
    JSR(c, 0xCB1A, 0xD0D308); /* clear_native_menu_descriptor_row_attributes */
    bool carry_ret = r->c;
    RAM16_SET(0x1822, 0x0782);
    uint8_t a1 = RAM16(RING_ENTRY_COUNT) & 0xFF;
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0x0782;
    uint16_t y1 = 0;
    bool carry1 = carry_ret;
    bool overflow1 = overflow;
    for (;;) {
        RAM16_SET(0x1820, (uint16_t)((uint16_t)(y1 << 1) + 0x18A0));
        uint16_t value = RAM16(0x0000 + (uint16_t)((uint16_t)(y1 << 1) + 0x1880));
        uint8_t a_hi5;
        uint16_t x5;
        bool carry4;
        bool overflow2;
        if (value == 0xFFFF) {
            a_hi5 = value >> 8;
            x5 = (uint16_t)((uint16_t)(y1 << 1) + 0x1880);
            carry4 = value >= 0xFFFF;
            overflow2 = (((uint16_t)((uint16_t)(y1 << 1) + 0x1880) ^ (uint16_t)((uint16_t)(y1 << 1) + 0x18A0)) & ((uint16_t)((uint16_t)(y1 << 1) + 0x18A0) ^ 0x20) & 0x8000) != 0;
        } else {
            uint8_t a_hi4;
            uint16_t x4;
            bool carry3;
            if (y1 == 3) {
                r->a = 0;
                r->x = (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1;
                r->y = y1;
                r->c = y1 >= 3;
                r->v = (((((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) ^ (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF)) & (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) ^ (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF)) & 0x8000) != 0;
                r->mf = false;
                r->xf = false;
                r->db = 0;
                r->dp = 0;
                r->sp -= 2;
                JSR(c, 0xCB75, 0xD0CBBF); /* append_one_native_icon_palette_color */
                r->sp += 2;
                uint16_t a_all2 = r->a;
                uint16_t x_ret2 = r->x;
                a_hi4 = a_all2 >> 8;
                x4 = x_ret2;
                carry3 = y1 >= 3;
            } else {
                uint8_t a_hi3;
                uint16_t x3;
                bool carry2;
                if (y1 == 6) {
                    r->a = 0;
                    r->x = (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1;
                    r->y = y1;
                    r->c = y1 >= 6;
                    r->v = (((((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) ^ (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF)) & (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) ^ (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF)) & 0x8000) != 0;
                    r->mf = false;
                    r->xf = false;
                    r->db = 0;
                    r->dp = 0;
                    r->sp -= 2;
                    JSR(c, 0xCB75, 0xD0CBBF); /* append_one_native_icon_palette_color */
                    r->sp += 2;
                    uint16_t a_all3 = r->a;
                    uint16_t x_ret3 = r->x;
                    a_hi3 = a_all3 >> 8;
                    x3 = x_ret3;
                    carry2 = y1 >= 6;
                } else {
                    uint8_t a_hi2;
                    uint16_t x2;
                    if (y1 != 9) {
                        a_hi2 = 0;
                        x2 = (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1;
                    } else {
                        r->a = 0;
                        r->x = (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1;
                        r->y = y1;
                        r->c = y1 >= 9;
                        r->v = (((((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) ^ (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF)) & (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) ^ (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF)) & 0x8000) != 0;
                        r->mf = false;
                        r->xf = false;
                        r->db = 0;
                        r->dp = 0;
                        r->sp -= 2;
                        JSR(c, 0xCB75, 0xD0CBBF); /* append_one_native_icon_palette_color */
                        r->sp += 2;
                        uint16_t a_all4 = r->a;
                        uint16_t x_ret4 = r->x;
                        a_hi2 = a_all4 >> 8;
                        x2 = x_ret4;
                    }
                    a_hi3 = a_hi2;
                    x3 = x2;
                    carry2 = y1 >= 9;
                }
                a_hi4 = a_hi3;
                x4 = x3;
                carry3 = carry2;
            }
            a_hi5 = a_hi4;
            x5 = x4;
            carry4 = carry3;
            overflow2 = (((((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) ^ (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF)) & (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) ^ (((((uint8_t)value << 8) | (value >> 8)) & 0xFF) << 1 << 1) + ((((uint8_t)value << 8) | (value >> 8)) & 0xFF)) & 0x8000) != 0;
        }
        uint16_t value3 = RAM16(0x0000 + RAM16(0x1820));
        uint8_t a_hi6;
        if ((value3 & 0x4000) == 0) {
            a_hi6 = (value3 & 0x4000) >> 8;
        } else {
            a_hi6 = 0;
        }
        r->a = (a_hi6 << 8) | a;
        r->x = x5;
        r->y = y1;
        r->c = carry4;
        r->v = overflow2;
        r->mf = false;
        r->xf = false;
        r->db = 0;
        r->dp = 0;
        r->sp -= 2;
        JSR(c, 0xCB89, 0xD0CBA2); /* read_native_icon_color_or_disabled_row_color */
        r->sp += 2;
        r->mf = false;
        r->xf = false;
        r->sp -= 2;
        JSR(c, 0xCB8C, 0xD0CBA2); /* read_native_icon_color_or_disabled_row_color */
        r->sp += 2;
        r->mf = false;
        r->xf = false;
        r->sp -= 2;
        JSR(c, 0xCB8F, 0xD0CBA2); /* read_native_icon_color_or_disabled_row_color */
        r->sp += 2;
        r->mf = false;
        r->xf = false;
        r->sp -= 2;
        JSR(c, 0xCB92, 0xD0CBA2); /* read_native_icon_color_or_disabled_row_color */
        r->sp += 2;
        r->mf = false;
        r->xf = false;
        r->sp -= 2;
        JSR(c, 0xCB95, 0xD0CBA2); /* read_native_icon_color_or_disabled_row_color */
        r->sp += 2;
        uint16_t x_ret9 = r->x;
        bool again = (uint16_t)(((a_hi1 << 8) | a1) - 1) != 0;
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) - 1);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) - 1) >> 8;
        uint16_t x1_next = x_ret9;
        uint16_t y1_next = (uint16_t)(y1 + 1);
        bool carry1_next = carry4;
        bool overflow1_next = overflow2;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!again) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = false;
    r->xf = false;
    r->db = 0;
    r->dp = 0;
    JSR(c, 0xCB9D, 0xD0CDA9); /* request_menu_palette_upload */
    r->mf = false;
    r->xf = false;
    JSR(c, 0xCBA0, 0xD0CBD6); /* cache_selected_native_menu_icon_palette_page */
    r->mf = false;
    r->xf = false;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0CB11, SOM_RTL, "hand", initialize_twelve_native_icon_rows_and_publish_upper_palette, 0, L_Y | L_V, 4, 1, 0, 145, 68)
