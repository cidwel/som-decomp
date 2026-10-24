#include "som_c.h"

/* C12923 retire_spell_entity_actor_record   [class B, 116 bytes, 57 instructions]
 * Source: src/rom/retire_spell_entity_actor_record.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: CV.
 */
static void retire_spell_entity_actor_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    if (x != 0) {
        uint8_t value = RAM8(0x000D + x);
        uint8_t a_hi3;
        bool overflow3;
        if (value == 0) {
            a_hi3 = a >> 8;
            overflow3 = overflow;
        } else {
            uint8_t a_hi2;
            bool overflow2;
            if (value == 0x20) {
                uint16_t value2 = RAM16(0x8216);
                uint8_t value3 = RAM8(0x0000 + (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2));
                uint8_t a2;
                if ((uint8_t)(value3 - 1) == 1) {
                    a2 = 0;
                } else {
                    uint8_t a1;
                    if ((uint8_t)(value3 - 1) >= 1) {
                        a1 = (uint8_t)(value3 - 1);
                    } else {
                        a1 = 0;
                    }
                    a2 = a1;
                }
                RAM8(0x0000 + (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2)) = a2;
                a_hi2 = (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2) >> 8;
                overflow2 = (((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) ^ (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2)) & (value2 ^ (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value2)) & 0x8000) != 0;
            } else {
                uint8_t a_hi1;
                bool overflow1;
                if (value >= 0x20) {
                    a_hi1 = a >> 8;
                    overflow1 = overflow;
                } else {
                    uint16_t value4 = RAM16(0x8216);
                    uint8_t value5 = RAM8(0x0000 + (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4));
                    uint8_t a4;
                    if ((uint8_t)(value5 - 1) == 1) {
                        a4 = 0;
                    } else {
                        uint8_t a3;
                        if ((uint8_t)(value5 - 1) >= 1) {
                            a3 = (uint8_t)(value5 - 1);
                        } else {
                            a3 = 0;
                        }
                        a4 = a3;
                    }
                    RAM8(0x0000 + (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4)) = a4;
                    a_hi1 = (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4) >> 8;
                    overflow1 = (((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) ^ (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4)) & (value4 ^ (uint16_t)((((a >> 8 << 8) | (uint8_t)(value - 1)) & 0xFF) + value4)) & 0x8000) != 0;
                }
                a_hi2 = a_hi1;
                overflow2 = overflow1;
            }
            a_hi3 = a_hi2;
            overflow3 = overflow2;
        }
        uint8_t value6 = RAM8(0x000F + x);
        uint16_t x1;
        if (value6 != 5) {
            x1 = x;
        } else {
            RAM8(0x821E) = (RAM8(0x0009 + x) ^ 0xFF) & RAM8(0x821E);
            uint8_t value9 = RAM8(0x0009 + x);
            RAM8(0x0000 + sp0 - 4) = x >> 8;
            RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
            r->a = ((a_hi3 << 8) | value9) & 0xFF;
            r->x = ((a_hi3 << 8) | value9) & 0xFF;
            r->c = value6 >= 5;
            r->z = (((a_hi3 << 8) | value9) & 0xFF) == 0;
            r->n = ((a_hi3 << 8) | value9) & 0xFF & 0x8000;
            r->v = overflow3;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2978, 0xC14720); GUARD_JSR(c, sp_call, 0x2978); } /* find_highest_set_entity_flag_bit */
            r->sp += 6;
            uint16_t a_all = r->a;
            RAM8(0x8220 + (a_all & 7)) = 0;
            uint8_t value10 = RAM8(0x0000 + sp0 - 5);
            uint8_t value11 = RAM8(0x0000 + sp0 - 4);
            if (RAM8(0x0009 + ((value11 << 8) | value10)) == 0x80) {
                RAM8(0x8228) = 0;
                RAM8(0x8229) = 0;
            }
            x1 = (value11 << 8) | value10;
        }
        RAM8(0x000F + x1) = 0;
    }
    uint8_t value13 = RAM8(0x0000 + sp0 - 3);
    uint8_t value14 = RAM8(0x0000 + sp0 - 2);
    uint8_t value15 = RAM8(0x0000 + sp0 - 1);
    uint8_t value16 = RAM8(0x0000 + sp0);
    r->c = value14 & 0x01;
    r->v = value14 & 0x40;
    r->mf = value14 & 0x20;
    r->xf = value14 & 0x10;
    r->db = value13;
    r->dp = (value16 << 8) | value15;
    r->i = value14 & 0x04;
    r->d = value14 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12923, SOM_RTS, "gen", retire_spell_entity_actor_record, 0, L_C | L_V, 6, 0, 0, 116, 57)
