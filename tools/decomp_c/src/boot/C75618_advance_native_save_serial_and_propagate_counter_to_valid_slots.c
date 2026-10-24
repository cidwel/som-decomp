#include "som_c.h"

/* C75618 advance_native_save_serial_and_propagate_counter_to_valid_slots   [class B, 59 bytes, 22 instructions]
 * Source: src/rom/advance_native_save_serial_and_propagate_counter_to_valid_slots.s
 * Documented in docs/ui-native-loaded-game-save-write.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void advance_native_save_serial_and_propagate_counter_to_valid_slots(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0xA211);
    RAM8(0xA178) = value;
    r->a = (a_hi << 8) | value;
    JSR(c, 0x5620, 0xC75682); /* find_first_valid_save_slot_and_read_native_serial_counter */
    uint8_t value2 = RAM8(0xA175);
    uint8_t a1;
    if ((uint8_t)(value2 + 1) < 0x64) {
        a1 = (uint8_t)(value2 + 1);
    } else {
        a1 = 1;
    }
    RAM8(0xA175) = a1;
    RAM8(0xA211) = RAM8(0xA178);
    r->mf = true;
    r->xf = false;
    r->sp -= 1;
    JSR(c, 0x5637, 0xC757C6); /* derive_primary_sram_slot_offset_from_selected_index */
    r->sp += 1;
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    BUS8_SET(c, 0x3062B7 + x_ret2, a1);
    BUS8_SET(c, 0x3072B7 + x_ret2, a1);
    BUS8_SET(c, 0x3062B8 + x_ret2, a1);
    BUS8_SET(c, 0x3072B8 + x_ret2, a1);
    r->a = (a_all2 >> 8 << 8) | a1;
    r->mf = true;
    r->xf = false;
    JSR(c, 0x564B, 0xC75653); /* propagate_native_save_serial_to_each_valid_slot_and_resign */
    RAM8(0xA211) = RAM8(0xA178);
    r->mf = true;
    r->xf = false;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75618, SOM_RTS, "hand", advance_native_save_serial_and_propagate_counter_to_valid_slots, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 59, 22)
