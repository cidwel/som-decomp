#include "som_c.h"

/* C08638 advance_ui_coordinates_and_request_changed_tile_edges   [class B, 99 bytes, 50 instructions]
 * Source: src/rom/advance_ui_coordinates_and_request_changed_tile_edges.s
 * Documented in docs/ui-native-ui-frame-coordinate-contract.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void advance_ui_coordinates_and_request_changed_tile_edges(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x863A, 0xC0869B); /* compute_ui_motion_from_native_hardware_division */
    uint8_t value = RAM8(0x005F);
    uint8_t a_hi1;
    bool overflow1;
    if ((value & 4) == 0) {
        RAM16_SET(0x00FC, (uint16_t)(RAM16(0x00FC) - RAM16(0x0068)));
        uint16_t value4 = RAM16(0x00FA);
        uint16_t value5 = RAM16(0x0066);
        RAM16_SET(0x00FA, (uint16_t)(value4 - value5));
        a_hi1 = (uint16_t)(value4 - value5) >> 8;
        overflow1 = ((value4 ^ value5) & (value4 ^ (uint16_t)(value4 - value5)) & 0x8000) != 0;
    } else {
        RAM16_SET(0x00FC, (uint16_t)(RAM16(0x00FC) + RAM16(0x0068)));
        uint16_t value8 = RAM16(0x00FA);
        uint16_t value9 = RAM16(0x0066);
        RAM16_SET(0x00FA, (uint16_t)(value8 + value9));
        a_hi1 = (uint16_t)(value8 + value9) >> 8;
        overflow1 = ((value8 ^ (uint16_t)(value8 + value9)) & (value9 ^ (uint16_t)(value8 + value9)) & 0x8000) != 0;
    }
    uint16_t value10 = RAM16(0x00FA);
    uint16_t value11 = RAM16(0x0070);
    uint8_t x4;
    if ((value10 & 0xFFF8) == value11) {
        x4 = 0;
    } else {
        RAM16_SET(0x0070, value10 & 0xFFF8);
        uint8_t x3;
        if ((uint16_t)((value10 & 0xFFF8) - value11) & 0x8000) {
            x3 = 2;
        } else {
            uint8_t x2;
            if ((value10 & 0xFFF8) >= value11) {
                x2 = 1;
            } else {
                uint8_t x1;
                if ((value10 & 0xFFF8) == 0) {
                    x1 = 1;
                } else {
                    x1 = 2;
                }
                x2 = x1;
            }
            x3 = x2;
        }
        x4 = x3;
    }
    uint16_t value12 = RAM16(0x00FC);
    uint16_t value13 = RAM16(0x0072);
    uint8_t y4;
    bool carry3;
    if ((value12 & 0xFFF8) == value13) {
        y4 = 0;
        carry3 = (value12 & 0xFFF8) >= value13;
    } else {
        RAM16_SET(0x0072, value12 & 0xFFF8);
        uint8_t y3;
        bool carry2;
        if ((uint16_t)((value12 & 0xFFF8) - value13) & 0x8000) {
            y3 = 2;
            carry2 = (value12 & 0xFFF8) >= value13;
        } else {
            uint8_t y2;
            bool carry1;
            if ((value12 & 0xFFF8) >= value13) {
                y2 = 1;
                carry1 = (value12 & 0xFFF8) >= value13;
            } else {
                uint8_t y1;
                if ((value12 & 0xFFF8) == 0) {
                    y1 = 1;
                } else {
                    y1 = 2;
                }
                y2 = y1;
                carry1 = (value12 & 0xFFF8) >= 0;
            }
            y3 = y2;
            carry2 = carry1;
        }
        y4 = y3;
        carry3 = carry2;
    }
    RAM8(0x002F) = x4;
    RAM8(0x002E) = y4;
    r->a = value12 & 0xFFF8;
    r->x = x4;
    r->y = y4;
    r->c = carry3;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08638, SOM_RTS, "gen", advance_ui_coordinates_and_request_changed_tile_edges, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 99, 50)
