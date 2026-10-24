#include "som_c.h"
#include "som_hand.h"

/* C13113 construct_boss_spell_entity_sprite_pointer_set   [class B, 209 bytes, 105 instructions]
 * Source: src/rom/construct_boss_spell_entity_sprite_pointer_set.s
 * Documented in docs/actor-cast-entity-sprite-topology.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: CV.
 */
static void construct_boss_spell_entity_sprite_pointer_set(SomCtx *c)
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
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0001 + (uint16_t)(sp0 - 0x10)) = (uint8_t)value;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x10), x);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 0x10), y);
    uint8_t value2 = RAM8(0x0000 + y);
    RAM16_SET(0x0008 + (uint16_t)(sp0 - 0x10), (uint16_t)((uint16_t)((((((value >> 8 << 8) | value2) & 0xFF) << 8) | 0) << 1) + 0xE000));
    r->a = 0;
    r->x = 0x20;
    r->c = (uint16_t)((((((value >> 8 << 8) | value2) & 0xFF) << 8) | 0) << 1) + 0xE000 > 0xFFFF;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)((((((value >> 8 << 8) | value2) & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((((value >> 8 << 8) | value2) & 0xFF) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((((value >> 8 << 8) | value2) & 0xFF) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x10);
    r->sp -= 16;
    JSR(c, 0x3141, 0xC13D48); /* allocate_and_fill_spell_entity_heap_bytes */
    r->sp += 16;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x10), x_ret);
    RAM16_SET(0x000A + (uint16_t)(sp0 - 0x10), 8);
    uint8_t a_hi1 = 0;
    uint16_t x1 = x_ret;
    bool carry1 = carry_ret;
    bool overflow1 = overflow_ret;
    do {
        RAM16_SET(0x000C + (uint16_t)(sp0 - 0x10), x1);
        r->a = 0;
        r->c = carry1;
        r->z = 1;
        r->n = 0;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = (uint16_t)(sp0 - 0x10);
        r->sp -= 16;
        JSR(c, 0x3150, 0xC141A5); /* allocate_spell_entity_sprite_slot */
        r->sp += 16;
        uint16_t x_ret2 = r->x;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        uint16_t value3 = RAM16(0x000C + (uint16_t)(sp0 - 0x10));
        RAM16_SET(0x0000 + value3, x_ret2);
        RAM16_SET(0x000A + (uint16_t)(sp0 - 0x10), (uint16_t)(RAM16(0x000A + (uint16_t)(sp0 - 0x10)) - 1));
        a_hi1 = x_ret2 >> 8;
        x1 = (uint16_t)(value3 + 2);
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
    } while (RAM16(0x000A + (uint16_t)(sp0 - 0x10)) != 0);
    RAM16_SET(0x000A + (uint16_t)(sp0 - 0x10), 8);
    uint8_t a_hi2 = 0;
    uint16_t x2 = x1;
    bool carry2 = carry1;
    bool overflow2 = overflow1;
    do {
        RAM16_SET(0x000C + (uint16_t)(sp0 - 0x10), x2);
        r->a = 8;
        r->c = carry2;
        r->z = 0;
        r->n = 0;
        r->v = overflow2;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = (uint16_t)(sp0 - 0x10);
        r->sp -= 16;
        JSR(c, 0x3169, 0xC141A5); /* allocate_spell_entity_sprite_slot */
        r->sp += 16;
        uint16_t x_ret3 = r->x;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        uint16_t value4 = RAM16(0x000C + (uint16_t)(sp0 - 0x10));
        RAM16_SET(0x0000 + value4, x_ret3);
        RAM16_SET(0x000A + (uint16_t)(sp0 - 0x10), (uint16_t)(RAM16(0x000A + (uint16_t)(sp0 - 0x10)) - 1));
        a_hi2 = x_ret3 >> 8;
        x2 = (uint16_t)(value4 + 2);
        carry2 = carry_ret3;
        overflow2 = overflow_ret3;
    } while (RAM16(0x000A + (uint16_t)(sp0 - 0x10)) != 0);
    uint16_t value5 = RAM16(0x0006 + (uint16_t)(sp0 - 0x10));
    uint16_t value6 = RAM16(0x0002 + (uint16_t)(sp0 - 0x10));
    uint16_t value7 = RAM16(0x0001 + (uint16_t)(sp0 - 0x10));
    uint8_t a_hi3;
    if ((value7 & 0xFF) < 0xC0) {
        uint16_t value8 = RAM16(0x0010 + value5);
        RAM16_SET(0x0000 + value6, value8);
        RAM16_SET(0x0010 + value5, 0);
        a_hi3 = value8 >> 8;
    } else {
        uint16_t value9 = RAM16(0x0018 + value5);
        RAM16_SET(0x0000 + value6, value9);
        RAM16_SET(0x0018 + value5, 0);
        a_hi3 = value9 >> 8;
    }
    RAM16_SET(0x000C + (uint16_t)(sp0 - 0x10), (uint16_t)(value6 + 2));
    RAM16_SET(0x000A + (uint16_t)(sp0 - 0x10), 4);
    uint8_t a_hi4 = 0;
    uint16_t y1 = (uint16_t)(value6 + 2);
    bool carry3 = (value7 & 0xFF) >= 0xC0;
    bool overflow3 = overflow2;
    do {
        uint16_t value10 = RAM16(0x0008 + (uint16_t)(sp0 - 0x10));
        uint16_t value11 = RAM16(0x0018 + value10);
        RAM16_SET(0x0008 + (uint16_t)(sp0 - 0x10), (uint16_t)(value10 + 1));
        uint8_t a_hi5;
        uint16_t y3;
        bool carry4;
        bool overflow4;
        if ((value11 & 0xFF) == 0) {
            a_hi5 = 0;
            y3 = y1;
            carry4 = carry3;
            overflow4 = overflow3;
        } else {
            uint16_t value12 = RAM16(0x0006 + (uint16_t)(sp0 - 0x10));
            uint16_t value13 = RAM16(0x0000 + (uint16_t)(((value11 & 0xFF) << 1) + value12));
            uint16_t y2;
            if (value13 == 0) {
                y2 = y1;
            } else {
                RAM16_SET(0x0000 + y1, value13);
                RAM16_SET(0x0000 + (uint16_t)(((value11 & 0xFF) << 1) + value12), 0);
                y2 = (uint16_t)(y1 + 2);
            }
            a_hi5 = value13 >> 8;
            y3 = y2;
            carry4 = ((value11 & 0xFF) << 1) + value12 > 0xFFFF;
            overflow4 = ((((value11 & 0xFF) << 1) ^ (uint16_t)(((value11 & 0xFF) << 1) + value12)) & (value12 ^ (uint16_t)(((value11 & 0xFF) << 1) + value12)) & 0x8000) != 0;
        }
        RAM16_SET(0x000A + (uint16_t)(sp0 - 0x10), (uint16_t)(RAM16(0x000A + (uint16_t)(sp0 - 0x10)) - 1));
        a_hi4 = a_hi5;
        y1 = y3;
        carry3 = carry4;
        overflow3 = overflow4;
    } while (RAM16(0x000A + (uint16_t)(sp0 - 0x10)) != 0);
    uint16_t value14 = RAM16(0x0006 + (uint16_t)(sp0 - 0x10));
    RAM16_SET(0x000A + (uint16_t)(sp0 - 0x10), 0x10);
    uint16_t y4 = value14;
    bool carry5 = carry3;
    bool overflow5 = overflow3;
    do {
        uint16_t value15 = RAM16(0x0000 + y4);
        uint16_t y5;
        bool carry6;
        bool overflow6;
        if (value15 == 0) {
            y5 = y4;
            carry6 = carry5;
            overflow6 = overflow5;
        } else {
            RAM8(0x0000 + sp0 - 0x10) = y4 >> 8;
            RAM8(0x0000 + sp0 - 0x11) = (uint8_t)y4;
            r->x = value15;
            r->y = y4;
            r->c = carry5;
            r->z = value15 == 0;
            r->n = value15 & 0x8000;
            r->v = overflow5;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = (uint16_t)(sp0 - 0x10);
            r->sp -= 18;
            JSR(c, 0x31D3, 0xC141E1); /* release_spell_entity_sprite_slot */
            r->sp += 18;
            bool carry_ret4 = r->c;
            bool overflow_ret4 = r->v;
            y5 = (RAM8(0x0000 + sp0 - 0x10) << 8) | RAM8(0x0000 + sp0 - 0x11);
            carry6 = carry_ret4;
            overflow6 = overflow_ret4;
        }
        RAM16_SET(0x000A + (uint16_t)(sp0 - 0x10), (uint16_t)(RAM16(0x000A + (uint16_t)(sp0 - 0x10)) - 1));
        y4 = (uint16_t)(y5 + 2);
        carry5 = carry6;
        overflow5 = overflow6;
    } while (RAM16(0x000A + (uint16_t)(sp0 - 0x10)) != 0);
    uint8_t value18 = RAM8(0x0000 + sp0 - 1);
    uint8_t value19 = RAM8(0x0000 + sp0);
    som_pull_p(c, sp0 - 2); /* PLP: the callees ran with D inside this frame and may have rewritten the saved flags */
    r->dp = (value19 << 8) | value18;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC13113, SOM_RTS, "hand", construct_boss_spell_entity_sprite_pointer_set, 0, L_C | L_V, 18, 1, 0, 209, 105)
