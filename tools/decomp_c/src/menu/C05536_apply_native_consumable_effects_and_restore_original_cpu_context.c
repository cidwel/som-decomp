#include "som_c.h"

/* C05536 apply_native_consumable_effects_and_restore_original_cpu_context   [class C, 182 bytes, 76 instructions]
 * Source: src/rom/apply_native_consumable_effects_and_restore_original_cpu_context.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void apply_native_consumable_effects_and_restore_original_cpu_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp + 4;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint16_t value = RAM16(ACTOR_HP + y);
    uint8_t a1;
    uint8_t a_hi1;
    if (value == 0) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
    } else {
        uint16_t value2 = BUS16(c, 0xD04152 + ((a_hi << 8) | a));
        uint16_t value3 = RAM16(ACTOR_PENDING_HP_HEAL + y);
        RAM16_SET(ACTOR_PENDING_HP_HEAL + y, (uint16_t)((value2 & 0xFF) + value3));
        a1 = (uint8_t)((value2 & 0xFF) + value3);
        a_hi1 = (uint16_t)((value2 & 0xFF) + value3) >> 8;
    }
    uint8_t value4 = RAM8(0x0000 + sp0 - 3);
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | a1;
    r->x = (a_hi << 8) | a;
    r->c = value4 & 0x01;
    r->z = ((value7 << 8) | value6) == 0;
    r->n = ((value7 << 8) | value6) & 0x8000;
    r->v = value4 & 0x40;
    r->mf = value4 & 0x20;
    r->xf = value4 & 0x10;
    r->db = value5;
    r->dp = (value7 << 8) | value6;
    r->i = value4 & 0x04;
    r->d = value4 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    r->sp += 4;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05536, SOM_RTS, "gen", apply_native_consumable_effects_and_restore_original_cpu_context, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 1, 0, 182, 76)
