#include "som_c.h"

/* C1DC8F initialize_party_for_map_entry   [class B, 215 bytes, 85 instructions]
 * Source: src/rom/initialize_party_for_map_entry.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_party_for_map_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDC92, 0x02AEF4); GUARD_JSL(c, sp_call, 0xDC92); } /* copy_actor_velocity_presets_to_wram */
    uint8_t db_ret = r->db;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM8(0x0000 + sp0) = db_ret;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    uint16_t x1 = 0x03FE;
    for (;;) {
        RAM16_SET(0x0C00 + x1, 0xCB00);
        x1 = (uint16_t)(x1 - 2);
        if (!(!(x1 & 0x8000))) break;
    }
    uint16_t x2 = 0x01FE;
    for (;;) {
        RAM16_SET(0xD000 + x2, 0);
        x2 = (uint16_t)(x2 - 2);
        if (!(!(x2 & 0x8000))) break;
    }
    RAM16_SET(0xE06E, 0x0C00);
    RAM16_SET(0xE26E, 0x0C20);
    RAM16_SET(0xE46E, 0x0C40);
    RAM16_SET(0xE06C, 0x0C60);
    RAM16_SET(0xE26C, 0x0CB0);
    RAM16_SET(0xE46C, 0x0D00);
    uint16_t value = RAM16(0x0098);
    RAM16_SET(0xE08A, value ^ 0x23C0);
    RAM16_SET(0xE28A, value ^ 0x25C8);
    RAM16_SET(0xE48A, value ^ 0x27E0);
    RAM16_SET(0xE086, value ^ 0x0144);
    RAM16_SET(0xE286, value ^ 0x0168);
    RAM16_SET(0xE486, value ^ 0x018C);
    r->a = value ^ 0x018C;
    r->x = x2;
    r->y = y_ret;
    r->c = carry_ret;
    r->z = (value ^ 0x018C) == 0;
    r->n = (value ^ 0x018C) & 0x8000;
    r->v = overflow_ret;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDD0B, 0xC1DF96); GUARD_JSR(c, sp_call, 0xDD0B); } /* assign_party_palette_rows */
    r->sp += 1;
    r->x = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDD11, 0xC1E06F); GUARD_JSR(c, sp_call, 0xDD11); } /* prepare_and_place_party_actor */
    r->sp += 1;
    r->x = 0x0200;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDD17, 0xC1E06F); GUARD_JSR(c, sp_call, 0xDD17); } /* prepare_and_place_party_actor */
    r->sp += 1;
    r->x = 0x0400;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDD1D, 0xC1E06F); GUARD_JSR(c, sp_call, 0xDD1D); } /* prepare_and_place_party_actor */
    r->sp += 1;
    uint16_t a_all5 = r->a;
    RAM8(0xE01E) = 8;
    RAM8(0xE21E) = 4;
    RAM8(0xE41E) = 0;
    r->a = (a_all5 >> 8 << 8) | 1;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDD33, 0xC1DF0A); GUARD_JSR(c, sp_call, 0xDD33); } /* find_actor_controller_binding */
    r->sp += 1;
    uint16_t a_all6 = r->a;
    RAM8(0xE02C) = (uint8_t)a_all6;
    r->a = (a_all6 >> 8 << 8) | 2;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDD3B, 0xC1DF0A); GUARD_JSR(c, sp_call, 0xDD3B); } /* find_actor_controller_binding */
    r->sp += 1;
    uint16_t a_all7 = r->a;
    RAM8(0xE22C) = (uint8_t)a_all7;
    r->a = (a_all7 >> 8 << 8) | 4;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDD43, 0xC1DF0A); GUARD_JSR(c, sp_call, 0xDD43); } /* find_actor_controller_binding */
    r->sp += 1;
    uint16_t a_all8 = r->a;
    RAM8(0xE42C) = (uint8_t)a_all8;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDD49, 0xC1DF26); GUARD_JSR(c, sp_call, 0xDD49); } /* initialize_party_tile_state */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDD4C, 0xC1DD66); GUARD_JSR(c, sp_call, 0xDD4C); } /* prepare_party_entry_walk */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xDD4F, 0xC1DE00); GUARD_JSR(c, sp_call, 0xDD4F); } /* start_uncontrolled_party_programs */
    r->sp += 1;
    uint16_t value2 = RAM16(0x010E);
    bool m_flag;
    uint8_t a1;
    if (value2 != 0) {
        m_flag = 0;
        a1 = (uint8_t)value2;
    } else {
        RAM8(0xE00E) = 0x80;
        RAM8(0xE20E) = 0x80;
        RAM8(0xE40E) = 0x80;
        m_flag = 1;
        a1 = 0x80;
    }
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->a = (value2 >> 8 << 8) | a1;
    r->mf = m_flag;
    r->db = value3;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1DC8F, SOM_RTL, "gen", initialize_party_for_map_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 215, 85)
