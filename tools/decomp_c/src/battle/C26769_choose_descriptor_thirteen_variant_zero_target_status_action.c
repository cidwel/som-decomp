#include "som_c.h"

/* C26769 choose_descriptor_thirteen_variant_zero_target_status_action   [class B, 53 bytes, 26 instructions]
 * Source: src/rom/choose_descriptor_thirteen_variant_zero_target_status_action.s
 * Documented in docs/boss-descriptor-thirteen.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_thirteen_variant_zero_target_status_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 2;
    JSR(c, 0x676E, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret = r->z;
    if (!zero_ret) {
        r->a = 3;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x6795, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all2 = r->a;
        uint16_t value = BUS16(c, 0xDCE37E + (uint16_t)(a_all2 << 1));
        r->a = value;
        r->x = (uint16_t)(a_all2 << 1);
        r->c = 0;
        r->z = value == 0;
        r->n = value & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(0x00A9 + value2);
    if (RAM16(0x0190 + (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000)) != 0) {
        r->a = 3;
        r->x = value2;
        r->y = (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000);
        r->c = (uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000 > 0xFFFF;
        r->v = (((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x6795, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all3 = r->a;
        uint16_t value5 = BUS16(c, 0xDCE37E + (uint16_t)(a_all3 << 1));
        r->a = value5;
        r->x = (uint16_t)(a_all3 << 1);
        r->c = 0;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 1;
    r->x = value2;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000);
    r->c = (uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000 > 0xFFFF;
    r->v = (((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value3 << 8) | (value3 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6787, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all4 = r->a;
    uint16_t value6 = BUS16(c, 0xDCE386 + (uint16_t)(a_all4 << 1));
    r->a = value6;
    r->x = (uint16_t)(a_all4 << 1);
    r->c = 0;
    r->z = value6 == 0;
    r->n = value6 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26769, SOM_RTS, "gen", choose_descriptor_thirteen_variant_zero_target_status_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 53, 26)
