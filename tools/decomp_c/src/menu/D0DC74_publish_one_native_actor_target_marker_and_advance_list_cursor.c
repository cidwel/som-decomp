#include "som_c.h"
#include "som_hand_b.h"

/* D0DC74 publish_one_native_actor_target_marker_and_advance_list_cursor   [class B, 74 bytes, 39 instructions]
 * Source: src/rom/publish_one_native_actor_target_marker_and_advance_list_cursor.s
 * Documented in docs/event-menu-target-selector.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_one_native_actor_target_marker_and_advance_list_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = BUS16(c, (uint16_t)(0x0000 + x));
    uint8_t a2;
    uint8_t a_hi1;
    uint16_t y2;
    bool carry1;
    bool overflow2;
    if (value == 0) {
        a2 = (uint8_t)value;
        a_hi1 = value >> 8;
        y2 = y;
        carry1 = carry;
        overflow2 = overflow;
    } else {
        uint8_t value2 = RAM8(0x0022 + value);
        uint8_t value3 = RAM8(0x0045 + value);
        uint8_t value4 = RAM8(0x0020 + value);
        uint8_t a1;
        uint16_t y1;
        bool overflow1;
        if ((uint8_t)(value4 + 4) < 0xF0) {
            a1 = (uint8_t)(value4 + 4);
            y1 = 0x0120;
            overflow1 = ((value4 ^ (uint8_t)(value4 + 4)) & ((uint8_t)(value4 + 4) ^ 4) & 0x80) != 0;
        } else {
            a1 = (uint8_t)((uint8_t)(value4 + 4) - 0x18);
            y1 = 0x4120;
            overflow1 = (((uint8_t)(value4 + 4) ^ 0x18) & ((uint8_t)(value4 + 4) ^ (uint8_t)((uint8_t)(value4 + 4) - 0x18)) & 0x80) != 0;
        }
        uint16_t value5 = RAM16(0x1832);
        BUS16_SET(c, (uint16_t)(0x0000 + value5), ((uint8_t)((uint8_t)(value2 - 0x16) - value3) << 8) | a1);
        r->a = 1;
        r->x = (uint16_t)(value5 + 2);
        r->y = y1;
        r->v = overflow1;
        r->c = (uint8_t)(value4 + 4) >= 0xF0; /* CMP #$F0 / SBC #$18 leave C set only on the wrap path */
        r->z = 0; /* LDA #$0001 */
        r->n = 0;
        r->sp -= 2;
        JSL(c, 0xDCAC, 0xC070DB); /* select_native_menu_marker_palette_attribute_long */
        r->sp += 2;
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        BUS16_SET(c, (uint16_t)(0x0000 + x_ret), a_all);
        if (!hand_rd_ok(x_ret) || !hand_rd_ok((uint32_t)x_ret + 1)) { c->fail = 3; return; } /* open bus: out of contract */
        uint16_t value6 = BUS16(c, (uint16_t)(0x0000 + x_ret));
        BUS16_SET(c, (uint16_t)(0x0000 + x_ret), (uint16_t)(y_ret + value6));
        RAM16_SET(0x1832, (uint16_t)(x_ret + 2));
        a2 = (uint8_t)(y_ret + value6);
        a_hi1 = (uint16_t)(y_ret + value6) >> 8;
        y2 = y_ret;
        carry1 = y_ret + value6 > 0xFFFF;
        overflow2 = ((y_ret ^ (uint16_t)(y_ret + value6)) & (value6 ^ (uint16_t)(y_ret + value6)) & 0x8000) != 0;
    }
    r->a = (a_hi1 << 8) | a2;
    r->x = (uint16_t)(x + 2);
    r->y = y2;
    r->c = carry1;
    r->z = (uint16_t)(x + 2) == 0;
    r->n = (uint16_t)(x + 2) & 0x8000;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0DC74, SOM_RTS, "hand", publish_one_native_actor_target_marker_and_advance_list_cursor, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 74, 39)
