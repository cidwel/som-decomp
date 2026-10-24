#include "som_c.h"

/* C2CFD5 await_map_nmi_frame_request_two   [class A, 11 bytes, 6 instructions]
 * Source: src/rom/await_map_nmi_frame_request_two.s
 * Documented in docs/ui-native-map-overlay-wait.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void await_map_nmi_frame_request_two(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x00EC) = 2;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = RAM8(0x00EC);
        overflow1 = value & 0x40;
        if (!((value & 2) != 0)) break;
    }
    r->a = (a_hi << 8) | 2;
    r->x = x;
    r->y = y;
    r->c = carry;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2CFD5, SOM_RTS, "gen", await_map_nmi_frame_request_two, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 11, 6)
