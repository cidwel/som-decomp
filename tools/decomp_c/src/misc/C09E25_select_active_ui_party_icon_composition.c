#include "som_c.h"

static void publish_single_ui_party_icon(SomCtx *c);

/* C09E25 select_active_ui_party_icon_composition   [class C, 208 bytes, 94 instructions]
 * Source: src/rom/select_active_ui_party_icon_composition.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void select_active_ui_party_icon_composition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0xE000);
    if (value == 0) {
        uint8_t value2 = RAM8(0xE200);
        if (value2 == 0) {
            r->a = (a_hi << 8) | 0x20;
            r->z = 0;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        if (value2 & 0x80) {
            r->a = (a_hi << 8) | 0x20;
            r->z = 0;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        uint8_t value3 = RAM8(0xE400);
        if (value3 == 0) {
            r->a = (a_hi << 8) | 0x10;
            r->z = 0;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        if (value3 & 0x80) {
            r->a = (a_hi << 8) | 0x10;
            r->z = 0;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        RAM8(0x0000 + sp0) = 0x20;
        RAM8(0x0000 + sp0 - 1) = 0x10;
        r->a = 0x2010;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9E7D, publish_single_ui_party_icon, sp_in, 2); GUARD_JSR(c, sp_call, 0x9E7D); }
        r->sp += 2;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool x_ret = r->xf;
        uint8_t value4 = RAM8(0x0000 + sp0 - 1);
        uint8_t value5 = RAM8(0x0000 + sp0);
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9C));
        if (x_ret) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (uint16_t)(((((uint8_t)((value5 << 8) | value4) << 8) | value5) & 0xFF) + value6);
            r->x = 0x80;
            r->y = 0x90;
            r->c = ((((uint8_t)((value5 << 8) | value4) << 8) | value5) & 0xFF) + value6 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((((((uint8_t)((value5 << 8) | value4) << 8) | value5) & 0xFF) ^ (uint16_t)(((((uint8_t)((value5 << 8) | value4) << 8) | value5) & 0xFF) + value6)) & (value6 ^ (uint16_t)(((((uint8_t)((value5 << 8) | value4) << 8) | value5) & 0xFF) + value6)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9E90, 0xC09EF5); GUARD_JSR(c, sp_call, 0x9E90); } /* forward_ui_party_icon_to_native_packed_sprite_emitter */
            uint8_t value7 = BUS8_RDP(c, (db_ret << 0x10) + 0x0A01);
            BUS8_SET(c, (db_ret << 0x10) + 0x0A01, value7 | 0xAA);
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    if (value & 0x80) {
        uint8_t value8 = RAM8(0xE200);
        if (value8 == 0) {
            r->a = (a_hi << 8) | 0x20;
            r->z = 0;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        if (value8 & 0x80) {
            r->a = (a_hi << 8) | 0x20;
            r->z = 0;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        uint8_t value9 = RAM8(0xE400);
        if (value9 == 0) {
            r->a = (a_hi << 8) | 0x10;
            r->z = 0;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        if (value9 & 0x80) {
            r->a = (a_hi << 8) | 0x10;
            r->z = 0;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        RAM8(0x0000 + sp0) = 0x20;
        RAM8(0x0000 + sp0 - 1) = 0x10;
        r->a = 0x2010;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9E7D, publish_single_ui_party_icon, sp_in, 2); GUARD_JSR(c, sp_call, 0x9E7D); }
        r->sp += 2;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool x_ret5 = r->xf;
        uint8_t value10 = RAM8(0x0000 + sp0 - 1);
        uint8_t value11 = RAM8(0x0000 + sp0);
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x9C));
        if (x_ret5) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (uint16_t)(((((uint8_t)((value11 << 8) | value10) << 8) | value11) & 0xFF) + value12);
            r->x = 0x80;
            r->y = 0x90;
            r->c = ((((uint8_t)((value11 << 8) | value10) << 8) | value11) & 0xFF) + value12 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((((((uint8_t)((value11 << 8) | value10) << 8) | value11) & 0xFF) ^ (uint16_t)(((((uint8_t)((value11 << 8) | value10) << 8) | value11) & 0xFF) + value12)) & (value12 ^ (uint16_t)(((((uint8_t)((value11 << 8) | value10) << 8) | value11) & 0xFF) + value12)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9E90, 0xC09EF5); GUARD_JSR(c, sp_call, 0x9E90); } /* forward_ui_party_icon_to_native_packed_sprite_emitter */
            uint8_t value13 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x0A01);
            BUS8_SET(c, (db_ret2 << 0x10) + 0x0A01, value13 | 0xAA);
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    uint8_t value14 = RAM8(0xE200);
    if (value14 == 0) {
        uint8_t value15 = RAM8(0xE400);
        if (value15 == 0) {
            r->a = (a_hi << 8) | 0;
            r->z = 1;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        if (value15 & 0x80) {
            r->a = (a_hi << 8) | 0;
            r->z = 1;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        RAM8(0x0000 + sp0) = 0x20;
        RAM8(0x0000 + sp0 - 1) = 0;
        r->a = 0x2000;
        r->z = 1;
        r->n = 0;
        r->mf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9E7D, publish_single_ui_party_icon, sp_in, 2); GUARD_JSR(c, sp_call, 0x9E7D); }
        r->sp += 2;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool x_ret9 = r->xf;
        uint8_t value16 = RAM8(0x0000 + sp0 - 1);
        uint8_t value17 = RAM8(0x0000 + sp0);
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x9C));
        if (x_ret9) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (uint16_t)(((((uint8_t)((value17 << 8) | value16) << 8) | value17) & 0xFF) + value18);
            r->x = 0x80;
            r->y = 0x90;
            r->c = ((((uint8_t)((value17 << 8) | value16) << 8) | value17) & 0xFF) + value18 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((((((uint8_t)((value17 << 8) | value16) << 8) | value17) & 0xFF) ^ (uint16_t)(((((uint8_t)((value17 << 8) | value16) << 8) | value17) & 0xFF) + value18)) & (value18 ^ (uint16_t)(((((uint8_t)((value17 << 8) | value16) << 8) | value17) & 0xFF) + value18)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9E90, 0xC09EF5); GUARD_JSR(c, sp_call, 0x9E90); } /* forward_ui_party_icon_to_native_packed_sprite_emitter */
            uint8_t value19 = BUS8_RDP(c, (db_ret3 << 0x10) + 0x0A01);
            BUS8_SET(c, (db_ret3 << 0x10) + 0x0A01, value19 | 0xAA);
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    if (value14 & 0x80) {
        uint8_t value20 = RAM8(0xE400);
        if (value20 == 0) {
            r->a = (a_hi << 8) | 0;
            r->z = 1;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        if (value20 & 0x80) {
            r->a = (a_hi << 8) | 0;
            r->z = 1;
            r->n = 0;
            publish_single_ui_party_icon(c); return;
        }
        RAM8(0x0000 + sp0) = 0x20;
        RAM8(0x0000 + sp0 - 1) = 0;
        r->a = 0x2000;
        r->z = 1;
        r->n = 0;
        r->mf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9E7D, publish_single_ui_party_icon, sp_in, 2); GUARD_JSR(c, sp_call, 0x9E7D); }
        r->sp += 2;
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        bool x_ret13 = r->xf;
        uint8_t value21 = RAM8(0x0000 + sp0 - 1);
        uint8_t value22 = RAM8(0x0000 + sp0);
        uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 0x9C));
        if (x_ret13) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (uint16_t)(((((uint8_t)((value22 << 8) | value21) << 8) | value22) & 0xFF) + value23);
            r->x = 0x80;
            r->y = 0x90;
            r->c = ((((uint8_t)((value22 << 8) | value21) << 8) | value22) & 0xFF) + value23 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((((((uint8_t)((value22 << 8) | value21) << 8) | value22) & 0xFF) ^ (uint16_t)(((((uint8_t)((value22 << 8) | value21) << 8) | value22) & 0xFF) + value23)) & (value23 ^ (uint16_t)(((((uint8_t)((value22 << 8) | value21) << 8) | value22) & 0xFF) + value23)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9E90, 0xC09EF5); GUARD_JSR(c, sp_call, 0x9E90); } /* forward_ui_party_icon_to_native_packed_sprite_emitter */
            uint8_t value24 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x0A01);
            BUS8_SET(c, (db_ret4 << 0x10) + 0x0A01, value24 | 0xAA);
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    uint8_t value25 = RAM8(0xE400);
    if (value25 == 0) {
        RAM8(0x0000 + sp0) = 0x10;
        RAM8(0x0000 + sp0 - 1) = 0;
        r->a = 0x1000;
        r->z = 1;
        r->n = 0;
        r->mf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9E7D, publish_single_ui_party_icon, sp_in, 2); GUARD_JSR(c, sp_call, 0x9E7D); }
        r->sp += 2;
        uint16_t dp_ret5 = r->dp;
        uint8_t db_ret5 = r->db;
        bool x_ret17 = r->xf;
        uint8_t value26 = RAM8(0x0000 + sp0 - 1);
        uint8_t value27 = RAM8(0x0000 + sp0);
        uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 0x9C));
        if (x_ret17) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (uint16_t)(((((uint8_t)((value27 << 8) | value26) << 8) | value27) & 0xFF) + value28);
            r->x = 0x80;
            r->y = 0x90;
            r->c = ((((uint8_t)((value27 << 8) | value26) << 8) | value27) & 0xFF) + value28 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((((((uint8_t)((value27 << 8) | value26) << 8) | value27) & 0xFF) ^ (uint16_t)(((((uint8_t)((value27 << 8) | value26) << 8) | value27) & 0xFF) + value28)) & (value28 ^ (uint16_t)(((((uint8_t)((value27 << 8) | value26) << 8) | value27) & 0xFF) + value28)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9E90, 0xC09EF5); GUARD_JSR(c, sp_call, 0x9E90); } /* forward_ui_party_icon_to_native_packed_sprite_emitter */
            uint8_t value29 = BUS8_RDP(c, (db_ret5 << 0x10) + 0x0A01);
            BUS8_SET(c, (db_ret5 << 0x10) + 0x0A01, value29 | 0xAA);
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    if (value25 & 0x80) {
        RAM8(0x0000 + sp0) = 0x10;
        RAM8(0x0000 + sp0 - 1) = 0;
        r->a = 0x1000;
        r->z = 1;
        r->n = 0;
        r->mf = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9E7D, publish_single_ui_party_icon, sp_in, 2); GUARD_JSR(c, sp_call, 0x9E7D); }
        r->sp += 2;
        uint16_t dp_ret6 = r->dp;
        uint8_t db_ret6 = r->db;
        bool x_ret21 = r->xf;
        uint8_t value30 = RAM8(0x0000 + sp0 - 1);
        uint8_t value31 = RAM8(0x0000 + sp0);
        uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 0x9C));
        if (x_ret21) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (uint16_t)(((((uint8_t)((value31 << 8) | value30) << 8) | value31) & 0xFF) + value32);
            r->x = 0x80;
            r->y = 0x90;
            r->c = ((((uint8_t)((value31 << 8) | value30) << 8) | value31) & 0xFF) + value32 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((((((uint8_t)((value31 << 8) | value30) << 8) | value31) & 0xFF) ^ (uint16_t)(((((uint8_t)((value31 << 8) | value30) << 8) | value31) & 0xFF) + value32)) & (value32 ^ (uint16_t)(((((uint8_t)((value31 << 8) | value30) << 8) | value31) & 0xFF) + value32)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9E90, 0xC09EF5); GUARD_JSR(c, sp_call, 0x9E90); } /* forward_ui_party_icon_to_native_packed_sprite_emitter */
            uint8_t value33 = BUS8_RDP(c, (db_ret6 << 0x10) + 0x0A01);
            BUS8_SET(c, (db_ret6 << 0x10) + 0x0A01, value33 | 0xAA);
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    r->a = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0x9EBF, publish_single_ui_party_icon, sp_in, 2); GUARD_JSR(c, sp_call, 0x9EBF); }
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret7 = r->db;
    bool x_ret25 = r->xf;
    uint16_t value34 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9C));
    if (x_ret25) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        r->a = (uint16_t)(value34 + 0x10);
        r->x = 0x60;
        r->y = 0x80;
        r->c = value34 + 0x10 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = ((value34 ^ (uint16_t)(value34 + 0x10)) & ((uint16_t)(value34 + 0x10) ^ 0x10) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9ED0, 0xC09EF5); GUARD_JSR(c, sp_call, 0x9ED0); } /* forward_ui_party_icon_to_native_packed_sprite_emitter */
        bool x_ret27 = r->xf;
        uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x9C));
        if (x_ret27) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->a = (uint16_t)(value35 + 0x20);
            r->x = 0xA0;
            r->y = 0x80;
            r->c = value35 + 0x20 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((value35 ^ (uint16_t)(value35 + 0x20)) & ((uint16_t)(value35 + 0x20) ^ 0x20) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9EE1, 0xC09EF5); GUARD_JSR(c, sp_call, 0x9EE1); } /* forward_ui_party_icon_to_native_packed_sprite_emitter */
            uint8_t value36 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x0A01);
            BUS8_SET(c, (db_ret7 << 0x10) + 0x0A01, value36 | 0xAA);
            uint8_t value37 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x0A02);
            BUS8_SET(c, (db_ret7 << 0x10) + 0x0A02, value37 | 0xAA);
            r->mf = 1;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC09E25, SOM_RTS, "gen", select_active_ui_party_icon_composition, 0, L_B | L_X | L_Y | L_C | L_V, 6, 1, 0, 208, 94)

/* C09E9C publish_single_ui_party_icon   [class A, 28 bytes, 12 instructions]
 * Source: src/rom/select_active_ui_party_icon_composition.s
 * Subroutine of select_active_ui_party_icon_composition, translated in place.
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_single_ui_party_icon(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x009C);
    r->a = (uint16_t)((a & 0xFF) + value);
    r->x = 0x80;
    r->y = 0x70;
    r->c = (a & 0xFF) + value > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = (((a & 0xFF) ^ (uint16_t)((a & 0xFF) + value)) & (value ^ (uint16_t)((a & 0xFF) + value)) & 0x8000) != 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9EAC, 0xC09EF5); GUARD_JSR(c, sp_call, 0x9EAC); } /* forward_ui_party_icon_to_native_packed_sprite_emitter */
    uint8_t value2 = RAM8(0x0A00);
    RAM8(0x0A00) = value2 | 0xAA;
    SET_A8(r, value2 | 0xAA);
    r->z = (value2 | 0xAA) == 0;
    r->n = (value2 | 0xAA) & 0x80;
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
