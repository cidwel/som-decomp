#include "som_c.h"

/* D0D822 render_complete_menu_price_or_armor_selection_description   [class B, 124 bytes, 49 instructions]
 * Source: src/rom/render_complete_menu_price_or_armor_selection_description.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: YCV.
 */
static void render_complete_menu_price_or_armor_selection_description(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t y = r->y;
    const bool overflow = r->v;
    RAM16_SET(0x19D4, 0x1559);
    uint8_t value = RAM8(0x1847);
    bool m_flag;
    uint16_t x1;
    uint16_t y2;
    bool carry2;
    bool overflow2;
    if (value != 3) {
        m_flag = 1;
        x1 = 0x19D6;
        y2 = y;
        carry2 = value >= 3;
        overflow2 = overflow;
    } else {
        RAM16_SET(0x19D4, 0x1059);
        RAM16_SET(0x19D6, 0xD0);
        RAM16_SET(0x19D7, 0xBFBF);
        RAM16_SET(0x19D9, 0xBFBF);
        uint16_t ring_cursor = RAM16(RING_CURSOR);
        uint16_t value2 = RAM16(0x18A0 + ((ring_cursor & 0xFF) << 1));
        uint8_t a_hi1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        if ((value2 & 0x4000) != 0) {
            a_hi1 = value2 >> 8;
            y1 = y;
            carry1 = ring_cursor & 0xFF & 0x8000;
            overflow1 = overflow;
        } else {
            r->a = value2;
            r->x = (ring_cursor & 0xFF) << 1;
            r->c = ring_cursor & 0xFF & 0x8000;
            r->z = (value2 & 0x4000) == 0;
            r->n = value2 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD861, 0xC07C4C); GUARD_JSL(c, sp_call, 0xD861); } /* resolve_selected_armor_inventory_row_and_description_id */
            uint8_t y_ret = r->y;
            uint8_t value3 = RAM8(0x1842);
            RAM8(0x19D7) = (uint8_t)(value3 + 0xB6);
            RAM16_SET(0x19D8, 0x8080);
            a_hi1 = 0x80;
            y1 = y_ret;
            carry1 = (uint8_t)(value3 + 1) + 0xB5 > 0xFF;
            overflow1 = (((uint8_t)(value3 + 1) ^ (uint8_t)(value3 + 0xB6)) & ((uint8_t)(value3 + 0xB6) ^ 0xB5) & 0x80) != 0;
        }
        RAM16_SET(0x19DA, 0x1559);
        m_flag = 0;
        x1 = 0x19DC;
        y2 = y1;
        carry2 = carry1;
        overflow2 = overflow1;
    }
    BUS16_SET(c, x1, 0);
    r->a = 0;
    r->x = x1;
    r->y = y2;
    r->c = carry2;
    r->z = 1;
    r->n = 0;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD888, 0xD0D8DE); GUARD_JSR(c, sp_call, 0xD888); } /* calculate_menu_item_price_preserving_register_context */
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret2 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool overflow_ret2 = r->v;
    bool x_flag;
    uint16_t y3;
    bool carry3;
    bool overflow3;
    if (a_all2 == 0xFFFF) {
        x_flag = x_ret2;
        y3 = y_ret2;
        carry3 = a_all2 >= 0xFFFF;
        overflow3 = overflow_ret2;
    } else {
        r->c = a_all2 >= 0xFFFF;
        r->z = a_all2 == 0xFFFF;
        r->n = (uint16_t)(a_all2 - 0xFFFF) & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD890, 0xD0D89E); GUARD_JSR(c, sp_call, 0xD890); } /* format_native_menu_price_with_five_decimal_places */
        bool x_ret4 = r->xf;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        BUS16_SET(c, x_ret5, 0xAAA1);
        BUS16_SET(c, (uint16_t)(x_ret5 + 2), 0);
        x_flag = x_ret4;
        y3 = y_ret3;
        carry3 = carry_ret3;
        overflow3 = overflow_ret3;
    }
    r->y = y3;
    r->c = carry3;
    r->v = overflow3;
    r->mf = 0;
    r->xf = x_flag;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D822, SOM_RTS, "gen", render_complete_menu_price_or_armor_selection_description, 0, L_Y | L_C | L_V, 1, 1, 1, 124, 49)
