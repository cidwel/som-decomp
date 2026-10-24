#include "som_c.h"

/* C0248F consume_native_menu_frame_record_and_register_selection   [class B, 84 bytes, 43 instructions]
 * Source: src/rom/consume_native_menu_frame_record_and_register_selection.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$C7 D=$0000.  Callers read: ABXYCZNV.
 */
static void consume_native_menu_frame_record_and_register_selection(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0xC7, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint16_t value = BUS16(c, 0xC70000 + y);
    uint16_t value2 = BUS16(c, 0xC70000 + (uint16_t)(y + 2));
    RAM16_SET(0xA163, value2);
    RAM16_SET(0xA16B, value2);
    uint8_t value3 = RAM8(0xA20A);
    uint8_t a_hi1;
    bool carry1;
    if ((value3 & 0x20) == 0) {
        a_hi1 = value2 >> 8;
        carry1 = carry;
    } else {
        uint16_t value4 = RAM16(0xA200);
        RAM16_SET(0xA1E0 + ((value4 & 0xFF) << 1 << 1), value);
        uint16_t value5 = RAM16(0xA16B);
        RAM16_SET(0xA1E2 + ((value4 & 0xFF) << 1 << 1), value5);
        RAM8(0xA200)++;
        RAM8(0xA20A) &= 0xDF;
        a_hi1 = value5 >> 8;
        carry1 = (value4 & 0xFF) << 1 & 0x8000;
    }
    r->x = value;
    r->db = 0x7E;
    r->sp -= 5;
    JSR(c, 0x24D3, 0xC02556); /* expand_native_menu_top_border */
    r->sp += 5;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 5;
    JSR(c, 0x24D6, 0xC024E3); /* expand_native_menu_frame_vertical_pairs */
    r->sp += 5;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 5;
    JSR(c, 0x24D9, 0xC02576); /* expand_native_menu_bottom_border */
    r->sp += 5;
    RAM8(0xA20A) &= 0xBF;
    SET_A8(r, 0x40);
    r->x = value;
    r->y = (uint16_t)(y + 4);
    r->z = (uint16_t)(y + 4) == 0;
    r->n = (uint16_t)(y + 4) & 0x8000;
    r->mf = 1;
    r->xf = 0;
    r->db = 0xC7;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0248F, SOM_RTS, "gen", consume_native_menu_frame_record_and_register_selection, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 84, 43)
