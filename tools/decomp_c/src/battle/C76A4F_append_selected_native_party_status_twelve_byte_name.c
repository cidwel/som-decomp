#include "som_c.h"

/* C76A4F append_selected_native_party_status_twelve_byte_name   [class B, 44 bytes, 24 instructions]
 * Source: src/rom/append_selected_native_party_status_twelve_byte_name.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void append_selected_native_party_status_twelve_byte_name(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 4;
    JSR(c, 0x6A53, 0xC759E0); /* append_native_saved_slot_format_pair */
    uint16_t x_ret = r->x;
    uint8_t value = RAM8(0x19FE);
    RAM8(0xA173) = (uint8_t)(value << 2);
    uint8_t value2 = RAM8(0xA173);
    uint8_t a1 = 0x0C;
    uint8_t a_hi1 = 0;
    uint16_t x1 = x_ret;
    uint16_t y1 = (uint8_t)((uint8_t)(value << 3) + value2);
    bool zero1 = 0;
    for (;;) {
        uint8_t value3 = RAM8(0xCC00 + y1);
        uint8_t a2;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool zero2;
        if (value3 == 0) {
            a2 = value3;
            a_hi2 = a1;
            x2 = x1;
            y2 = y1;
            zero2 = value3 == 0;
        } else {
            RAM8(0x9C00 + x1) = value3;
            if ((uint8_t)(a1 - 1) != 0) {
                uint8_t a1_next = (uint8_t)(a1 - 1);
                uint8_t a_hi1_next = value3;
                uint16_t x1_next = (uint16_t)(x1 + 1);
                uint16_t y1_next = (uint16_t)(y1 + 1);
                bool zero1_next = (uint8_t)(a1 - 1) == 0;
                a1 = a1_next;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                y1 = y1_next;
                zero1 = zero1_next;
                continue;
            }
            a2 = (uint8_t)(a1 - 1);
            a_hi2 = value3;
            x2 = (uint16_t)(x1 + 1);
            y2 = (uint16_t)(y1 + 1);
            zero2 = (uint8_t)(a1 - 1) == 0;
        }
        a1 = a2;
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = y2;
        zero1 = zero2;
        break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = (uint8_t)(value << 3) + value2 > 0xFF;
    r->v = (((uint8_t)(value << 3) ^ (uint8_t)((uint8_t)(value << 3) + value2)) & (value2 ^ (uint8_t)((uint8_t)(value << 3) + value2)) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x6A79, 0xC7538D); /* append_native_saved_slot_text_line_token */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76A4F, SOM_RTS, "gen", append_selected_native_party_status_twelve_byte_name, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 44, 24)
