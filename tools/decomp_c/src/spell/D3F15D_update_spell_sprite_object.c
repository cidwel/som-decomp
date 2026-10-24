#include "som_c.h"
#include "som_hand.h"

/* D3F15D update_spell_sprite_object   [class B, 203 bytes, 102 instructions]
 * Source: src/rom/update_spell_sprite_object.s
 * Documented in docs/actor-cast-entity-sprite-motion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void update_spell_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 9) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0A) = 0x7E;
    uint8_t value = RAM8(0x023D + x);
    RAM8(0x023D + x) = (uint8_t)(value - 1);
    uint8_t a_hi5;
    if ((uint8_t)(value - 1) != 0) {
        uint8_t a_hi4;
        if ((uint8_t)(value - 1) != 2) {
            RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), x);
            uint8_t value2 = RAM8(0x023C + x);
            uint8_t a8;
            uint8_t a_hi3;
            uint16_t x1;
            if (value2 != 0) {
                uint8_t a1;
                if ((value2 & 0x80) != 0) {
                    RAM8(0x023C + x) = (uint8_t)(value2 + 8);
                    a1 = 0xF8;
                } else {
                    RAM8(0x023C + x) = (uint8_t)(value2 - 8);
                    a1 = 8;
                }
                a8 = a1;
                a_hi3 = (uint16_t)(sp0 - 9) >> 8;
                x1 = x;
            } else {
                r->c = (uint8_t)(value - 1) >= 2;
                r->z = value2 == 0;
                r->n = value2 & 0x80;
                r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
                r->dp = (uint16_t)(sp0 - 9);
                r->sp -= 10;
                JSR(c, 0xF190, 0xD3F0B1); /* derive_spell_sprite_object_target_vectors */
                r->sp += 10;
                r->mf = 0; /* rep */
                uint16_t x_ret = r->x;
                uint16_t y_ret = r->y;
                uint8_t a2;
                uint8_t a_hi1;
                if ((x_ret & 0x8000) == 0) {
                    a2 = (uint8_t)x_ret;
                    a_hi1 = x_ret >> 8;
                } else {
                    a2 = (uint8_t)((x_ret ^ 0xFFFF) + 1);
                    a_hi1 = (uint16_t)((x_ret ^ 0xFFFF) + 1) >> 8;
                }
                RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), (a_hi1 << 8) | a2);
                RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), 0);
                uint8_t a3;
                uint8_t a_hi2;
                if ((y_ret & 0x8000) == 0) {
                    a3 = (uint8_t)y_ret;
                    a_hi2 = y_ret >> 8;
                } else {
                    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0003 + (uint16_t)(sp0 - 9)) - 1));
                    a3 = (uint8_t)((y_ret ^ 0xFFFF) + 1);
                    a_hi2 = (uint16_t)((y_ret ^ 0xFFFF) + 1) >> 8;
                }
                uint16_t value3 = RAM16(0x0001 + (uint16_t)(sp0 - 9));
                BUS16_SET(c, 0x004204, (a_hi2 << 8) | a3);
                uint8_t value4 = RAM8(0x0006 + (uint16_t)(sp0 - 9));
                BUS8_SET(c, 0x004206, value4);
                RAM8(0x0000 + sp0 - 0x0A) = a_hi2;
                RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)((a_hi2 << 8) | value4);
                RAM8(0x0000 + sp0 - 0x0A) = a_hi2;
                RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)((a_hi2 << 8) | value4);
                uint16_t value5 = BUS16(c, 0x004214);
                uint8_t a7;
                if (value5 >= 0x20) {
                    uint8_t value6 = RAM8(0x0003 + (uint16_t)(sp0 - 9));
                    RAM8(0x0003 + (uint16_t)(sp0 - 9)) <<= 1;
                    uint8_t a4;
                    if (!(value6 & 0x80)) {
                        a4 = 8;
                    } else {
                        a4 = 0xF8;
                    }
                    a7 = a4;
                } else {
                    uint8_t value7 = RAM8(0x0003 + (uint16_t)(sp0 - 9));
                    RAM8(0x0003 + (uint16_t)(sp0 - 9)) <<= 1;
                    uint8_t a5;
                    if (value7 & 0x80) {
                        a5 = 0x20;
                    } else {
                        a5 = 0xE0;
                    }
                    RAM8(0x023C + value3) = a5;
                    uint8_t a6;
                    if ((a5 & 0x80) != 0) {
                        RAM8(0x023C + value3) = (uint8_t)(a5 + 8);
                        a6 = 0xF8;
                    } else {
                        RAM8(0x023C + value3) = (uint8_t)(a5 - 8);
                        a6 = 8;
                    }
                    a7 = a6;
                }
                a8 = a7;
                a_hi3 = value5 >> 8;
                x1 = value3;
            }
            uint8_t value8 = RAM8(0x023A + x1);
            RAM8(0x023A + x1) = (uint8_t)(a8 + value8);
            uint16_t value9 = RAM16(0x0005 + (uint16_t)(sp0 - 9));
            uint16_t value10 = RAM16(0x023E + x1);
            uint16_t y1;
            if (value9 < value10) {
                y1 = 5;
            } else {
                y1 = 2;
            }
            RAM16_SET(0x023E + x1, value9);
            r->a = y1;
            r->x = x1;
            r->y = y1;
            r->c = value9 >= value10;
            r->z = y1 == 0;
            r->n = y1 & 0x8000;
            r->v = ((a8 ^ (uint8_t)(a8 + value8)) & (value8 ^ (uint8_t)(a8 + value8)) & 0x80) != 0;
            r->mf = 0;
            r->xf = 0;
            r->dp = (uint16_t)(sp0 - 9);
            r->sp -= 10;
            JSR(c, 0xF214, 0xD3EFC4); /* advance_spell_sprite_object_motion */
            r->sp += 10;
            r->mf = 1; /* sep */
            uint16_t a_all2 = r->a;
            a_hi4 = a_all2 >> 8;
        } else {
            a_hi4 = (uint16_t)(sp0 - 9) >> 8;
        }
        a_hi5 = a_hi4;
    } else {
        RAM8(0x023D + x) = 6;
        a_hi5 = (uint16_t)(sp0 - 9) >> 8;
    }
    RAM16_SET(0x0000 + sp0 - 4, (a_hi5 << 8) | 0xFF);
    uint8_t value13 = RAM8(0x0000 + sp0 - 1);
    uint8_t value14 = RAM8(0x0000 + sp0);
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E; /* PLB restores the entry data bank */
    som_pull_p(c, sp0 - 2); /* PLP */
    r->dp = RAM8(sp0 - 1) | (RAM8(sp0) << 8); /* PLD */
    r->z = r->dp == 0;
    r->n = r->dp & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F15D, SOM_RTS, "hand", update_spell_sprite_object, 0, 0, 12, 1, 0, 203, 102)
