#include "som_c.h"

/* C2A9F4 test_partner_actor_active_uncontrolled_and_status_available   [class B, 35 bytes, 15 instructions]
 * Source: src/rom/test_partner_actor_active_uncontrolled_and_status_available.s
 * Documented in docs/map-main-frame-partner-selection.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void test_partner_actor_active_uncontrolled_and_status_available(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE000 + x);
    if (value == 0) {
        r->c = 1;
        RETURN_RTS(c);
    }
    if (value & 0x80) {
        r->c = 1;
        RETURN_RTS(c);
    }
    if ((RAM8(0xE02C + x) | RAM8(0xE08C + x)) != 0) {
        r->c = 1;
        RETURN_RTS(c);
    }
    uint16_t value4 = RAM16(ACTOR_STATUS + x);
    if ((value4 & 0xC160) != 0) {
        r->a = (r->a & 0x00FF) | ((value4 >> 8) << 8);
        r->c = 1;
        RETURN_RTS(c);
    }
    r->a = (r->a & 0x00FF) | ((value4 >> 8) << 8);
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A9F4, SOM_RTS, "gen", test_partner_actor_active_uncontrolled_and_status_available, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 35, 15)
