#include "som_c.h"

/* C282C0 prepare_attack_row_then_create_parent_projectile   [class A, 36 bytes, 16 instructions]
 * Source: src/rom/prepare_attack_row_then_create_parent_projectile.s
 * Documented in docs/boss-native58-grandchildren.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void prepare_attack_row_then_create_parent_projectile_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t a = r->a;
    RAM16_SET(0x0346, a);
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    RAM8(0x005A + battle_defence_work) = 0;
    uint16_t value = RAM16(0x00B0 + battle_defence_work);
    uint16_t value2 = RAM16(0x0346);
    r->a = value2;
    r->x = value;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0x82D4, 0xC0006C); GUARD_JSL(c, sp_call, 0x82D4); } /* boss_attack_row_public_jump */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        uint8_t battle_defence_work2 = RAM8(BATTLE_DEFENCE_WORK);
        uint8_t value3 = RAM8(0x00A9 + battle_defence_work2);
        if (m_ret) {
            uint8_t value4 = RAM8(0x00B0 + battle_defence_work2);
            r->a = (a_all >> 8 << 8) | RAM8(0x0346);
            r->x = (uint8_t)((a_all >> 8 << 8) | value4);
            r->y = value3;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x82E2, 0xC233BE); GUARD_JSR(c, sp_call, 0x82E2); } /* create_boss_projectile_with_graphics_and_palette */
            RETURN_RTS(c);
        } else {
            uint16_t value6 = RAM16(0x00B0 + battle_defence_work2);
            r->a = RAM16(0x0346);
            r->x = (uint8_t)value6;
            r->y = value3;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x82E2, 0xC233BE); GUARD_JSR(c, sp_call, 0x82E2); } /* create_boss_projectile_with_graphics_and_palette */
            RETURN_RTS(c);
        }
    } else {
        uint16_t battle_defence_work3 = RAM16(BATTLE_DEFENCE_WORK);
        uint16_t value8 = RAM16(0x00A9 + battle_defence_work3);
        if (m_ret) {
            uint8_t value9 = RAM8(0x00B0 + battle_defence_work3);
            r->a = (a_all >> 8 << 8) | RAM8(0x0346);
            r->x = (a_all >> 8 << 8) | value9;
            r->y = value8;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x82E2, 0xC233BE); GUARD_JSR(c, sp_call, 0x82E2); } /* create_boss_projectile_with_graphics_and_palette */
            RETURN_RTS(c);
        } else {
            uint16_t value11 = RAM16(0x00B0 + battle_defence_work3);
            r->a = RAM16(0x0346);
            r->x = value11;
            r->y = value8;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x82E2, 0xC233BE); GUARD_JSR(c, sp_call, 0x82E2); } /* create_boss_projectile_with_graphics_and_palette */
            RETURN_RTS(c);
        }
    }
}

/* C282C0 prepare_attack_row_then_create_parent_projectile   [class A, 36 bytes, 16 instructions]
 * Source: src/rom/prepare_attack_row_then_create_parent_projectile.s
 * Documented in docs/boss-native58-grandchildren.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void prepare_attack_row_then_create_parent_projectile_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    RAM8(0x0346) = a;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    RAM8(0x005A + battle_defence_work) = 0;
    uint16_t value = RAM16(0x00B0 + battle_defence_work);
    uint16_t value2 = RAM16(0x0346);
    r->a = value2;
    r->x = value;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x82D4, 0xC0006C); GUARD_JSL(c, sp_call, 0x82D4); } /* boss_attack_row_public_jump */
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        uint8_t battle_defence_work2 = RAM8(BATTLE_DEFENCE_WORK);
        uint8_t value3 = RAM8(0x00A9 + battle_defence_work2);
        if (m_ret) {
            uint8_t value4 = RAM8(0x00B0 + battle_defence_work2);
            r->a = (a_all >> 8 << 8) | RAM8(0x0346);
            r->x = (uint8_t)((a_all >> 8 << 8) | value4);
            r->y = value3;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x82E2, 0xC233BE); GUARD_JSR(c, sp_call, 0x82E2); } /* create_boss_projectile_with_graphics_and_palette */
            RETURN_RTS(c);
        } else {
            uint16_t value6 = RAM16(0x00B0 + battle_defence_work2);
            r->a = RAM16(0x0346);
            r->x = (uint8_t)value6;
            r->y = value3;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x82E2, 0xC233BE); GUARD_JSR(c, sp_call, 0x82E2); } /* create_boss_projectile_with_graphics_and_palette */
            RETURN_RTS(c);
        }
    } else {
        uint16_t battle_defence_work3 = RAM16(BATTLE_DEFENCE_WORK);
        uint16_t value8 = RAM16(0x00A9 + battle_defence_work3);
        if (m_ret) {
            uint8_t value9 = RAM8(0x00B0 + battle_defence_work3);
            r->a = (a_all >> 8 << 8) | RAM8(0x0346);
            r->x = (a_all >> 8 << 8) | value9;
            r->y = value8;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x82E2, 0xC233BE); GUARD_JSR(c, sp_call, 0x82E2); } /* create_boss_projectile_with_graphics_and_palette */
            RETURN_RTS(c);
        } else {
            uint16_t value11 = RAM16(0x00B0 + battle_defence_work3);
            r->a = RAM16(0x0346);
            r->x = value11;
            r->y = value8;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x82E2, 0xC233BE); GUARD_JSR(c, sp_call, 0x82E2); } /* create_boss_projectile_with_graphics_and_palette */
            RETURN_RTS(c);
        }
    }
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void prepare_attack_row_then_create_parent_projectile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { prepare_attack_row_then_create_parent_projectile_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { prepare_attack_row_then_create_parent_projectile_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC282C0, SOM_RTS, "gen", prepare_attack_row_then_create_parent_projectile, 0, 0, 1, -1, -1, 36, 16)
