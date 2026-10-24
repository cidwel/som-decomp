#include "som_c.h"

/* C75653 propagate_native_save_serial_to_each_valid_slot_and_resign   [class B, 47 bytes, 19 instructions]
 * Source: src/rom/propagate_native_save_serial_to_each_valid_slot_and_resign.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void propagate_native_save_serial_to_each_valid_slot_and_resign(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    RAM8(0xA211) = 0;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = 4;
    bool overflow1 = overflow;
    for (;;) {
        r->a = (a_hi1 << 8) | a;
        r->y = y1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        r->sp -= 2;
        JSR(c, 0x565C, 0xC7583C); /* select_save_slot_copy_and_reject_invalid_pair */
        r->sp += 2;
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint8_t value = RAM8(0xA212);
        uint8_t a_hi2;
        uint16_t x2;
        bool overflow2;
        if ((value & 4) != 0) {
            a_hi2 = a_all >> 8;
            x2 = x_ret;
            overflow2 = value & 0x40;
        } else {
            r->v = value & 0x40;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 2;
            JSR(c, 0x5666, 0xC757C6); /* derive_primary_sram_slot_offset_from_selected_index */
            r->sp += 2;
            uint16_t x_ret2 = r->x;
            uint8_t value2 = RAM8(0xA175);
            BUS8_SET(c, 0x3062B8 + x_ret2, value2);
            BUS8_SET(c, 0x3072B8 + x_ret2, value2);
            r->mf = 1;
            r->xf = 0;
            r->sp -= 2;
            JSR(c, 0x5674, 0xC756A9); /* write_two_save_signatures_and_checksum_primary_payload */
            r->sp += 2;
            uint16_t a_all3 = r->a;
            uint16_t x_ret3 = r->x;
            bool overflow_ret2 = r->v;
            a_hi2 = a_all3 >> 8;
            x2 = x_ret3;
            overflow2 = overflow_ret2;
        }
        RAM8(0xA212) &= 0xFB;
        RAM8(0xA211)++;
        a_hi1 = a_hi2;
        x1 = x2;
        y1 = (uint16_t)(y1 - 1);
        overflow1 = overflow2;
        if (!(y1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75653, SOM_RTS, "gen", propagate_native_save_serial_to_each_valid_slot_and_resign, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 47, 19)
