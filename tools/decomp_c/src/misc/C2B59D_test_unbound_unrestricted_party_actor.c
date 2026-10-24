#include "som_c.h"

/* C2B59D test_unbound_unrestricted_party_actor   [class C, 74 bytes, 38 instructions]
 * Source: src/rom/test_unbound_unrestricted_party_actor.s
 * Entry: M=8 bit X=8 bit DB=any D=any.  Callers read: BXYCV.
 */
static void test_unbound_unrestricted_party_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t x = r->x;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = x;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0xE000 + ((a << 8) | 0));
    bool carry5;
    if (value == 0) {
        carry5 = 1;
    } else {
        bool carry4;
        if (value & 0x80) {
            carry4 = 1;
        } else {
            uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xE191 + ((a << 8) | 0));
            bool carry3;
            if ((value2 & 0xC1) != 0) {
                carry3 = 1;
            } else {
                uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xE190 + ((a << 8) | 0));
                bool carry2;
                if ((value3 & 0x60) != 0) {
                    carry2 = 1;
                } else {
                    uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0xE02C + ((a << 8) | 0));
                    uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0xE08C + ((a << 8) | 0));
                    bool carry1;
                    if ((value4 | value5) != 0) {
                        carry1 = 1;
                    } else {
                        carry1 = 0;
                    }
                    carry2 = carry1;
                }
                carry3 = carry2;
            }
            carry4 = carry3;
        }
        carry5 = carry4;
    }
    r->a = (r->a & 0x00FF) | (a << 8);
    r->c = carry5;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2B59D, SOM_RTL, "gen", test_unbound_unrestricted_party_actor, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 74, 38)
