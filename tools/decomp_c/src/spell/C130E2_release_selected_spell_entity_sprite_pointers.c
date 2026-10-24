#include "som_c.h"
#include "som_hand.h"

/* C130E2 release_selected_spell_entity_sprite_pointers   [class B, 49 bytes, 33 instructions]
 * Source: src/rom/release_selected_spell_entity_sprite_pointers.s
 * Documented in docs/actor-cast-entity-sprite-topology.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void release_selected_spell_entity_sprite_pointers_m16x16(SomCtx *c)
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
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = (uint16_t)(x - 2);
    uint16_t y1 = y;
    bool overflow1 = overflow;
    do {
        uint8_t value = RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1));
        RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) >>= 1;
        if (value & 0x01) {
            uint16_t value2 = RAM16(0x0000 + (uint16_t)(x1 + 2));
            if (value2 == 0) {
                x1 = (uint16_t)(x1 + 2);
                y1 = value2;
                continue;
            }
            RAM8(0x0000 + sp0 - 6) = (uint16_t)(x1 + 2) >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)(x1 + 2);
            r->x = value2;
            r->y = value2;
            r->c = value & 0x01;
            r->z = value2 == 0;
            r->n = value2 & 0x8000;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = (uint16_t)((uint16_t)(sp0 - 5) + 1);
            r->sp -= 8;
            JSR(c, 0x3102, 0xC141E1); /* release_spell_entity_sprite_slot */
            r->sp += 8;
            if (r->db != 0x7E) { c->fail = 3; return; } /* the callee's PLB popped a clobbered byte: the next absolute accesses leave bank 7E */
            uint16_t a_all = r->a;
            bool overflow_ret = r->v;
            uint8_t value3 = RAM8(0x0000 + sp0 - 7);
            uint8_t value4 = RAM8(0x0000 + sp0 - 6);
            RAM8(0x0000 + ((value4 << 8) | value3)) = 0;
            RAM8(0x0001 + ((value4 << 8) | value3)) = 0;
            a_hi1 = a_all >> 8;
            x1 = (value4 << 8) | value3;
            y1 = value2;
            overflow1 = overflow_ret;
            continue;
        }
        x1 = (uint16_t)(x1 + 2);
    } while (RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) != 0);
    uint8_t value5 = RAM8(0x0000 + sp0 - 5);
    uint8_t value6 = RAM8(0x0000 + sp0 - 4);
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value7;
    r->x = (value6 << 8) | value5;
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    r->dp = (value9 << 8) | value8;
    som_pull_p(c, sp0 - 2); /* PLP */
    RETURN_RTS(c);
}

/* C130E2 release_selected_spell_entity_sprite_pointers   [class B, 49 bytes, 33 instructions]
 * Source: src/rom/release_selected_spell_entity_sprite_pointers.s
 * Documented in docs/actor-cast-entity-sprite-topology.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void release_selected_spell_entity_sprite_pointers_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = (uint16_t)(x - 2);
    uint16_t y1 = y;
    bool overflow1 = overflow;
    do {
        uint8_t value = RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1));
        RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) >>= 1;
        if (value & 0x01) {
            uint16_t value2 = RAM16(0x0000 + (uint16_t)(x1 + 2));
            if (value2 == 0) {
                x1 = (uint16_t)(x1 + 2);
                y1 = value2;
                continue;
            }
            RAM8(0x0000 + sp0 - 6) = (uint16_t)(x1 + 2) >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)(x1 + 2);
            r->x = value2;
            r->y = value2;
            r->c = value & 0x01;
            r->z = value2 == 0;
            r->n = value2 & 0x8000;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = (uint16_t)((uint16_t)(sp0 - 5) + 1);
            r->sp -= 8;
            JSR(c, 0x3102, 0xC141E1); /* release_spell_entity_sprite_slot */
            r->sp += 8;
            if (r->db != 0x7E) { c->fail = 3; return; } /* the callee's PLB popped a clobbered byte: the next absolute accesses leave bank 7E */
            uint16_t a_all = r->a;
            bool overflow_ret = r->v;
            uint8_t value3 = RAM8(0x0000 + sp0 - 7);
            uint8_t value4 = RAM8(0x0000 + sp0 - 6);
            RAM8(0x0000 + ((value4 << 8) | value3)) = 0;
            RAM8(0x0001 + ((value4 << 8) | value3)) = 0;
            a_hi1 = a_all >> 8;
            x1 = (value4 << 8) | value3;
            y1 = value2;
            overflow1 = overflow_ret;
            continue;
        }
        x1 = (uint16_t)(x1 + 2);
    } while (RAM8(0x0001 + (uint16_t)((uint16_t)(sp0 - 5) + 1)) != 0);
    uint8_t value5 = RAM8(0x0000 + sp0 - 5);
    uint8_t value6 = RAM8(0x0000 + sp0 - 4);
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value7;
    r->x = (value6 << 8) | value5;
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    r->dp = (value9 << 8) | value8;
    som_pull_p(c, sp0 - 2); /* PLP */
    RETURN_RTS(c);
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void release_selected_spell_entity_sprite_pointers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { release_selected_spell_entity_sprite_pointers_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { release_selected_spell_entity_sprite_pointers_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC130E2, SOM_RTS, "hand", release_selected_spell_entity_sprite_pointers, 0, L_B | L_X | L_Y | L_C | L_V, 8, -1, -1, 49, 33)
