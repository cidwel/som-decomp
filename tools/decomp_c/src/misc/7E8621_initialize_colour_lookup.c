#include "som_c.h"

/* 7E8621 initialize_colour_lookup   [class B, 101 bytes, 53 instructions]
 * Source: src/boot/initialize_colour_lookup.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYCZNV.
 */
static void initialize_colour_lookup(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7F;
    r->a = ((uint16_t)(sp0 - 0x0B) >> 8 << 8) | 0x7F;
    r->c = (uint16_t)(sp0 - 3) >= 8;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 8) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 0x0B);
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8637, 0x7E8607); GUARD_JSR(c, sp_call, 0x8637); } /* clear_colour_lookup_bank */
    r->sp += 12;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0x18);
    BUS16_SET(c, (uint16_t)(dp_ret + 7), (uint16_t)(value + 0x30));
    BUS16_SET(c, (uint16_t)(dp_ret + 1), 8);
    BUS16_SET(c, (uint16_t)(dp_ret + 3), 0);
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0;
    bool carry1 = value + 0x30 > 0xFFFF;
    bool overflow1 = ((value ^ (uint16_t)(value + 0x30)) & ((uint16_t)(value + 0x30) ^ 0x30) & 0x8000) != 0;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            BUS16_SET(c, (uint16_t)(dp_ret + 5), x1);
            uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret + 7));
            BUS16_SET(c, (db_ret << 0x10) + value2, RAM16(0x59E0 + x1));
            uint16_t value4 = RAM16(0x59E2 + x1);
            BUS16_SET(c, (db_ret << 0x10) + 2 + value2, value4);
            r->a = value4;
            r->x = value2;
            r->y = value2;
            r->c = carry1;
            r->z = value2 == 0;
            r->n = value2 & 0x8000;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = db_ret;
            r->dp = dp_ret;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8660, 0x7E8577); GUARD_JSR(c, sp_call, 0x8660); } /* mark_cyclic_component_permutations */
            r->sp += 12;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret2 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
            BUS16_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(a_all2 + value5));
            if ((uint16_t)(a_all2 + value5) >= 0x8000) {
                uint8_t value6 = RAM8(0x0000 + sp0 - 0x0B);
                RAM16_SET(0x0000 + sp0 - 4, (uint16_t)(a_all2 + value5));
                uint8_t value9 = RAM8(0x0000 + sp0 - 2);
                uint8_t value10 = RAM8(0x0000 + sp0 - 1);
                uint8_t value11 = RAM8(0x0000 + sp0);
                r->c = value9 & 0x01;
                r->z = ((value11 << 8) | value10) == 0;
                r->n = ((value11 << 8) | value10) & 0x8000;
                r->v = value9 & 0x40;
                r->mf = value9 & 0x20;
                r->xf = value9 & 0x10;
                r->db = value6;
                r->dp = (value11 << 8) | value10;
                r->i = value9 & 0x04;
                r->d = value9 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
            if (x_ret2) {
                uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value13 - 1));
                if ((uint16_t)(value13 - 1) != 0) {
                    a_hi1 = (uint16_t)(value12 + 3) >> 8;
                    x1 = (uint8_t)(value12 + 3);
                    carry1 = value12 + 3 > 0xFFFF;
                    overflow1 = ((value12 ^ (uint16_t)(value12 + 3)) & ((uint16_t)(value12 + 3) ^ 3) & 0x8000) != 0;
                    first_pass = false;
                    continue;
                }
                uint8_t value14 = RAM8(0x0000 + sp0 - 0x0B);
                RAM16_SET(0x0000 + sp0 - 4, 0);
                uint8_t value17 = RAM8(0x0000 + sp0 - 2);
                uint8_t value18 = RAM8(0x0000 + sp0 - 1);
                uint8_t value19 = RAM8(0x0000 + sp0);
                r->x = (uint8_t)(value12 + 3);
                r->y = (uint8_t)y_ret2;
                r->c = value17 & 0x01;
                r->z = ((value19 << 8) | value18) == 0;
                r->n = ((value19 << 8) | value18) & 0x8000;
                r->v = value17 & 0x40;
                r->mf = value17 & 0x20;
                r->xf = value17 & 0x10;
                r->db = value14;
                r->dp = (value19 << 8) | value18;
                r->i = value17 & 0x04;
                r->d = value17 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value20 - 1));
                if ((uint16_t)(value20 - 1) != 0) {
                    a_hi1 = (uint16_t)(value12 + 3) >> 8;
                    x1 = (uint16_t)(value12 + 3);
                    carry1 = value12 + 3 > 0xFFFF;
                    overflow1 = ((value12 ^ (uint16_t)(value12 + 3)) & ((uint16_t)(value12 + 3) ^ 3) & 0x8000) != 0;
                    continue;
                }
                uint8_t value21 = RAM8(0x0000 + sp0 - 0x0B);
                RAM16_SET(0x0000 + sp0 - 4, 0);
                uint8_t value24 = RAM8(0x0000 + sp0 - 2);
                uint8_t value25 = RAM8(0x0000 + sp0 - 1);
                uint8_t value26 = RAM8(0x0000 + sp0);
                r->x = (uint16_t)(value12 + 3);
                r->c = value24 & 0x01;
                r->z = ((value26 << 8) | value25) == 0;
                r->n = ((value26 << 8) | value25) & 0x8000;
                r->v = value24 & 0x40;
                r->mf = value24 & 0x20;
                r->xf = value24 & 0x10;
                r->db = value21;
                r->dp = (value26 << 8) | value25;
                r->i = value24 & 0x04;
                r->d = value24 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS8_SET(c, (uint16_t)(dp_ret + 5), (uint8_t)x1);
            uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp_ret + 7));
            BUS16_SET(c, (db_ret << 0x10) + value27, RAM16(0x59E0 + (uint8_t)x1));
            uint16_t value29 = RAM16(0x59E2 + (uint8_t)x1);
            BUS16_SET(c, (db_ret << 0x10) + 2 + value27, value29);
            r->a = value29;
            r->x = value27;
            r->y = value27;
            r->c = carry1;
            r->z = value27 == 0;
            r->n = value27 & 0x80;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 1;
            r->db = db_ret;
            r->dp = dp_ret;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8660, 0x7E8577); GUARD_JSR(c, sp_call, 0x8660); } /* mark_cyclic_component_permutations */
            r->sp += 12;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret4 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t y_ret3 = r->y;
            uint16_t value30 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
            BUS16_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(a_all3 + value30));
            if ((uint16_t)(a_all3 + value30) >= 0x8000) {
                uint8_t value31 = RAM8(0x0000 + sp0 - 0x0B);
                RAM16_SET(0x0000 + sp0 - 4, (uint16_t)(a_all3 + value30));
                uint8_t value34 = RAM8(0x0000 + sp0 - 2);
                uint8_t value35 = RAM8(0x0000 + sp0 - 1);
                uint8_t value36 = RAM8(0x0000 + sp0);
                r->c = value34 & 0x01;
                r->z = ((value36 << 8) | value35) == 0;
                r->n = ((value36 << 8) | value35) & 0x8000;
                r->v = value34 & 0x40;
                r->mf = value34 & 0x20;
                r->xf = value34 & 0x10;
                r->db = value31;
                r->dp = (value36 << 8) | value35;
                r->i = value34 & 0x04;
                r->d = value34 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
            if (x_ret4) {
                uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value38 - 1));
                if ((uint16_t)(value38 - 1) != 0) {
                    a_hi1 = (uint16_t)(value37 + 3) >> 8;
                    x1 = (uint8_t)(value37 + 3);
                    carry1 = value37 + 3 > 0xFFFF;
                    overflow1 = ((value37 ^ (uint16_t)(value37 + 3)) & ((uint16_t)(value37 + 3) ^ 3) & 0x8000) != 0;
                    continue;
                }
                uint8_t value39 = RAM8(0x0000 + sp0 - 0x0B);
                RAM16_SET(0x0000 + sp0 - 4, 0);
                uint8_t value42 = RAM8(0x0000 + sp0 - 2);
                uint8_t value43 = RAM8(0x0000 + sp0 - 1);
                uint8_t value44 = RAM8(0x0000 + sp0);
                r->x = (uint8_t)(value37 + 3);
                r->y = (uint8_t)y_ret3;
                r->c = value42 & 0x01;
                r->z = ((value44 << 8) | value43) == 0;
                r->n = ((value44 << 8) | value43) & 0x8000;
                r->v = value42 & 0x40;
                r->mf = value42 & 0x20;
                r->xf = value42 & 0x10;
                r->db = value39;
                r->dp = (value44 << 8) | value43;
                r->i = value42 & 0x04;
                r->d = value42 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value45 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value45 - 1));
                if ((uint16_t)(value45 - 1) != 0) {
                    a_hi1 = (uint16_t)(value37 + 3) >> 8;
                    x1 = (uint16_t)(value37 + 3);
                    carry1 = value37 + 3 > 0xFFFF;
                    overflow1 = ((value37 ^ (uint16_t)(value37 + 3)) & ((uint16_t)(value37 + 3) ^ 3) & 0x8000) != 0;
                    first_pass = true;
                    continue;
                }
                uint8_t value46 = RAM8(0x0000 + sp0 - 0x0B);
                RAM16_SET(0x0000 + sp0 - 4, 0);
                uint8_t value49 = RAM8(0x0000 + sp0 - 2);
                uint8_t value50 = RAM8(0x0000 + sp0 - 1);
                uint8_t value51 = RAM8(0x0000 + sp0);
                r->x = (uint16_t)(value37 + 3);
                r->c = value49 & 0x01;
                r->z = ((value51 << 8) | value50) == 0;
                r->n = ((value51 << 8) | value50) & 0x8000;
                r->v = value49 & 0x40;
                r->mf = value49 & 0x20;
                r->xf = value49 & 0x10;
                r->db = value46;
                r->dp = (value51 << 8) | value50;
                r->i = value49 & 0x04;
                r->d = value49 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0x7E8621, SOM_RTS, "gen", initialize_colour_lookup, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 13, 1, 0, 101, 53)
