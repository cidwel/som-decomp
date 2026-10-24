#include "som_c.h"

/* JSR keeps the program bank: this code runs from the bank $00 mirror, where $0B00 is WRAM. */
#define SAME_BANK(c, off) (((uint32_t)(c)->cpu.k << 16) | (off))

/* C099F3 configure_rom_row_cursor_and_execute_relocated_rle_decoder   [class D, 109 bytes, 60 instructions]
 * Source: src/rom/configure_rom_row_cursor_and_execute_relocated_rle_decoder.s
 * Documented in docs/ui-native-scene-tile-rows.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void configure_rom_row_cursor_and_execute_relocated_rle_decoder(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t sp0 = r->sp;
    const bool overflow = r->v;
    BUS16_SET(c, 0x002181, (uint16_t)((((uint8_t)(a & 0x01FF) << 8) | ((a & 0x01FF) >> 8)) << 1) & 0xFE00);
    uint16_t value = BUS16(c, 0xC68000 + ((a & 0x01FF) << 1));
    RAM16_SET(0x0B01, value & 0xFF00);
    RAM16_SET(0x0B17, value & 0xFF00);
    RAM16_SET(0x0B3A, value & 0xFF);
    BUS8_SET(c, 0x002183, 1);
    uint8_t value2 = BUS8(c, 0xC67FC0 + ((a & 0x01FF) >> 3));
    RAM8(0x0B3C) = value2;
    uint8_t a2;
    uint8_t a_hi2;
    bool carry2;
    if (((uint8_t)(a & 0x01FF) & 7) != 0) {
        uint8_t a1 = RAM8(0x0B3C);
        uint8_t a_hi1 = 0;
        uint8_t x1 = (uint8_t)(a & 0x01FF) & 7;
        bool carry1 = (a & 0x01FF) >> 2 & 0x01;
        for (;;) {
            uint8_t a1_next = a1 >> 1;
            uint8_t x1_next = (uint8_t)(x1 - 1);
            bool carry1_next = a1 & 0x01;
            a1 = a1_next;
            x1 = x1_next;
            carry1 = carry1_next;
            if (!(x1 != 0)) break;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        carry2 = carry1;
    } else {
        a2 = RAM8(0x0B3C);
        a_hi2 = 0;
        carry2 = (a & 0x01FF) >> 2 & 0x01;
    }
    RAM8(0x0B3E) = (a2 & 1) | 0xC6;
    uint8_t value5 = RAM8(0x0B3E);
    uint16_t value6 = RAM16(0x0B3A);
    RAM8(0x0B3B) = 0;
    r->a = (a_hi2 << 8) | value5;
    r->x = 0x01FF;
    r->y = value6;
    r->c = carry2;
    r->z = 0;
    r->n = 0;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RAM8(sp0) = r->db; /* PHB */
    r->db = value5;
    r->dp = 0x0B00;
    r->sp -= 1;
    push16(c, 0x9A55);
    som_call(c, SAME_BANK(c, 0x0B00), SOM_RTS); /* relocated RLE decoder in WRAM, run from bank 00; not "nested": a decoder that drops its return address is not unwound */
    r->sp += 1;
    r->mf = 0; /* SEP #$20 / PLB / REP #$20: the index width is whatever the decoder left */
    r->db = RAM8(sp0);
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC099F3, SOM_RTS, "hand", configure_rom_row_cursor_and_execute_relocated_rle_decoder, 0, L_X | L_Y, 2, 0, 1, 109, 60)
