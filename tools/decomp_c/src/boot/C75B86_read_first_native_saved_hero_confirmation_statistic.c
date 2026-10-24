#include "som_c.h"

/* C75B86 read_first_native_saved_hero_confirmation_statistic   [class A, 34 bytes, 17 instructions]
 * Source: src/rom/read_first_native_saved_hero_confirmation_statistic.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void read_first_native_saved_hero_confirmation_statistic(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    r->mf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B8B, 0xC75D00); GUARD_JSR(c, sp_call, 0x5B8B); } /* derive_selected_save_slot_primary_or_backup_offset */
    r->sp += 2;
    uint16_t x_ret = r->x;
    RAM16_SET(0xA171, x_ret);
    uint16_t value = RAM16(0xA177);
    uint16_t value2 = RAM16(0xA171);
    uint16_t value3 = BUS16(c, 0x306109 + (uint16_t)(((((value & 0xFF) << 8) | 0) >> 1) + value2));
    uint8_t value4 = RAM8(0x0000 + sp0 - 1);
    uint8_t value5 = RAM8(0x0000 + sp0);
    r->a = (r->a & 0x00FF) | (0 << 8);
    r->x = (value5 << 8) | value4;
    r->y = value3 & 0xFF;
    r->c = ((((value & 0xFF) << 8) | 0) >> 1) + value2 > 0xFFFF;
    r->v = ((((((value & 0xFF) << 8) | 0) >> 1) ^ (uint16_t)(((((value & 0xFF) << 8) | 0) >> 1) + value2)) & (value2 ^ (uint16_t)(((((value & 0xFF) << 8) | 0) >> 1) + value2)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75B86, SOM_RTS, "gen", read_first_native_saved_hero_confirmation_statistic, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 34, 17)
