#include "som_c.h"

/* 7E8B00 wait_for_native_title_timer_with_pause_clear   [class A, 21 bytes, 13 instructions]
 * Source: src/boot/wait_for_native_title_timer_with_pause_clear.s
 * Documented in docs/boot-native-title-unpaused-wait.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void wait_for_native_title_timer_with_pause_clear(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = zero;
    bool negative1 = negative;
    bool overflow1 = overflow;
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0300;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8B09, 0x7EA814); GUARD_JSR(c, sp_call, 0x8B09); } /* read_native_scheduler_flags_from_bank_7f */
        r->sp += 5;
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        a1 = (uint8_t)a_all & 0x40;
        a_hi1 = a_all >> 8;
        carry1 = carry_ret;
        zero1 = ((uint8_t)a_all & 0x40) == 0;
        negative1 = (uint8_t)a_all & 0x40 & 0x80;
        overflow1 = overflow_ret;
        if (!(a1 != 0)) break;
    }
    uint8_t value = RAM8(0x0000 + sp0 - 4);
    uint8_t value2 = RAM8(0x0000 + sp0 - 3);
    r->a = (a_hi1 << 8) | a1;
    r->x = (value2 << 8) | value;
    r->y = y1;
    r->c = carry1;
    r->z = ((value2 << 8) | value) == 0;
    r->n = ((value2 << 8) | value) & 0x8000;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8B11, 0x7EABE7); GUARD_JSR(c, sp_call, 0x8B11); } /* receive_with_supplied_delay */
    r->sp += 3;
    uint8_t value3 = RAM8(0x0000 + sp0 - 2);
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->c = value3 & 0x01;
    r->z = ((value5 << 8) | value4) == 0;
    r->n = ((value5 << 8) | value4) & 0x8000;
    r->v = value3 & 0x40;
    r->mf = value3 & 0x20;
    r->xf = value3 & 0x10;
    r->dp = (value5 << 8) | value4;
    r->i = value3 & 0x04;
    r->d = value3 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8B00, SOM_RTS, "gen", wait_for_native_title_timer_with_pause_clear, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 21, 13)
