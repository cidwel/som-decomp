#include "som_c.h"

/* C1E0F9 request_frame_upload_and_wait_for_native_nmi   [class A, 11 bytes, 6 instructions]
 * Source: src/rom/request_frame_upload_and_wait_for_native_nmi.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void request_frame_upload_and_wait_for_native_nmi(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x00EC) = 2;
    bool zero1 = 0;
    bool negative1 = 0;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = RAM8(0x00EC);
        zero1 = (value & 2) == 0;
        negative1 = value & 0x80;
        overflow1 = value & 0x40;
        if (!((value & 2) != 0)) break;
    }
    r->a = (a_hi << 8) | 2;
    r->x = x;
    r->y = y;
    r->c = carry;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E0F9, SOM_RTS, "gen", request_frame_upload_and_wait_for_native_nmi, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, -1, 11, 6)
