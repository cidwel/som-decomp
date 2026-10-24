#include "som_c.h"

/* C1E6AC wait_for_native_nmi_and_refresh_party_portraits   [class D, 46 bytes, 18 instructions]
 * Source: src/rom/wait_for_native_nmi_and_refresh_party_portraits.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=any D=$0000.  Callers read: ABXYCZNV.
 */
static void wait_for_native_nmi_and_refresh_party_portraits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x00EC) = 2;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value = RAM8(0x00EC);
        overflow1 = value & 0x40;
        if (!((value & 2) != 0)) break;
    }
    BUS8_SET(c, (db << 0x10) + 0x2115, 0x80);
    RAM16_SET(0x0000, 0x7E80);
    r->a = (a_hi << 8) | RAM8(0xE180);
    r->y = 0x7E80;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE6CA, 0xC1E6DA); GUARD_JSR(c, sp_call, 0xE6CA); } /* upload_one_map_party_icon */
    uint16_t a_all = r->a;
    r->a = (a_all >> 8 << 8) | RAM8(0xE380);
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE6D1, 0xC1E6DA); GUARD_JSR(c, sp_call, 0xE6D1); } /* upload_one_map_party_icon */
    uint16_t a_all2 = r->a;
    r->a = (a_all2 >> 8 << 8) | RAM8(0xE580);
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE6D8, 0xC1E6DA); GUARD_JSR(c, sp_call, 0xE6D8); } /* upload_one_map_party_icon */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E6AC, SOM_RTS, "gen", wait_for_native_nmi_and_refresh_party_portraits, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 46, 18)
