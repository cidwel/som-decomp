#include "som_c.h"

static void advance_native_actor_effect_cell_toward_live_target(SomCtx *c);
static void advance_native_actor_effect_cell_toward_live_target_v2(SomCtx *c);

/* C18D80 update_native_effect_cells_before_shared_weapon_restore   [class C, 275 bytes, 130 instructions]
 * Source: src/rom/update_native_effect_cells_before_shared_weapon_restore.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void update_native_effect_cells_before_shared_weapon_restore(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp_in = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE110 + x);
    if ((value | RAM8(0xE120 + x) | RAM8(0xE130 + x)) == 0) {
        RAM8(0xE104 + x) = 0;
        uint8_t value4 = RAM8(0xE108 + x);
        if (!(value4 & 0x80)) {
            RAM8(0xE060 + x) = 0;
            if (x < 0x0600) {
                if (x < 0x0600) {
                    r->a = (a_hi << 8) | value4;
                    r->c = x >= 0x0600;
                    r->z = x == 0x0600;
                    r->n = (uint16_t)(x - 0x0600) & 0x8000;
                    { const uint16_t sp_call = r->sp; JSL(c, 0x8DB9, 0x00E9F4); GUARD_JSL(c, sp_call, 0x8DB9); } /* refresh_actor_weapon_graphics_long */
                    r->x = RAM16(0x0014);
                    r->xf = 0;
                    RETURN_RTS(c);
                }
                uint8_t value6 = RAM8(0x005C);
                if (value6 & 0x80) {
                    RAM8(0xE001 + x) = 2;
                    SET_A8(r, 2);
                    r->c = x >= 0x0600;
                    r->v = value6 & 0x40;
                    RETURN_RTS(c);
                }
                r->a = (a_hi << 8) | value4;
                r->c = x >= 0x0600;
                r->z = (value4 & value6) == 0;
                r->n = value6 & 0x80;
                r->v = value6 & 0x40;
                { const uint16_t sp_call = r->sp; JSL(c, 0x8DB9, 0x00E9F4); GUARD_JSL(c, sp_call, 0x8DB9); } /* refresh_actor_weapon_graphics_long */
                r->x = RAM16(0x0014);
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value8 = RAM8(0x00ED);
            if (!(value8 & 0x80)) {
                SET_A8(r, value4);
                r->c = x >= 0x0600;
                r->v = value8 & 0x40;
                RETURN_RTS(c);
            }
            if (x < 0x0600) {
                r->a = (a_hi << 8) | value4;
                r->c = x >= 0x0600;
                r->z = x == 0x0600;
                r->n = (uint16_t)(x - 0x0600) & 0x8000;
                r->v = value8 & 0x40;
                { const uint16_t sp_call = r->sp; JSL(c, 0x8DB9, 0x00E9F4); GUARD_JSL(c, sp_call, 0x8DB9); } /* refresh_actor_weapon_graphics_long */
                r->x = RAM16(0x0014);
                r->xf = 0;
                RETURN_RTS(c);
            }
            uint8_t value10 = RAM8(0x005C);
            if (value10 & 0x80) {
                RAM8(0xE001 + x) = 2;
                SET_A8(r, 2);
                r->c = x >= 0x0600;
                r->v = value10 & 0x40;
                RETURN_RTS(c);
            }
            r->a = (a_hi << 8) | value4;
            r->c = x >= 0x0600;
            r->z = (value4 & value10) == 0;
            r->n = value10 & 0x80;
            r->v = value10 & 0x40;
            { const uint16_t sp_call = r->sp; JSL(c, 0x8DB9, 0x00E9F4); GUARD_JSL(c, sp_call, 0x8DB9); } /* refresh_actor_weapon_graphics_long */
            r->x = RAM16(0x0014);
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = (a_hi << 8) | value4;
        r->y = x;
        r->z = x == 0;
        r->n = x & 0x8000;
        TAIL_CALL(c, 0xC187C2, SOM_RTS); /* transfer_cast_presentation_to_target */
    }
    if (value != 4) {
        r->a = (a_hi << 8) | value;
        r->y = 0;
        r->c = value >= 4;
        r->z = 1;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x8DD4, advance_native_actor_effect_cell_toward_live_target, sp_in, 2); GUARD_JSR(c, sp_call, 0x8DD4); }
        if (r->xf != 0) { c->fail = 3; return; }
        r->y = 0x10;
        r->z = 0;
        r->n = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x8DDA, advance_native_actor_effect_cell_toward_live_target_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0x8DDA); }
        if (r->xf != 0) { c->fail = 3; return; }
        r->y = 0x20;
        r->z = 0;
        r->n = 0;
        advance_native_actor_effect_cell_toward_live_target_v2(c); return;
    }
    SET_A8(r, value);
    r->c = value >= 4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18D80, SOM_RTS, "gen", update_native_effect_cells_before_shared_weapon_restore, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 15, 1, 0, 275, 130)

