#include "som_c.h"

/* C079C7 test_native_menu_item_eligibility_for_selected_hero   [class B, 50 bytes, 25 instructions]
 * Source: src/rom/test_native_menu_item_eligibility_for_selected_hero.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZV.
 */
static void test_native_menu_item_eligibility_for_selected_hero(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    uint8_t value = BUS8(c, (db << 0x10) + 0x1809);
    if (value == 3) {
        uint16_t value2 = BUS16(c, (db << 0x10) + 0x182A);
        if ((RAM8(0x0191 + (value2 & 0xFE00)) & 0xC7) != 0) {
            r->a = ((value2 & 0xFE00) >> 8 << 8) | 0;
            r->x = value2 & 0xFE00;
            r->y = (uint8_t)y;
            r->c = value >= 3;
            r->z = 1;
            r->mf = 1;
            RETURN_RTL(c);
        }
        r->a = ((value2 & 0xFE00) >> 8 << 8) | 1;
        r->x = value2 & 0xFE00;
        r->y = (uint8_t)y;
        r->c = value >= 3;
        r->z = 0;
        r->mf = 1;
        RETURN_RTL(c);
    }
    r->y = (uint8_t)y;
    r->c = value >= 3;
    r->z = value == 3;
    r->n = (uint8_t)(value - 3) & 0x80;
    r->mf = 1;
    r->xf = 1;
    JSL(c, 0x79D3, 0xC07A02); /* read_native_item_usability_and_category_bits */
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    uint8_t a2;
    uint8_t y1;
    bool carry2;
    if ((uint8_t)((uint8_t)y - 1) & 0x80) {
        a2 = (uint8_t)a_all;
        y1 = (uint8_t)((uint8_t)y - 1);
        carry2 = carry_ret;
    } else {
        uint8_t a1;
        bool carry1;
        if ((uint8_t)((uint8_t)y - 2) & 0x80) {
            a1 = (uint8_t)((uint8_t)a_all << 1);
            carry1 = (uint8_t)a_all & 0x80;
        } else {
            a1 = (uint8_t)((uint8_t)a_all << 2);
            carry1 = (uint8_t)((uint8_t)a_all << 1) & 0x80;
        }
        a2 = a1;
        y1 = (uint8_t)((uint8_t)y - 2);
        carry2 = carry1;
    }
    if ((a2 & 0x40) != 0) {
        SET_A8(r, 1);
        r->y = y1;
        r->c = carry2;
        r->z = 0;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTL(c);
    }
    SET_A8(r, 0);
    r->y = y1;
    r->c = carry2;
    r->z = 1;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC079C7, SOM_RTL, "gen", test_native_menu_item_eligibility_for_selected_hero, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, -1, 0, 50, 25)
