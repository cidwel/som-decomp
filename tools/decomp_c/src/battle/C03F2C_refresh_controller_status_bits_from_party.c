#include "som_c.h"

/* C03F2C refresh_controller_status_bits_from_party   [class A, 61 bytes, 28 instructions]
 * Source: src/rom/refresh_controller_status_bits_from_party.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCZNV.
 */
static void refresh_controller_status_bits_from_party(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x00EE) = RAM8(0xCC6D);
    RAM8(0x00EF) = RAM8(0xCC6E);
    RAM8(0x00F0) = RAM8(0xCC6F);
    RAM8(0x03B4) = 0;
    RAM8(0x03B5) = 4;
    uint8_t a_hi1 = 0;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = a_hi == 0;
    bool negative1 = a_hi & 0x80;
    for (;;) {
        uint16_t value4 = RAM16(0x03B4);
        uint8_t value5 = RAM8(ACTOR_STATUS + value4);
        uint16_t y3;
        bool carry3;
        if (!(value5 & 0x80)) {
            y3 = value4;
            carry3 = carry1;
        } else {
            uint8_t value6 = RAM8(0xE02C + value4);
            uint16_t y2;
            bool carry2;
            if (value6 == 0) {
                y2 = value4;
                carry2 = carry1;
            } else {
                uint8_t a1;
                if ((uint8_t)(value6 - 1) != 3) {
                    a1 = (uint8_t)(value6 - 1);
                } else {
                    a1 = (uint8_t)(value6 - 2);
                }
                RAM8(0x00EE + ((a_hi1 << 8) | a1)) ^= 3;
                y2 = (a_hi1 << 8) | a1;
                carry2 = (uint8_t)(value6 - 1) >= 3;
            }
            y3 = y2;
            carry3 = carry2;
        }
        RAM8(0x03B5)--;
        RAM8(0x03B5)--;
        y1 = y3;
        carry1 = carry3;
        zero1 = RAM8(0x03B5) == 0;
        negative1 = RAM8(0x03B5) & 0x80;
        if (!(!negative1)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03F2C, SOM_RTS, "gen", refresh_controller_status_bits_from_party, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 61, 28)
