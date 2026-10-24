#include "som_c.h"

/* D0D66F format_selected_equipment_current_and_candidate_stat   [class B, 81 bytes, 30 instructions]
 * Source: src/rom/format_selected_equipment_current_and_candidate_stat.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void format_selected_equipment_current_and_candidate_stat(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x19D4, 0x1559);
    uint16_t value = RAM16(0x1803);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if ((value & 0x80) == 0) {
        a_hi1 = 0;
        x1 = 0x19D6;
        y1 = y;
        carry1 = carry;
        overflow1 = overflow;
    } else {
        RAM16_SET(0x19D4, 0x1359);
        r->a = RAM16(0x1843) & 0xFF;
        r->x = 0x19D6;
        JSR(c, 0xD692, 0xD0D7B8); /* append_native_two_or_three_digit_menu_number */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    }
    RAM16_SET(0x0000 + x1, 0xAAA7);
    uint16_t ring_owner = RAM16(RING_OWNER);
    uint8_t a1;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool zero1;
    bool negative1;
    bool overflow2;
    if ((ring_owner & 1) == 0) {
        r->a = RAM16(0xE586);
        r->x = (uint16_t)(x1 + 2);
        r->y = y1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0xD6B7, 0xD0D787); /* append_menu_stat_value_and_separator */
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        uint16_t value4 = RAM16(0xE587);
        a1 = (uint8_t)value4;
        a_hi2 = value4 >> 8;
        x2 = x_ret2;
        y2 = y_ret2;
        carry2 = carry_ret2;
        zero1 = value4 == 0;
        negative1 = value4 & 0x8000;
        overflow2 = overflow_ret2;
    } else {
        r->a = RAM16(0xE386);
        r->x = (uint16_t)(x1 + 2);
        r->y = y1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0xD6AA, 0xD0D787); /* append_menu_stat_value_and_separator */
        uint16_t x_ret3 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        uint16_t value6 = RAM16(0xE387);
        a1 = (uint8_t)value6;
        a_hi2 = value6 >> 8;
        x2 = x_ret3;
        y2 = y_ret3;
        carry2 = carry_ret3;
        zero1 = value6 == 0;
        negative1 = value6 & 0x8000;
        overflow2 = overflow_ret3;
    }
    r->a = (a_hi2 << 8) | a1;
    r->x = x2;
    r->y = y2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xD6BE, 0xD0D7A9); /* append_menu_stat_value_and_terminator */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D66F, SOM_RTS, "gen", format_selected_equipment_current_and_candidate_stat, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 81, 30)
