#include "som_c.h"

/* C1E2E5 clear_party_hud_tilemap   [class D, 25 bytes, 11 instructions]
 * Source: src/rom/clear_party_hud_tilemap.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void clear_party_hud_tilemap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x002115, 0x80);
    BUS16_SET(c, 0x002116, 0x5B20);
    uint16_t y1 = 0x60;
    bool zero1 = 0;
    bool negative1 = 0;
    for (;;) {
        BUS16_SET(c, 0x002118, 0);
        uint16_t y1_next = (uint16_t)(y1 - 1);
        bool zero1_next = (uint16_t)(y1 - 1) == 0;
        bool negative1_next = (uint16_t)(y1 - 1) & 0x8000;
        y1 = y1_next;
        zero1 = zero1_next;
        negative1 = negative1_next;
        if (!(y1 != 0)) break;
    }
    r->a = 0x5B20;
    r->x = x;
    r->y = y1;
    r->c = carry;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E2E5, SOM_RTS, "gen", clear_party_hud_tilemap, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 25, 11)
