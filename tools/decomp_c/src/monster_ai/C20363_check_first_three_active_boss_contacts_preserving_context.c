#include "som_c.h"

/* C20363 check_first_three_active_boss_contacts_preserving_context   [class B, 51 bytes, 31 instructions]
 * Source: src/rom/check_first_three_active_boss_contacts_preserving_context.s
 * Documented in docs/boss-public-party-services.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 */
static void check_first_three_active_boss_contacts_preserving_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = 0;
    uint8_t a_hi1 = 2;
    uint16_t y1 = 0;
    for (;;) {
        RAM16_SET(0x0287, (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600));
        uint16_t value = RAM16(0x0000 + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600));
        uint8_t a2;
        uint8_t a_hi2;
        if ((value & 0xFF) == 0) {
            a2 = value & 0xFF;
            a_hi2 = 0;
        } else {
            r->a = value & 0xFF;
            r->x = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600);
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0x0200;
            r->sp -= 6;
            JSR(c, 0x038A, 0xC2125B); /* test_boss_contact_with_three_party_actors */
            r->sp += 6;
            uint16_t a_all = r->a;
            a2 = (uint8_t)a_all;
            a_hi2 = a_all >> 8;
        }
        a1 = a2;
        a_hi1 = a_hi2;
        y1 = (uint16_t)(y1 + 1);
        if (!(y1 != 3)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC20363, SOM_RTL, "gen", check_first_three_active_boss_contacts_preserving_context, 0, L_A | L_B | L_Y | L_C | L_V, 6, 1, 0, 51, 31)
