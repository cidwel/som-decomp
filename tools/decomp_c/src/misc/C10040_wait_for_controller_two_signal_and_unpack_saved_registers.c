#include "som_c.h"

/* C10040 wait_for_controller_two_signal_and_unpack_saved_registers   [class D, 57 bytes, 37 instructions]
 * Source: src/rom/wait_for_controller_two_signal_and_unpack_saved_registers.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: nothing.
 */
static void wait_for_controller_two_signal_and_unpack_saved_registers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    uint64_t loop_guard = 0;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t value = RAM8(0x0100);
    RAM8(0x0100) = 0x40;
    uint8_t a1 = 0x40;
    uint8_t a_hi1 = value;
    for (;;) {
        LOOP_GUARD(loop_guard);
        r->a = (a_hi1 << 8) | a1;
        r->y = y;
        r->c = carry;
        r->v = overflow;
        r->mf = 1;
        r->xf = 0;
        r->db = 0;
        r->dp = dp;
        r->sp -= 8;
        som_wai(c); /* WAI */
        if (c->fail) return;
        r->sp += 8;
        uint16_t x1 = 0;
        for (;;) {
            LOOP_GUARD(loop_guard);
            x1 = (uint16_t)(x1 - 1);
            if (!(x1 != 0)) break;
        }
        uint8_t value2 = BUS8(c, 0x00421B);
        uint8_t value3 = BUS8(c, 0x00421A);
        a1 = value3 & 0x10;
        if (!(a1 == 0)) break;
    }
    RAM8(0x0100) = a_hi1;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC10040, SOM_RTS, "gen", wait_for_controller_two_signal_and_unpack_saved_registers, 0, 0, 8, 1, 0, 57, 37)
