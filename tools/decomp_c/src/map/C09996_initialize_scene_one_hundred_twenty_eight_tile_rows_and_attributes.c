#include "som_c.h"

/* JSR keeps the program bank: this code runs from the bank $00 mirror, where $0B00 is WRAM, and the callees must follow it. */
#define SAME_BANK(c, off) (((uint32_t)(c)->cpu.k << 16) | (off))

/* C09996 initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes   [class B, 93 bytes, 46 instructions]
 * Source: src/rom/initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes.s
 * Documented in docs/ui-native-scene-tile-rows.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    r->y = (uint8_t)y;
    r->mf = 0;
    r->xf = 1;
    JSR(c, 0x999C, SAME_BANK(c, 0x9985)); /* install_relocated_scene_row_rle_decoder */
    uint16_t value = RAM16(0x00FC);
    uint8_t a1 = (uint8_t)value;
    uint8_t a_hi1 = value >> 8;
    uint8_t x1 = 0x80;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        RAM8(0x002E) = 2;
        r->a = (a_hi1 << 8) | a1;
        r->y = 2;
        r->c = carry1;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 1;
        r->db = 0;
        r->dp = 0;
        r->sp -= 3;
        JSR(c, 0x99A9, SAME_BANK(c, 0x98E4)); /* prepare_upper_or_lower_scene_tile_row_for_publication */
        r->sp += 3;
        r->mf = 0;
        r->xf = 1;
        r->sp -= 3;
        JSR(c, 0x99AC, SAME_BANK(c, 0x9881)); /* publish_scene_tile_row_with_horizontal_page_wrap */
        r->sp += 3;
        r->mf = 0; /* rep */
        uint16_t value2 = RAM16(0x00FC);
        RAM16_SET(0x00FC, (uint16_t)(value2 + 8));
        a1 = (uint8_t)(value2 + 8);
        a_hi1 = (uint16_t)(value2 + 8) >> 8;
        x1 = (uint8_t)(x1 - 1);
        carry1 = value2 + 8 > 0xFFFF;
        overflow1 = ((value2 ^ (uint16_t)(value2 + 8)) & ((uint16_t)(value2 + 8) ^ 8) & 0x8000) != 0;
        if (!(x1 != 0)) break;
    }
    RAM16_SET(0x00FC, value);
    uint16_t value3 = RAM16(0x00F6);
    RAM16_SET(0x00F6, (uint16_t)(value3 - 0x0100) & 0x03FF);
    RAM8(0x0011) = 0x40;
    uint8_t a_hi2 = ((uint16_t)(value3 - 0x0100) & 0x03FF) >> 8;
    uint8_t y1 = 0;
    bool carry2 = value3 >= 0x0100;
    bool overflow2 = ((value3 ^ 0x0100) & (value3 ^ (uint16_t)(value3 - 0x0100)) & 0x8000) != 0;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            RAM16_SET(0x00F6, (uint16_t)(RAM16(0x00F6) + 4) & 0x03FF);
            r->x = 0;
            r->y = 4;
            r->mf = 0;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            JSR(c, 0x99E4, SAME_BANK(c, 0x8455)); /* advance_two_scene_attribute_windows_and_rom_rows */
            r->mf = 0; /* rep */
            bool carry_ret3 = r->c;
            bool overflow_ret2 = r->v;
            r->mf = 0;
            r->xf = 1;
            JSR(c, 0x99EB, SAME_BANK(c, 0x8890)); /* publish_changed_scene_attribute_window_rows */
            r->mf = 1; /* sep */
            uint16_t a_all5 = r->a;
            RAM8(0x0011)--;
            if (RAM8(0x0011) != 0) {
                a_hi2 = a_all5 >> 8;
                y1 = 4;
                carry2 = carry_ret3;
                overflow2 = overflow_ret2;
                first_pass = false;
                continue;
            }
            a_hi2 = a_all5 >> 8;
            y1 = 4;
            carry2 = carry_ret3;
            overflow2 = overflow_ret2;
            break;
        } else {
            RAM16_SET(0x00F6, (uint16_t)(RAM16(0x00F6) + 4) & 0x03FF);
            r->x = 0;
            r->y = 4;
            r->mf = 0;
            r->xf = 1;
            r->db = 0;
            r->dp = 0;
            JSR(c, 0x99E4, SAME_BANK(c, 0x8455)); /* advance_two_scene_attribute_windows_and_rom_rows */
            r->mf = 0; /* rep */
            bool carry_ret4 = r->c;
            bool overflow_ret3 = r->v;
            r->mf = 0;
            r->xf = 1;
            JSR(c, 0x99EB, SAME_BANK(c, 0x8890)); /* publish_changed_scene_attribute_window_rows */
            r->mf = 1; /* sep */
            uint16_t a_all7 = r->a;
            RAM8(0x0011)--;
            if (RAM8(0x0011) != 0) {
                a_hi2 = a_all7 >> 8;
                y1 = 4;
                carry2 = carry_ret4;
                overflow2 = overflow_ret3;
                continue;
            }
            a_hi2 = a_all7 >> 8;
            y1 = 4;
            carry2 = carry_ret4;
            overflow2 = overflow_ret3;
            break;
        }
    }
    r->a = (a_hi2 << 8) | a;
    r->y = y1;
    r->c = carry2;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 1;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09996, SOM_RTS, "hand", initialize_scene_one_hundred_twenty_eight_tile_rows_and_attributes, 0, L_B | L_Y | L_C | L_V, 3, 1, 0, 93, 46)