/* C18DDE advance_native_actor_effect_cell_toward_live_target   [class A, 181 bytes, 90 instructions]
 * Source: src/rom/update_native_effect_cells_before_shared_weapon_restore.s
 * Subroutine of update_native_effect_cells_before_shared_weapon_restore, translated in place.
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void advance_native_actor_effect_cell_toward_live_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(0x0000, y);
    uint16_t value = RAM16(0x0000);
    uint8_t value2 = RAM8(0xE110 + (x | value));
    if (value2 == 0) {
        r->a = ((x | value) >> 8 << 8) | value2;
        r->y = x | value;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0xE114 + (x | value));
    if (value3 == 0) {
        uint8_t value4 = RAM8(0xE113 + (x | value));
        uint8_t value5 = RAM8(0xE115 + (x | value));
        if (value4 < value5) {
            RAM8(0xE113 + (x | value)) = (uint8_t)(value4 + 2);
        }
        RAM8(0x0000 + sp0) = (x | value) >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)(x | value);
        uint8_t value6 = RAM8(0xE117 + (x | value));
        uint8_t value7 = RAM8(0xE000 + ((value6 << 8) | 0));
        if (value7 == 0) {
            RAM8(0xE110 + (x | value)) = 0;
            r->a = (value6 << 8) | 0;
            r->y = x | value;
            r->c = value4 >= value5;
            r->z = (x | value) == 0;
            r->n = (x | value) & 0x8000;
            r->mf = 1;
            RETURN_RTS(c);
        }
        if (!(value7 & 0x80)) {
            RAM16_SET(0x0002, RAM16(0xE112 + (x | value)));
            RAM16_SET(0x000C, RAM16(0xE11C + (x | value)) & 0x0F0F);
            RAM16_SET(0x0004, (uint16_t)(RAM16(0xE118 + (x | value)) + RAM16(0xE020 + x)));
            uint16_t value12 = RAM16(0xE074 + x);
            uint16_t value13 = RAM16(0xE045 + x);
            uint16_t value14 = RAM16(0xE022 + x);
            uint16_t value15 = RAM16(0xE11A + (x | value));
            RAM16_SET(0x0006, (uint16_t)((uint16_t)(((uint16_t)((value12 & 0x7F) + value13) ^ 0xFFFF) + value14 + 1) + value15));
            uint16_t value16 = RAM16(0xE116 + (x | value));
            RAM8(0x0000 + sp0) = (x | value) >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)(x | value);
            r->a = value16;
            r->y = value16;
            r->c = (uint16_t)(((uint16_t)((value12 & 0x7F) + value13) ^ 0xFFFF) + value14 + 1) + value15 > 0xFFFF;
            r->z = value16 == 0;
            r->n = value16 & 0x8000;
            r->v = (((uint16_t)(((uint16_t)((value12 & 0x7F) + value13) ^ 0xFFFF) + value14 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value12 & 0x7F) + value13) ^ 0xFFFF) + value14 + 1) + value15)) & (value15 ^ (uint16_t)((uint16_t)(((uint16_t)((value12 & 0x7F) + value13) ^ 0xFFFF) + value14 + 1) + value15)) & 0x8000) != 0;
            r->mf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8E51, 0xC18E93); GUARD_JSR(c, sp_call, 0x8E51); } /* steer_native_actor_effect_toward_target_with_fractional_sine_motion */
            r->sp += 2;
            uint16_t x_ret = r->x;
            bool carry_ret = r->c;
            uint8_t value17 = RAM8(0x0000 + sp0 - 1);
            uint8_t value18 = RAM8(0x0000 + sp0);
            if (!carry_ret) {
                uint16_t value19 = RAM16(0xE116 + ((value18 << 8) | value17));
                RAM8(0x0000 + sp0) = value18;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)((value18 << 8) | value17);
                RAM8(0x0000 + sp0 - 2) = x_ret >> 8;
                RAM8(0x0000 + sp0 - 3) = (uint8_t)x_ret;
                r->a = value19;
                r->y = value19;
                r->z = value19 == 0;
                r->n = value19 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8E7E, 0xC18D12); GUARD_JSR(c, sp_call, 0x8E7E); } /* deliver_complete_cast_hit_to_target */
                r->sp += 4;
                uint8_t db_ret = r->db;
                bool x_ret2 = r->xf;
                uint16_t a_all2 = r->a;
                bool carry_ret2 = r->c;
                if (carry_ret2) {
                    if (x_ret2) {
                        uint8_t value20 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value21 = RAM8(0x0000 + sp0 - 2);
                        BUS16_SET(c, (db_ret << 0x10) + 0xE116 + value21, a_all2);
                        uint8_t value22 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value23 = RAM8(0x0000 + sp0);
                        r->x = value20;
                        r->y = value21;
                        r->z = value21 == 0;
                        r->n = value21 & 0x80;
                        r->mf = 0;
                        r->xf = 1;
                        TAIL_CALL_DYN(c, 0xC10000 | (uint16_t)(((value23 << 8) | value22) + 1), SOM_RTS); /* jump through a pushed address */
                    } else {
                        uint8_t value24 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value25 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value26 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value27 = RAM8(0x0000 + sp0);
                        BUS16_SET(c, (db_ret << 0x10) + 0xE116 + ((value27 << 8) | value26), a_all2);
                        r->x = (value25 << 8) | value24;
                        r->y = (value27 << 8) | value26;
                        r->z = ((value27 << 8) | value26) == 0;
                        r->n = ((value27 << 8) | value26) & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                }
                if (x_ret2) {
                    uint8_t value28 = RAM8(0x0000 + sp0 - 3);
                    uint8_t value29 = RAM8(0x0000 + sp0 - 2);
                    BUS8_SET(c, (db_ret << 0x10) + 0xE110 + value29, 0);
                    uint8_t value30 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value31 = RAM8(0x0000 + sp0);
                    r->a = (a_all2 >> 8 << 8) | 0;
                    r->x = value28;
                    r->y = value29;
                    r->z = 1;
                    r->n = 0;
                    r->mf = 1;
                    r->xf = 1;
                    TAIL_CALL_DYN(c, 0xC10000 | (uint16_t)(((value31 << 8) | value30) + 1), SOM_RTS); /* jump through a pushed address */
                } else {
                    uint8_t value32 = RAM8(0x0000 + sp0 - 3);
                    uint8_t value33 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value34 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value35 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (db_ret << 0x10) + 0xE110 + ((value35 << 8) | value34), 0);
                    SET_A8(r, 0);
                    r->x = (value33 << 8) | value32;
                    r->y = (value35 << 8) | value34;
                    r->z = 1;
                    r->n = 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            RAM16_SET(0xE112 + ((value18 << 8) | value17), RAM16(0x0002));
            RAM16_SET(0xE11C + ((value18 << 8) | value17), RAM16(0x000C));
            RAM16_SET(0xE118 + ((value18 << 8) | value17), (uint16_t)(RAM16(0x0004) + RAM16(0xE118 + ((value18 << 8) | value17))));
            uint16_t value40 = RAM16(0x0006);
            uint16_t value41 = RAM16(0xE11A + ((value18 << 8) | value17));
            RAM16_SET(0xE11A + ((value18 << 8) | value17), (uint16_t)(value40 + value41));
            r->a = (uint16_t)(value40 + value41);
            r->y = (value18 << 8) | value17;
            r->c = value40 + value41 > 0xFFFF;
            r->z = (uint16_t)(value40 + value41) == 0;
            r->n = (uint16_t)(value40 + value41) & 0x8000;
            r->v = ((value40 ^ (uint16_t)(value40 + value41)) & (value41 ^ (uint16_t)(value40 + value41)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0xE110 + (x | value)) = 0;
        r->a = (value6 << 8) | 0;
        r->y = x | value;
        r->c = value4 >= value5;
        r->z = (x | value) == 0;
        r->n = (x | value) & 0x8000;
        r->mf = 1;
        RETURN_RTS(c);
    }
    RAM8(0xE114 + (x | value)) = (uint8_t)(value3 - 1);
    r->a = ((x | value) >> 8 << 8) | (uint8_t)(value3 - 1);
    r->y = x | value;
    r->z = (uint8_t)(value3 - 1) == 0;
    r->n = (uint8_t)(value3 - 1) & 0x80;
    r->mf = 1;
    RETURN_RTS(c);
}

