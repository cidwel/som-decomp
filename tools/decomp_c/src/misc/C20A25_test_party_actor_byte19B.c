#include "som_c.h"

/* C20A25 test_party_actor_byte19B   [class A, 26 bytes, 13 instructions]
 * Source: src/rom/test_party_actor_byte19B.s
 * Documented in docs/boss-target-status-queries.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void test_party_actor_byte19B(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t a = r->a;
    if ((RAM16(0x019B + (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & 0xFF) == 0) {
        r->a = 0xFFFF;
        r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
        r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
        r->z = 0;
        r->n = 1;
        r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    r->a = 0;
    r->x = (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000);
    r->c = (uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)((((a & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((a & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20A25, SOM_RTS, "gen", test_party_actor_byte19B, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 26, 13)
