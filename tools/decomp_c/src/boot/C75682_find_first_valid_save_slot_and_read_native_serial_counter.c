#include "som_c.h"

/* C75682 find_first_valid_save_slot_and_read_native_serial_counter   [class B, 39 bytes, 16 instructions]
 * Source: src/rom/find_first_valid_save_slot_and_read_native_serial_counter.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void find_first_valid_save_slot_and_read_native_serial_counter(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0xA211) = 0;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool overflow1 = overflow;
    for (;;) {
        r->a = (a_hi1 << 8) | a;
        r->y = y1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0;
        JSR(c, 0x5687, 0xC7583C); /* select_save_slot_copy_and_reject_invalid_pair */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint8_t value = RAM8(0xA212);
        uint8_t a1;
        if ((value & 4) == 0) {
            uint8_t value2 = BUS8(c, 0x3062B8 + x_ret);
            a1 = value2;
        } else {
            RAM8(0xA212) &= 0xFB;
            uint8_t value4 = RAM8(0xA211);
            RAM8(0xA211) = (uint8_t)(value4 + 1);
            if ((uint8_t)(value4 + 1) != 4) {
                a_hi1 = a_all >> 8;
                x1 = x_ret;
                overflow1 = value & 0x40;
                continue;
            }
            a1 = 0;
        }
        RAM8(0xA175) = a1;
        r->v = value & 0x40;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC75682, SOM_RTS, "gen", find_first_valid_save_slot_and_read_native_serial_counter, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 39, 16)
