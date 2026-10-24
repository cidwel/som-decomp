#include "som_c.h"

/* C75162 compare_native_name_against_other_party_members   [class B, 31 bytes, 13 instructions]
 * Source: src/rom/compare_native_name_against_other_party_members.s
 * Documented in docs/event-menu-name-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BV.
 */
static void compare_native_name_against_other_party_members(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    RAM8(0xA175) = 3;
    uint8_t a_hi1 = a_hi;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = RAM8(0xA175);
        uint8_t value2 = RAM8(0xA22B);
        uint8_t a_hi2;
        bool overflow2;
        if ((uint8_t)(value - 1) == value2) {
            RAM8(0xA175)--;
            if (RAM8(0xA175) != 0) {
                continue;
            }
            a_hi2 = a_hi1;
            overflow2 = overflow1;
        } else {
            RAM8(0xA171) = 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            JSR(c, 0x5175, 0xC75181); /* compare_twelve_native_party_name_bytes */
            uint16_t a_all = r->a;
            bool overflow_ret = r->v;
            if (RAM8(0xA171) != 0) {
                RAM8(0xA175)--;
                if (RAM8(0xA175) != 0) {
                    a_hi1 = a_all >> 8;
                    overflow1 = overflow_ret;
                    continue;
                }
            }
            a_hi2 = a_all >> 8;
            overflow2 = overflow_ret;
        }
        a_hi1 = a_hi2;
        overflow1 = overflow2;
        break;
    }
    r->a = (a_hi1 << 8) | a;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC75162, SOM_RTL, "gen", compare_native_name_against_other_party_members, 0, L_B | L_V, 1, 1, 0, 31, 13)
