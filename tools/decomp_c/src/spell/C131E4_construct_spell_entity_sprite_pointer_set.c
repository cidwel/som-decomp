#include "som_c.h"
#include "som_hand.h"

/* C131E4 construct_spell_entity_sprite_pointer_set   [class B, 179 bytes, 86 instructions]
 * Source: src/rom/construct_spell_entity_sprite_pointer_set.s
 * Documented in docs/actor-cast-entity-sprite-topology.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: CV.
 */
/* absolute (and absolute indexed) operands follow the data bank, which the callees can leave elsewhere; sums above $FFFF carry into the next bank */
#define DBA(a) (((uint32_t)r->db << 16) + (uint32_t)(a))
static void construct_spell_entity_sprite_pointer_set(SomCtx *c)
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
    r->dp = (uint16_t)(sp0 - 0x0E); /* TSC SBC #9 TCD TCS: the frame; callees can leave D elsewhere, so every access follows r->dp */
    RAM16_SET((uint16_t)(0x0002 + r->dp), x);
    RAM16_SET((uint16_t)(0x0004 + r->dp), y);
    RAM8((uint16_t)(0x0001 + r->dp)) = (uint8_t)value;
    RAM16_SET((uint16_t)(0x0008 + r->dp), 8);
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = (uint16_t)(sp0 - 5) >= 9;
    bool overflow1 = (((uint16_t)(sp0 - 5) ^ 9) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0E)) & 0x8000) != 0;
    do {
        RAM16_SET((uint16_t)(0x0006 + r->dp), x1);
        r->x = x1; /* the callee gets the loop's X and Y, not the registers it returned last time */
        r->y = y1;
        r->a = 8;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 14;
        JSR(c, 0x3208, 0xC141A5); /* allocate_spell_entity_sprite_slot */
        r->sp += 14;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint16_t value2 = RAM16((uint16_t)(0x0006 + r->dp));
        BUS16_SET(c, DBA(0x0000 + value2), x_ret);
        RAM16_SET((uint16_t)(0x0008 + r->dp), (uint16_t)(RAM16((uint16_t)(0x0008 + r->dp)) - 1));
        a_hi1 = x_ret >> 8;
        x1 = (uint16_t)(value2 + 2);
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    } while (RAM16((uint16_t)(0x0008 + r->dp)) != 0);
    uint16_t value3 = RAM16((uint16_t)(0x0002 + r->dp));
    uint16_t value4 = RAM16((uint16_t)(0x0001 + r->dp));
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool overflow2;
    if ((value4 & 0xFF) < 0xC0) {
        a_hi2 = 0;
        x2 = value3;
        y2 = y1;
        carry2 = (value4 & 0xFF) >= 0xC0;
        overflow2 = overflow1;
    } else {
        r->a = 0xE1;
        r->x = value3;
        r->y = y1;
        r->c = (value4 & 0xFF) >= 0xC0;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 14;
        JSR(c, 0x3226, 0xC130E2); /* release_selected_spell_entity_sprite_pointers */
        r->sp += 14;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        BUS16_SET(c, DBA(0x0000 + x_ret2), BUS16(c, DBA(0x0008 + x_ret2)));
        BUS16_SET(c, DBA(0x000A + x_ret2), BUS16(c, DBA(0x0002 + x_ret2)));
        BUS16_SET(c, DBA(0x000C + x_ret2), BUS16(c, DBA(0x0004 + x_ret2)));
        uint16_t value8 = BUS16(c, DBA(0x0006 + x_ret2));
        BUS16_SET(c, DBA(0x000E + x_ret2), value8);
        BUS16_SET(c, DBA(0x0002 + x_ret2), 0);
        BUS16_SET(c, DBA(0x0004 + x_ret2), 0);
        BUS16_SET(c, DBA(0x0006 + x_ret2), 0);
        BUS16_SET(c, DBA(0x0008 + x_ret2), 0);
        a_hi2 = value8 >> 8;
        x2 = x_ret2;
        y2 = y_ret2;
        carry2 = carry_ret2;
        overflow2 = overflow_ret2;
    }
    r->a = 0x1E;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = 0;
    r->n = 0;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 14;
    JSR(c, 0x3250, 0xC130E2); /* release_selected_spell_entity_sprite_pointers */
    r->sp += 14;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    uint16_t value9 = RAM16((uint16_t)(0x0002 + r->dp));
    uint16_t value10 = RAM16((uint16_t)(0x0004 + r->dp));
    RAM16_SET((uint16_t)(0x0008 + r->dp), BUS16(c, DBA(0x0027 + value10)) & 0xFF);
    uint8_t a_hi3 = 0;
    uint16_t x3 = value10;
    uint16_t y3 = (uint16_t)(value9 + 2);
    bool carry3 = carry_ret3;
    bool overflow3 = overflow_ret3;
    do {
        RAM16_SET((uint16_t)(0x000A + r->dp), x3);
        uint16_t value12 = BUS16(c, DBA(0x0000 + x3));
        uint16_t value13 = RAM16((uint16_t)(0x0002 + r->dp));
        uint16_t value14 = BUS16(c, DBA(0x0008 + (uint16_t)((uint16_t)((uint16_t)((value12 & 7) - 2) << 1) + value13)));
        uint16_t y4;
        if (value14 == 0) {
            y4 = y3;
        } else {
            BUS16_SET(c, DBA(0x0000 + y3), value14);
            BUS16_SET(c, DBA(0x0008 + (uint16_t)((uint16_t)((uint16_t)((value12 & 7) - 2) << 1) + value13)), 0);
            y4 = (uint16_t)(y3 + 2);
        }
        uint16_t value15 = RAM16((uint16_t)(0x000A + r->dp));
        RAM16_SET((uint16_t)(0x0008 + r->dp), (uint16_t)(RAM16((uint16_t)(0x0008 + r->dp)) - 1));
        a_hi3 = (uint16_t)(value15 + 8) >> 8;
        x3 = (uint16_t)(value15 + 8);
        y3 = y4;
        carry3 = value15 + 8 > 0xFFFF;
        overflow3 = ((value15 ^ (uint16_t)(value15 + 8)) & ((uint16_t)(value15 + 8) ^ 8) & 0x8000) != 0;
    } while (RAM16((uint16_t)(0x0008 + r->dp)) != 0);
    uint16_t value16 = RAM16((uint16_t)(0x0002 + r->dp));
    r->a = 0xF0;
    r->x = value16;
    r->y = y3;
    r->c = carry3;
    r->z = 0;
    r->n = 0;
    r->v = overflow3;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 14;
    JSR(c, 0x328D, 0xC130E2); /* release_selected_spell_entity_sprite_pointers */
    r->sp += 14;
    som_pull_p(c, sp0 - 2); /* PLP */
    r->dp = RAM8(sp0 - 1) | (RAM8(sp0) << 8); /* PLD */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC131E4, SOM_RTS, "hand", construct_spell_entity_sprite_pointer_set, 0, L_C | L_V, 14, 1, 0, 179, 86)
