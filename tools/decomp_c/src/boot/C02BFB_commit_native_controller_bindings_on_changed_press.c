#include "som_c.h"

/* C02BFB commit_native_controller_bindings_on_changed_press   [class A, 20 bytes, 8 instructions]
 * Source: src/rom/commit_native_controller_bindings_on_changed_press.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void commit_native_controller_bindings_on_changed_press(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x2BFD, 0xC03269); GUARD_JSR(c, sp_call, 0x2BFD); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
    uint8_t value2 = RAM8(0xA204 + x_ret);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    bool zero1;
    bool negative1;
    if (value == value2) {
        a1 = value;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        zero1 = value == value2;
        negative1 = (uint8_t)(value - value2) & 0x80;
    } else {
        r->a = (a_all >> 8 << 8) | value;
        r->c = value >= value2;
        r->z = value == value2;
        r->n = (uint8_t)(value - value2) & 0x80;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x2C08, 0xC76FA7); GUARD_JSL(c, sp_call, 0x2C08); } /* commit_three_native_controller_bindings_to_runtime_and_save_records */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint8_t value3 = RAM8(0xA20A);
        RAM8(0xA20A) |= 1;
        a1 = 1;
        a_hi1 = a_all2 >> 8;
        x1 = x_ret2;
        zero1 = (value3 & 1) == 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->c = value >= value2;
    r->z = zero1;
    r->n = negative1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02BFB, SOM_RTS, "gen", commit_native_controller_bindings_on_changed_press, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 20, 8)
