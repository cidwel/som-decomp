#include "som_c.h"
#include "som_hand_b.h"

/* D0D720 compare_item_base_stat_after_real_hero_eligibility_test   [class C, 152 bytes, 68 instructions]
 * Source: src/rom/compare_item_base_stat_after_real_hero_eligibility_test.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYV.
 */
/* D0D787 (inside this routine): format one stat value at the text pointer X, then the separator character. */
static void write_stat_value_and_separator(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    r->mf = 0; /* REP #$20 */
    r->a &= 0x00FF;
    hand_nz16(r, r->a);
    JSR_CHK(c, 0xD78E, 0xD0D7B8); /* append_native_two_or_three_digit_menu_number */
    r->mf = 1; /* SEP #$20 */
    uint8_t category = RAM8(((uint32_t)r->db << 16) + 0x1809);
    hand_lda8(r, category);
    hand_cmp16(r, category, 1);
    if (category == 1) {
        hand_lda8(r, 0xC1);
        BUS8_SET(c, (uint16_t)(r->dp + r->x), 0xC1);
        r->x++;
        r->mf = 0;
        return;
    }
    r->mf = 0;
    r->a = 0x00D0;
    BUS16_SET(c, (uint16_t)(r->dp + r->x), 0x00D0);
    r->x++;
}

static void compare_item_base_stat_after_real_hero_eligibility_test(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    JSL_CHK(c, 0xD723, 0xD0C800); /* locate_menu_category_inventory_and_equipment_spans */
    const uint32_t bank = (uint32_t)r->db << 16;
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    r->a = r->y;
    r->c = 0;
    r->a = hand_adc16(r, r->a, BUS16(c, bank + 0x1849));
    bus16_set_once(c, bank + 0x184B, r->a);
    bus16_set_once(c, bank + 0x184D, r->x);
    bus16_set_once(c, bank + 0x19D4, 0x1559);
    r->x = BUS16(c, bank + 0x184B);
    r->a = BUS16(c, 0x7EE180u + r->x);
    JSR_CHK(c, 0xD740, 0xD0D9DE); /* read_item_base_stat_from_native_ten_byte_table */
    r->x = 0x19D6;
    push16(c, 0xD746); /* JSR D787 (a local subroutine): its return address is a real stack entry */
    write_stat_value_and_separator(c);
    if (c->fail) return;
    r->sp += 2;
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    i_phx(c);
    r->a = 0;
    JSR_CHK(c, 0xD74F, 0xD0D530); /* add_wrapped_menu_row_to_inventory_label_offset */
    r->mf = 0;
    r->xf = 0;
    r->a &= 0x00FF;
    r->c = 0;
    r->a = hand_adc16(r, r->a, BUS16(c, bank + 0x184D));
    r->x = r->a;
    r->a = BUS16(c, 0x7ECC00u + r->x);
    i_phx(c);
    i_php(c);
    r->y = BUS16(c, bank + 0x1808);
    JSL_CHK(c, 0xD766, 0xC079C7); /* test_native_menu_item_eligibility_for_selected_hero */
    hand_plp(c);
    i_plx(c);
    r->a &= 1;
    hand_nz16(r, r->a);
    if (r->a != 0) {
        r->a = BUS16(c, 0x7ECC00u + r->x);
        JSR_CHK(c, 0xD774, 0xD0D9DE); /* read_item_base_stat_from_native_ten_byte_table */
        i_plx(c);
        r->mf = 0; /* REP #$20 */
        r->a &= 0x00FF;
        JSR_CHK(c, 0xD7B0, 0xD0D7B8); /* append_native_two_or_three_digit_menu_number */
    } else {
        i_plx(c);
        r->mf = 0;
        r->xf = 0;
        BUS16_SET(c, (uint16_t)(r->dp + r->x), 0xBFBF);
        BUS16_SET(c, (uint16_t)(r->dp + r->x + 2), 0xBFBF);
        r->a = 0xBFBF;
        r->x += 3;
    }
    r->mf = 0; /* REP #$20 */
    r->a = 0;
    BUS16_SET(c, (uint16_t)(r->dp + r->x), 0);
    r->x++;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D720, SOM_RTS, "hand", compare_item_base_stat_after_real_hero_eligibility_test, 0, L_A | L_B | L_X | L_Y | L_V, 5, -1, 0, 152, 68)
