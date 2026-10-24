#include "som_c.h"

/* C07DB1 remove_native_sold_inventory_quantity_or_detach_equipment_and_compact   [class B, 127 bytes, 59 instructions]
 * Source: src/rom/remove_native_sold_inventory_quantity_or_detach_equipment_and_compact.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void remove_native_sold_inventory_quantity_or_detach_equipment_and_compact(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x183E);
    uint16_t value2 = RAM16(0xCC00 + value);
    if (value < 0x48) {
        if (((uint8_t)value2 & 0xC0) == 0) {
            RAM8(0x1804) &= 0xBF;
            uint16_t value4 = RAM16(0x1840);
            RAM16_SET(0x1851, (uint16_t)(value4 + 0x0B));
            uint8_t a_hi1 = (uint16_t)(value4 + 0x0B) >> 8;
            uint16_t x1 = value;
            bool carry1 = value4 + 0x0B > 0xFFFF;
            bool first_pass = true;
            for (;;) {
                if (first_pass) {
                    uint8_t value5 = RAM8(0xCC00 + (uint16_t)(x1 + 1));
                    uint16_t value6 = RAM16(0x1851);
                    if ((uint16_t)(x1 + 1) == value6) {
                        uint16_t x1_next2 = (uint16_t)(x1 + 1);
                        bool carry1_next2 = (uint16_t)(x1 + 1) >= value6;
                        x1 = x1_next2;
                        carry1 = carry1_next2;
                        break;
                    }
                    RAM8(0xCBFF + (uint16_t)(x1 + 1)) = value5;
                    uint16_t x1_next = (uint16_t)(x1 + 1);
                    bool carry1_next = (uint16_t)(x1 + 1) >= value6;
                    x1 = x1_next;
                    carry1 = carry1_next;
                    first_pass = false;
                    continue;
                } else {
                    uint8_t value7 = RAM8(0xCC00 + (uint16_t)(x1 + 1));
                    uint16_t value8 = RAM16(0x1851);
                    if ((uint16_t)(x1 + 1) == value8) {
                        uint16_t x1_next4 = (uint16_t)(x1 + 1);
                        bool carry1_next4 = (uint16_t)(x1 + 1) >= value8;
                        x1 = x1_next4;
                        carry1 = carry1_next4;
                        break;
                    }
                    RAM8(0xCBFF + (uint16_t)(x1 + 1)) = value7;
                    uint16_t x1_next3 = (uint16_t)(x1 + 1);
                    bool carry1_next3 = (uint16_t)(x1 + 1) >= value8;
                    x1 = x1_next3;
                    carry1 = carry1_next3;
                    continue;
                }
            }
            RAM8(0xCBFF + x1) = 0xFF;
            r->a = 0;
            r->x = x1;
            r->y = 0x0B;
            r->c = carry1;
            r->z = 1;
            r->n = 0;
            r->v = (((uint16_t)(value4 + 0x0B) ^ 0x0B) & (value4 ^ (uint16_t)(value4 + 0x0B)) & 0x8000) != 0;
            RETURN_RTS(c);
        }
        RAM8(0x0000 + sp0) = value >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)value;
        RAM8(0x0000 + sp0 - 2) = 0;
        RAM8(0x0000 + sp0 - 3) = 0x0B;
        uint16_t value9 = RAM16(0x184F);
        RAM8(0xE180 + (uint16_t)(((((value2 >> 8 << 8) | (uint8_t)((uint8_t)value2 - 0x40)) & 0xC0) << 1 << 1 << 1) + value9)) = 0x15;
        r->a = (uint16_t)(((((value2 >> 8 << 8) | (uint8_t)((uint8_t)value2 - 0x40)) & 0xC0) << 1 << 1 << 1) + value9) & 0x0600;
        r->x = (uint16_t)(((((value2 >> 8 << 8) | (uint8_t)((uint8_t)value2 - 0x40)) & 0xC0) << 1 << 1 << 1) + value9) & 0x0600;
        r->y = 0x0B;
        r->c = ((((value2 >> 8 << 8) | (uint8_t)((uint8_t)value2 - 0x40)) & 0xC0) << 1 << 1 << 1) + value9 > 0xFFFF;
        r->z = ((uint16_t)(((((value2 >> 8 << 8) | (uint8_t)((uint8_t)value2 - 0x40)) & 0xC0) << 1 << 1 << 1) + value9) & 0x0600) == 0;
        r->n = (uint16_t)(((((value2 >> 8 << 8) | (uint8_t)((uint8_t)value2 - 0x40)) & 0xC0) << 1 << 1 << 1) + value9) & 0x0600 & 0x8000;
        r->v = ((((((value2 >> 8 << 8) | (uint8_t)((uint8_t)value2 - 0x40)) & 0xC0) << 1 << 1 << 1) ^ (uint16_t)(((((value2 >> 8 << 8) | (uint8_t)((uint8_t)value2 - 0x40)) & 0xC0) << 1 << 1 << 1) + value9)) & (value9 ^ (uint16_t)(((((value2 >> 8 << 8) | (uint8_t)((uint8_t)value2 - 0x40)) & 0xC0) << 1 << 1 << 1) + value9)) & 0x8000) != 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x7DFE, 0xC00036); GUARD_JSL(c, sp_call, 0x7DFE); } /* rebuild_actor_stats_public_jump */
        r->sp += 4;
        uint8_t db_ret = r->db;
        bool x_ret = r->xf;
        if (x_ret) {
            uint8_t value10 = RAM8(0x0000 + sp0 - 3);
            uint8_t value11 = RAM8(0x0000 + sp0 - 2);
            uint8_t value12 = BUS8_RDP(c, (db_ret << 0x10) + 0x1804);
            BUS8_SET(c, (db_ret << 0x10) + 0x1804, value12 & 0xBF);
            uint16_t value13 = BUS16_RDP(c, (db_ret << 0x10) + 0x1840);
            BUS16_SET(c, (db_ret << 0x10) + 0x1851, (uint16_t)(value10 + value13));
            uint8_t a_hi2 = (uint16_t)(value10 + value13) >> 8;
            uint16_t x2 = value11;
            bool carry2 = value10 + value13 > 0xFFFF;
            bool first_pass2 = true;
            for (;;) {
                if (first_pass2) {
                    uint8_t value14 = RAM8(0xCC00 + (uint16_t)(x2 + 1));
                    uint16_t value15 = BUS16_RDP(c, (db_ret << 0x10) + 0x1851);
                    if ((uint16_t)(x2 + 1) == value15) {
                        uint16_t x2_next2 = (uint16_t)(x2 + 1);
                        bool carry2_next2 = (uint16_t)(x2 + 1) >= value15;
                        x2 = x2_next2;
                        carry2 = carry2_next2;
                        break;
                    }
                    RAM8(0xCBFF + (uint16_t)(x2 + 1)) = value14;
                    uint16_t x2_next = (uint16_t)(x2 + 1);
                    bool carry2_next = (uint16_t)(x2 + 1) >= value15;
                    x2 = x2_next;
                    carry2 = carry2_next;
                    first_pass2 = false;
                    continue;
                } else {
                    uint8_t value16 = RAM8(0xCC00 + (uint16_t)(x2 + 1));
                    uint16_t value17 = BUS16_RDP(c, (db_ret << 0x10) + 0x1851);
                    if ((uint16_t)(x2 + 1) == value17) {
                        uint16_t x2_next4 = (uint16_t)(x2 + 1);
                        bool carry2_next4 = (uint16_t)(x2 + 1) >= value17;
                        x2 = x2_next4;
                        carry2 = carry2_next4;
                        break;
                    }
                    RAM8(0xCBFF + (uint16_t)(x2 + 1)) = value16;
                    uint16_t x2_next3 = (uint16_t)(x2 + 1);
                    bool carry2_next3 = (uint16_t)(x2 + 1) >= value17;
                    x2 = x2_next3;
                    carry2 = carry2_next3;
                    continue;
                }
            }
            RAM8(0xCBFF + x2) = 0xFF;
            uint8_t value18 = RAM8(0x0000 + sp0 - 1);
            uint8_t value19 = RAM8(0x0000 + sp0);
            r->a = 0;
            r->x = x2;
            r->y = value10;
            r->c = carry2;
            r->z = 1;
            r->n = 0;
            r->v = ((value10 ^ (uint16_t)(value10 + value13)) & (value13 ^ (uint16_t)(value10 + value13)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            TAIL_CALL_DYN(c, 0xC00000 | (uint16_t)(((value19 << 8) | value18) + 1), SOM_RTS); /* jump through a pushed address */
        } else {
            uint8_t value20 = RAM8(0x0000 + sp0 - 3);
            uint8_t value21 = RAM8(0x0000 + sp0 - 2);
            uint8_t value22 = RAM8(0x0000 + sp0 - 1);
            uint8_t value23 = RAM8(0x0000 + sp0);
            uint8_t value24 = BUS8_RDP(c, (db_ret << 0x10) + 0x1804);
            BUS8_SET(c, (db_ret << 0x10) + 0x1804, value24 & 0xBF);
            uint16_t value25 = BUS16_RDP(c, (db_ret << 0x10) + 0x1840);
            BUS16_SET(c, (db_ret << 0x10) + 0x1851, (uint16_t)(((value21 << 8) | value20) + value25));
            uint8_t a_hi3 = (uint16_t)(((value21 << 8) | value20) + value25) >> 8;
            uint16_t x3 = (value23 << 8) | value22;
            bool carry3 = ((value21 << 8) | value20) + value25 > 0xFFFF;
            bool first_pass3 = true;
            for (;;) {
                if (first_pass3) {
                    uint8_t value26 = RAM8(0xCC00 + (uint16_t)(x3 + 1));
                    uint16_t value27 = BUS16_RDP(c, (db_ret << 0x10) + 0x1851);
                    if ((uint16_t)(x3 + 1) == value27) {
                        uint16_t x3_next2 = (uint16_t)(x3 + 1);
                        bool carry3_next2 = (uint16_t)(x3 + 1) >= value27;
                        x3 = x3_next2;
                        carry3 = carry3_next2;
                        break;
                    }
                    RAM8(0xCBFF + (uint16_t)(x3 + 1)) = value26;
                    uint16_t x3_next = (uint16_t)(x3 + 1);
                    bool carry3_next = (uint16_t)(x3 + 1) >= value27;
                    x3 = x3_next;
                    carry3 = carry3_next;
                    first_pass3 = false;
                    continue;
                } else {
                    uint8_t value28 = RAM8(0xCC00 + (uint16_t)(x3 + 1));
                    uint16_t value29 = BUS16_RDP(c, (db_ret << 0x10) + 0x1851);
                    if ((uint16_t)(x3 + 1) == value29) {
                        uint16_t x3_next4 = (uint16_t)(x3 + 1);
                        bool carry3_next4 = (uint16_t)(x3 + 1) >= value29;
                        x3 = x3_next4;
                        carry3 = carry3_next4;
                        break;
                    }
                    RAM8(0xCBFF + (uint16_t)(x3 + 1)) = value28;
                    uint16_t x3_next3 = (uint16_t)(x3 + 1);
                    bool carry3_next3 = (uint16_t)(x3 + 1) >= value29;
                    x3 = x3_next3;
                    carry3 = carry3_next3;
                    continue;
                }
            }
            RAM8(0xCBFF + x3) = 0xFF;
            r->a = 0;
            r->x = x3;
            r->y = (value21 << 8) | value20;
            r->c = carry3;
            r->z = 1;
            r->n = 0;
            r->v = ((((value21 << 8) | value20) ^ (uint16_t)(((value21 << 8) | value20) + value25)) & (value25 ^ (uint16_t)(((value21 << 8) | value20) + value25)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    RAM8(0xCC00 + value) = (uint8_t)((uint8_t)value2 - 0x20);
    if (((uint8_t)((uint8_t)value2 - 0x20) & 0xF0) != 0) {
        r->a = 0;
        r->x = value;
        r->y = 0x0B;
        r->c = (uint8_t)value2 >= 0x20;
        r->z = 1;
        r->n = 0;
        r->v = (((uint8_t)value2 ^ 0x20) & ((uint8_t)value2 ^ (uint8_t)((uint8_t)value2 - 0x20)) & 0x80) != 0;
        RETURN_RTS(c);
    }
    RAM8(0x1804) &= 0xBF;
    uint16_t value31 = RAM16(0x1840);
    RAM16_SET(0x1851, (uint16_t)(value31 + 0x0C));
    uint8_t a_hi4 = (uint16_t)(value31 + 0x0C) >> 8;
    uint16_t x4 = value;
    bool carry4 = value31 + 0x0C > 0xFFFF;
    bool first_pass4 = true;
    for (;;) {
        if (first_pass4) {
            uint8_t value32 = RAM8(0xCC00 + (uint16_t)(x4 + 1));
            uint16_t value33 = RAM16(0x1851);
            if ((uint16_t)(x4 + 1) == value33) {
                uint16_t x4_next2 = (uint16_t)(x4 + 1);
                bool carry4_next2 = (uint16_t)(x4 + 1) >= value33;
                x4 = x4_next2;
                carry4 = carry4_next2;
                break;
            }
            RAM8(0xCBFF + (uint16_t)(x4 + 1)) = value32;
            uint16_t x4_next = (uint16_t)(x4 + 1);
            bool carry4_next = (uint16_t)(x4 + 1) >= value33;
            x4 = x4_next;
            carry4 = carry4_next;
            first_pass4 = false;
            continue;
        } else {
            uint8_t value34 = RAM8(0xCC00 + (uint16_t)(x4 + 1));
            uint16_t value35 = RAM16(0x1851);
            if ((uint16_t)(x4 + 1) == value35) {
                uint16_t x4_next4 = (uint16_t)(x4 + 1);
                bool carry4_next4 = (uint16_t)(x4 + 1) >= value35;
                x4 = x4_next4;
                carry4 = carry4_next4;
                break;
            }
            RAM8(0xCBFF + (uint16_t)(x4 + 1)) = value34;
            uint16_t x4_next3 = (uint16_t)(x4 + 1);
            bool carry4_next3 = (uint16_t)(x4 + 1) >= value35;
            x4 = x4_next3;
            carry4 = carry4_next3;
            continue;
        }
    }
    RAM8(0xCBFF + x4) = 0xFF;
    r->a = 0;
    r->x = x4;
    r->y = 0x0C;
    r->c = carry4;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)(value31 + 0x0C) ^ 0x0C) & (value31 ^ (uint16_t)(value31 + 0x0C)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07DB1, SOM_RTS, "gen", remove_native_sold_inventory_quantity_or_detach_equipment_and_compact, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 0, 0, 127, 59)
