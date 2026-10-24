#include "som_c.h"

/* C76B55 build_and_upload_sixteen_rotating_native_status_bar_patterns   [class B, 65 bytes, 24 instructions]
 * Source: src/rom/build_and_upload_sixteen_rotating_native_status_bar_patterns.s
 * Documented in docs/ui-native-party-status-art.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void build_and_upload_sixteen_rotating_native_status_bar_patterns(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xA175) = 0x10;
    RAM16_SET(0xA1C7, 0x80);
    uint8_t a1 = 0x10;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0x80;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        r->a = (a_hi1 << 8) | RAM8(0xA1C7);
        r->x = x1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        JSR(c, 0x6B68, 0xC76B96); /* repeat_native_status_bar_plane_byte_eight_times */
        r->a = (a_hi1 << 8) | 0;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x6B6D, 0xC76B96); /* repeat_native_status_bar_plane_byte_eight_times */
        r->a = (a_hi1 << 8) | RAM8(0xA1C8);
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x6B73, 0xC76B96); /* repeat_native_status_bar_plane_byte_eight_times */
        r->a = (a_hi1 << 8) | 0;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0x6B78, 0xC76B96); /* repeat_native_status_bar_plane_byte_eight_times */
        uint16_t x_ret4 = r->x;
        uint16_t y_ret4 = r->y;
        uint8_t value3 = RAM8(0xA1C7);
        RAM8(0xA1C7) = (RAM8(0xA1C7) >> 1) | 0x80;
        uint8_t value4 = RAM8(0xA1C8);
        RAM8(0xA1C8) = (RAM8(0xA1C8) >> 1) | ((value3 & 1) << 7);
        RAM8(0xA175)--;
        a1 = 0;
        x1 = x_ret4;
        y1 = y_ret4;
        carry1 = value4 & 0x01;
        if (!(RAM8(0xA175) != a1)) break;
    }
    RAM16_SET(0xA191, 0x0200);
    RAM16_SET(0xA18C, 0x6180);
    r->a = (a_hi1 << 8) | a1;
    r->x = 0x6180;
    r->y = y1;
    r->c = carry1;
    r->z = 0;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    JSL(c, 0x6B94, 0xC02ADF); /* upload_native_saved_slot_text_rows_wrapper */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76B55, SOM_RTS, "gen", build_and_upload_sixteen_rotating_native_status_bar_patterns, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 65, 24)
