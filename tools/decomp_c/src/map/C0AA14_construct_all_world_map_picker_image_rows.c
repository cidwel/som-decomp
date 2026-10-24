#include "som_c.h"

/* JSR keeps the program bank: this code runs from the bank $00 mirror, where the relocated decoder at $0B00 is WRAM. */
#define SAME_BANK(c, off) (((uint32_t)(c)->cpu.k << 16) | (off))

/* C0AA14 construct_all_world_map_picker_image_rows   [class D, 190 bytes, 98 instructions]
 * Source: src/rom/construct_all_world_map_picker_image_rows.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void construct_all_world_map_picker_image_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x0010, 0);
    RAM16_SET(0x0012, 0);
    BUS8_SET(c, 0x002183, 1);
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = x;
    uint8_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint16_t direct_page = 0;
    for (;;) {
        uint8_t value = RAM8(0x0010 + direct_page);
        uint8_t a1;
        if (!(value & 0x80)) {
            a1 = value;
        } else {
            a1 = value ^ 0xFE;
        }
        uint8_t value2 = BUS8(c, 0x00A798 + (uint8_t)((a_hi1 << 8) | ((a1 ^ 0x7E) >> 1)));
        uint8_t a2;
        uint8_t a_hi2;
        if (value & 0x80) {
            a2 = ((a_hi1 << 8) | value2) & 0xFF;
            a_hi2 = 0;
        } else {
            a2 = (uint8_t)(((((a_hi1 << 8) | value2) & 0xFF) ^ 0xFFFF) + 1);
            a_hi2 = (uint16_t)(((((a_hi1 << 8) | value2) & 0xFF) ^ 0xFFFF) + 1) >> 8;
        }
        uint16_t value3 = RAM16(0x000A + direct_page);
        BUS16_SET(c, 0x002181, 0xFE00);
        r->a = 0xFE00; /* LDA #$FE00 */
        r->x = value; /* LDX $10 (8-bit index registers until REP #$30) */
        r->c = (uint32_t)((a_hi2 << 8) | a2) + value3 > 0xFFFF;
        r->z = false;
        r->n = true;
        r->y = (uint16_t)(((a_hi2 << 8) | a2) + value3) & 0x01FF;
        r->v = ((((a_hi2 << 8) | a2) ^ (uint16_t)(((a_hi2 << 8) | a2) + value3)) & (value3 ^ (uint16_t)(((a_hi2 << 8) | a2) + value3)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->db = 0;
        r->dp = 0x0B00;
        r->sp -= 1;
        JSR(c, 0xAA53, SAME_BANK(c, 0x9A06)); /* routine_c09a06: runs the relocated decoder in WRAM */
        r->sp += 1;
        RAM16_SET(0x0002, RAM16(0x15000 + a1));
        RAM16_SET(0x0000, RAM16(0x15080 + a1));
        uint16_t value6 = RAM16(0x0010);
        BUS16_SET(c, 0x002181, (uint16_t)(((((uint8_t)value6 << 8) | (value6 >> 8)) >> 2) + 0x40 + (((((uint8_t)value6 << 8) | (value6 >> 8)) >> 1) & 1) - RAM16(0x0000)));
        BUS8_SET(c, 0x002183, 1);
        uint16_t value8 = RAM16(0x0000);
        RAM16_SET(0x0004, (uint16_t)(value8 << 1));
        uint8_t a_hi3 = (uint16_t)(value8 << 1) >> 8;
        uint16_t y2 = (uint8_t)((uint8_t)(value8 << 1) - 2);
        for (;;) {
            uint16_t value9 = RAM16(0x0008);
            uint16_t value10 = BUS16(c, RAM16(0x0002) + 0x7F0000 + y2);
            BUS8_SET(c, 0x002180, RAM8(0x1FE00 + ((uint16_t)(value9 - value10) & 0x01FF)));
            a_hi3 = ((uint16_t)(value9 - value10) & 0x01FF) >> 8;
            y2 = (uint16_t)(y2 - 2);
            if (!(!(y2 & 0x8000))) break;
        }
        uint8_t a_hi4 = a_hi3;
        uint16_t x2 = 0;
        uint16_t y3 = (uint16_t)(y2 + 2);
        bool carry2 = 0;
        bool overflow2 = 0;
        for (;;) {
            uint16_t value12 = BUS16(c, RAM16(0x0002) + 0x7F0000 + y3);
            uint16_t value13 = RAM16(0x0008);
            BUS8_SET(c, 0x002180, RAM8(0x1FE00 + ((uint16_t)(value12 + value13) & 0x01FF)));
            uint16_t value15 = RAM16(0x0004);
            uint8_t a_hi4_next = ((uint16_t)(value12 + value13) & 0x01FF) >> 8;
            uint16_t x2_next = (uint16_t)(value12 + value13) & 0x01FF;
            uint16_t y3_next = (uint16_t)(y3 + 2);
            bool carry2_next = (uint16_t)(y3 + 2) >= value15;
            bool overflow2_next = ((value12 ^ (uint16_t)(value12 + value13)) & (value13 ^ (uint16_t)(value12 + value13)) & 0x8000) != 0;
            a_hi4 = a_hi4_next;
            x2 = x2_next;
            y3 = y3_next;
            carry2 = carry2_next;
            overflow2 = overflow2_next;
            if (!(y3 < value15)) break;
        }
        RAM8(0x0010)++;
        RAM8(0x0010)++;
        if (RAM8(0x0010) != 0) {
            a_hi1 = a_hi4;
            x1 = (uint8_t)x2;
            y1 = (uint8_t)y3;
            carry1 = carry2;
            overflow1 = overflow2;
            direct_page = 0; /* the decoder ends with LDA #$0000 / TCD */
            continue;
        }
        a_hi1 = a_hi4;
        x1 = (uint8_t)x2;
        y1 = (uint8_t)y3;
        carry1 = carry2;
        overflow1 = overflow2;
        direct_page = 0; /* the decoder ends with LDA #$0000 / TCD */
        break;
    }
    RAM8(0x000E + direct_page)++;
    RAM8(0x001E + direct_page) = 0;
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 1;
    r->db = 0;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0AA14, SOM_RTS, "hand", construct_all_world_map_picker_image_rows, 0, L_B | L_X | L_Y | L_C | L_V, 2, 0, 1, 190, 98)
