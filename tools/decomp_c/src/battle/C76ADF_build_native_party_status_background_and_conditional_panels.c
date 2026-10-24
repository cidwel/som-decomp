#include "som_c.h"

/* C76ADF build_native_party_status_background_and_conditional_panels   [class B, 68 bytes, 24 instructions]
 * Source: src/rom/build_native_party_status_background_and_conditional_panels.s
 * Documented in docs/ui-native-party-status-art.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void build_native_party_status_background_and_conditional_panels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->a = 0x2050;
    r->x = 0xE2;
    r->y = 5;
    r->mf = false;
    JSR(c, 0x6AEC, 0xC76B2B); /* build_ten_row_native_party_status_rectangle_prefix */
    r->x = 0xEC;
    r->y = 2;
    r->mf = false;
    r->xf = false;
    JSR(c, 0x6AF5, 0xC76B2B); /* build_ten_row_native_party_status_rectangle_prefix */
    uint16_t y_ret2 = r->y;
    bool overflow_ret2 = r->v;
    r->mf = false;
    r->xf = false;
    JSR(c, 0x6AF8, 0xC76AA4); /* read_selected_native_party_status_excluding_low_two_bits */
    uint16_t a_all3 = r->a;
    uint16_t x_ret3 = r->x;
    bool carry_ret3 = r->c;
    bool zero_ret3 = r->z;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool overflow1;
    if (zero_ret3) {
        a1 = (uint8_t)a_all3;
        a_hi1 = a_all3 >> 8;
        x1 = x_ret3;
        y1 = y_ret2;
        carry1 = carry_ret3;
        zero1 = zero_ret3;
        overflow1 = overflow_ret2;
    } else {
        r->a = RAM16(0x9000 + 0x0402) | 0x1400;
        r->x = 0x0402;
        r->y = 0x0E;
        r->mf = false;
        r->xf = false;
        JSR(c, 0x6B09, 0xC76B23); /* build_four_row_native_party_status_rectangle_prefix */
        uint16_t x_ret4 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret3 = r->v;
        RAM16_SET(0x9500, 0x2022);
        RAM16_SET(0x9540, 0x2022);
        RAM16_SET(0x951E, 0x6022);
        RAM16_SET(0x955E, 0x6022);
        a1 = 0x22;
        a_hi1 = 0x60;
        x1 = x_ret4;
        y1 = y_ret3;
        carry1 = carry_ret4;
        zero1 = 0;
        overflow1 = overflow_ret3;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow1;
    r->mf = true;
    r->xf = false;
    JSL(c, 0x6B21, 0xC02AD7); /* native_menu_tile_workspace_upload_long_wrapper */
    r->mf = true;
    r->xf = false;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76ADF, SOM_RTS, "hand", build_native_party_status_background_and_conditional_panels, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 68, 24)
