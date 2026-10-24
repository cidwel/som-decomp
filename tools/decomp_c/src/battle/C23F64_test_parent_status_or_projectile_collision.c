#include "som_c.h"

/* C23F64 test_parent_status_or_projectile_collision   [class B, 20 bytes, 11 instructions]
 * Source: src/rom/test_parent_status_or_projectile_collision.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYCV.
 */
static void test_parent_status_or_projectile_collision(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    uint16_t value2 = RAM16(0x0190 + value);
    if (value2 & 0x8000) {
        r->x = value;
        r->c = 1;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->x = value;
    JSR(c, 0x3F6F, 0xC23CE8); /* scan_projectile_collision_and_mark_parent_target_contacts */
    bool carry_ret = r->c;
    if (carry_ret) {
        r->c = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->x = RAM16(0x0287);
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23F64, SOM_RTS, "gen", test_parent_status_or_projectile_collision, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 20, 11)
