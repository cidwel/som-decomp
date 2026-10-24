#include "som_c.h"

/* C1EA43 event_request_party_freeze_until_ready   [class A, 22 bytes, 11 instructions]
 * Source: src/rom/event_request_party_freeze_until_ready.s
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_request_party_freeze_until_ready(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x00F1);
    RAM8(0x00F1) |= 0x80;
    r->a = (a_hi << 8) | 0x80;
    r->z = (value & 0x80) == 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEA4A, 0x02B053); GUARD_JSL(c, sp_call, 0xEA4A); } /* freeze_party_motion_when_all_heroes_ready */
    bool carry_ret = r->c;
    if (!carry_ret) {
        RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
        r->z = RAM16(0x00D1) == 0;
        r->n = RAM16(0x00D1) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EA43, SOM_RTS, "gen", event_request_party_freeze_until_ready, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 22, 11)
