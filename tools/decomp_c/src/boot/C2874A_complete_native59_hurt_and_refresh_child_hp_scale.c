#include "som_c.h"
#include "som_hand_b.h"

/* C2874A complete_native59_hurt_and_refresh_child_hp_scale   [class B, 34 bytes, 15 instructions]
 * Source: src/rom/complete_native59_hurt_and_refresh_child_hp_scale.s
 * Documented in docs/boss-native59-actions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void complete_native59_hurt_and_refresh_child_hp_scale(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    if (value2 < 0x0C) {
        r->a = value2;
        r->x = value;
        r->c = 0;
        r->z = value2 == 0x0C;
        r->n = (uint16_t)(value2 - 0x0C) & 0x8000;
        RETURN_RTS(c);
    }
    r->x = value;
    JSR_CHK(c, 0x8756, 0xC234B0); /* test_boss_negative_status_word */
    bool carry_ret = r->c;
    if (!carry_ret) {
        RAM16_SET(OBJECT_PHASE + value, 1);
        RAM16_SET(0x00B2 + value, 0);
        r->a = 1;
        r->mf = 0;
        r->xf = 0;
        JSR_CHK(c, 0x8769, 0xC2876C); /* dispatch_native59_variant_hp_scaling */
        r->c = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        RETURN_RTS(c);
    }
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->c = 0;
    r->z = RAM16(OBJECT_PHASE + value) == 0;
    r->n = RAM16(OBJECT_PHASE + value) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2874A, SOM_RTS, "hand", complete_native59_hurt_and_refresh_child_hp_scale, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 34, 15)