/* C18DDE advance_native_actor_effect_cell_toward_live_target_v2   [class A, 181 bytes, 90 instructions]
 * Source: src/rom/update_native_effect_cells_before_shared_weapon_restore.s
 * Subroutine of update_native_effect_cells_before_shared_weapon_restore, translated in place.
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void advance_native_actor_effect_cell_toward_live_target_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    BUS16_SET(c, dp, y);
    uint16_t value = BUS16_RDP(c, dp);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xE110 + (x | value));
    if (value2 == 0) {
        r->a = ((x | value) >> 8 << 8) | value2;
        r->y = x | value;
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xE114 + (x | value));
    if (value3 == 0) {
        uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0xE113 + (x | value));
        uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0xE115 + (x | value));
        if (value4 < value5) {
            BUS8_SET(c, (db << 0x10) + 0xE113 + (x | value), (uint8_t)(value4 + 2));
        }
        RAM8(0x0000 + sp0) = (x | value) >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)(x | value);
        uint8_t value6 = BUS8_RDP(c, (db << 0x10) + 0xE117 + (x | value));
        uint8_t value7 = BUS8_RDP(c, (db << 0x10) + 0xE000 + ((value6 << 8) | 0));
        if (value7 == 0) {
            BUS8_SET(c, (db << 0x10) + 0xE110 + (x | value), 0);
            r->a = (value6 << 8) | 0;
            r->y = x | value;
            r->c = value4 >= value5;
            r->z = (x | value) == 0;
            r->n = (x | value) & 0x8000;
            r->mf = 1;
            RETURN_RTS(c);
        }
        if (!(value7 & 0x80)) {
            uint16_t value8 = BUS16_RDP(c, (db << 0x10) + 0xE112 + (x | value));
            BUS16_SET(c, (uint16_t)(dp + 2), value8);
            uint16_t value9 = BUS16_RDP(c, (db << 0x10) + 0xE11C + (x | value));
            BUS16_SET(c, (uint16_t)(dp + 0x0C), value9 & 0x0F0F);
            uint16_t value10 = BUS16_RDP(c, (db << 0x10) + 0xE118 + (x | value));
            uint16_t value11 = BUS16_RDP(c, (db << 0x10) + 0xE020 + x);
            BUS16_SET(c, (uint16_t)(dp + 4), (uint16_t)(value10 + value11));
            uint16_t value12 = BUS16_RDP(c, (db << 0x10) + 0xE074 + x);
            uint16_t value13 = BUS16_RDP(c, (db << 0x10) + 0xE045 + x);
            uint16_t value14 = BUS16_RDP(c, (db << 0x10) + 0xE022 + x);
            uint16_t value15 = BUS16_RDP(c, (db << 0x10) + 0xE11A + (x | value));
            BUS16_SET(c, (uint16_t)(dp + 6), (uint16_t)((uint16_t)(((uint16_t)((value12 & 0x7F) + value13) ^ 0xFFFF) + value14 + 1) + value15));
            uint16_t value16 = BUS16_RDP(c, (db << 0x10) + 0xE116 + (x | value));
            RAM8(0x0000 + sp0) = (x | value) >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)(x | value);
            r->a = value16;
            r->y = value16;
            r->c = (uint16_t)(((uint16_t)((value12 & 0x7F) + value13) ^ 0xFFFF) + value14 + 1) + value15 > 0xFFFF;
            r->z = value16 == 0;
            r->n = value16 & 0x8000;
            r->v = (((uint16_t)(((uint16_t)((value12 & 0x7F) + value13) ^ 0xFFFF) + value14 + 1) ^ (uint16_t)((uint16_t)(((uint16_t)((value12 & 0x7F) + value13) ^ 0xFFFF) + value14 + 1) + value15)) & (value15 ^ (uint16_t)((uint16_t)(((uint16_t)((value12 & 0x7F) + value13) ^ 0xFFFF) + value14 + 1) + value15)) & 0x8000) != 0;
            r->mf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8E51, 0xC18E93); GUARD_JSR(c, sp_call, 0x8E51); } /* steer_native_actor_effect_toward_target_with_fractional_sine_motion */
            r->sp += 2;
            uint16_t x_ret = r->x;
            bool carry_ret = r->c;
            uint8_t value17 = RAM8(0x0000 + sp0 - 1);
            uint8_t value18 = RAM8(0x0000 + sp0);
            if (!carry_ret) {
                uint16_t value19 = BUS16_RDP(c, (db << 0x10) + 0xE116 + ((value18 << 8) | value17));
                RAM8(0x0000 + sp0) = value18;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)((value18 << 8) | value17);
                RAM8(0x0000 + sp0 - 2) = x_ret >> 8;
                RAM8(0x0000 + sp0 - 3) = (uint8_t)x_ret;
                r->a = value19;
                r->y = value19;
                r->z = value19 == 0;
                r->n = value19 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8E7E, 0xC18D12); GUARD_JSR(c, sp_call, 0x8E7E); } /* deliver_complete_cast_hit_to_target */
                r->sp += 4;
                uint8_t db_ret = r->db;
                bool x_ret2 = r->xf;
                uint16_t a_all2 = r->a;
                bool carry_ret2 = r->c;
                if (carry_ret2) {
                    if (x_ret2) {
                        uint8_t value20 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value21 = RAM8(0x0000 + sp0 - 2);
                        BUS16_SET(c, (db_ret << 0x10) + 0xE116 + value21, a_all2);
                        uint8_t value22 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value23 = RAM8(0x0000 + sp0);
                        r->x = value20;
                        r->y = value21;
                        r->z = value21 == 0;
                        r->n = value21 & 0x80;
                        r->mf = 0;
                        r->xf = 1;
                        TAIL_CALL_DYN(c, 0xC10000 | (uint16_t)(((value23 << 8) | value22) + 1), SOM_RTS); /* jump through a pushed address */
                    } else {
                        uint8_t value24 = RAM8(0x0000 + sp0 - 3);
                        uint8_t value25 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value26 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value27 = RAM8(0x0000 + sp0);
                        BUS16_SET(c, (db_ret << 0x10) + 0xE116 + ((value27 << 8) | value26), a_all2);
                        r->x = (value25 << 8) | value24;
                        r->y = (value27 << 8) | value26;
                        r->z = ((value27 << 8) | value26) == 0;
                        r->n = ((value27 << 8) | value26) & 0x8000;
                        r->mf = 0;
                        r->xf = 0;
                        RETURN_RTS(c);
                    }
                }
                if (x_ret2) {
                    uint8_t value28 = RAM8(0x0000 + sp0 - 3);
                    uint8_t value29 = RAM8(0x0000 + sp0 - 2);
                    BUS8_SET(c, (db_ret << 0x10) + 0xE110 + value29, 0);
                    uint8_t value30 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value31 = RAM8(0x0000 + sp0);
                    r->a = (a_all2 >> 8 << 8) | 0;
                    r->x = value28;
                    r->y = value29;
                    r->z = 1;
                    r->n = 0;
                    r->mf = 1;
                    r->xf = 1;
                    TAIL_CALL_DYN(c, 0xC10000 | (uint16_t)(((value31 << 8) | value30) + 1), SOM_RTS); /* jump through a pushed address */
                } else {
                    uint8_t value32 = RAM8(0x0000 + sp0 - 3);
                    uint8_t value33 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value34 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value35 = RAM8(0x0000 + sp0);
                    BUS8_SET(c, (db_ret << 0x10) + 0xE110 + ((value35 << 8) | value34), 0);
                    SET_A8(r, 0);
                    r->x = (value33 << 8) | value32;
                    r->y = (value35 << 8) | value34;
                    r->z = 1;
                    r->n = 0;
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTS(c);
                }
            }
            uint16_t value36 = BUS16_RDP(c, (uint16_t)(dp + 2));
            BUS16_SET(c, (db << 0x10) + 0xE112 + ((value18 << 8) | value17), value36);
            uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp + 0x0C));
            BUS16_SET(c, (db << 0x10) + 0xE11C + ((value18 << 8) | value17), value37);
            uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp + 4));
            uint16_t value39 = BUS16_RDP(c, (db << 0x10) + 0xE118 + ((value18 << 8) | value17));
            BUS16_SET(c, (db << 0x10) + 0xE118 + ((value18 << 8) | value17), (uint16_t)(value38 + value39));
            uint16_t value40 = BUS16_RDP(c, (uint16_t)(dp + 6));
            uint16_t value41 = BUS16_RDP(c, (db << 0x10) + 0xE11A + ((value18 << 8) | value17));
            BUS16_SET(c, (db << 0x10) + 0xE11A + ((value18 << 8) | value17), (uint16_t)(value40 + value41));
            r->a = (uint16_t)(value40 + value41);
            r->y = (value18 << 8) | value17;
            r->c = value40 + value41 > 0xFFFF;
            r->z = (uint16_t)(value40 + value41) == 0;
            r->n = (uint16_t)(value40 + value41) & 0x8000;
            r->v = ((value40 ^ (uint16_t)(value40 + value41)) & (value41 ^ (uint16_t)(value40 + value41)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        BUS8_SET(c, (db << 0x10) + 0xE110 + (x | value), 0);
        r->a = (value6 << 8) | 0;
        r->y = x | value;
        r->c = value4 >= value5;
        r->z = (x | value) == 0;
        r->n = (x | value) & 0x8000;
        r->mf = 1;
        RETURN_RTS(c);
    }
    BUS8_SET(c, (db << 0x10) + 0xE114 + (x | value), (uint8_t)(value3 - 1));
    r->a = ((x | value) >> 8 << 8) | (uint8_t)(value3 - 1);
    r->y = x | value;
    r->z = (uint8_t)(value3 - 1) == 0;
    r->n = (uint8_t)(value3 - 1) & 0x80;
    r->mf = 1;
    RETURN_RTS(c);
}
