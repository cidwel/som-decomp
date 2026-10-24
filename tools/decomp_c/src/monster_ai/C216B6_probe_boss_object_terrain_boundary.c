#include "som_c.h"
#include "som_hand_d.h"

/* C216B6 probe_boss_object_terrain_boundary   [class B, 80 bytes, 44 instructions]
 * Source: src/rom/probe_boss_object_terrain_boundary.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void probe_boss_object_terrain_boundary(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    uint16_t v;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    a_lda(r, dp_rd16(c, 0x6E));
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    dp_wr16(c, 0x46, r->a);
    a_lda(r, 0x0080);
    dp_wr16(c, 0x4E, r->a);
    i_sep(r, 0x20);
    JSR(c, 0x16C7, 0xC22AA6); /* multiply_boss_terrain_row_stride */
    i_rep(r, 0x20);
    a_lda(r, dp_rd16(c, 0x6C));
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    i_lsra(r);
    r->c = 0;
    a_adc(r, dp_rd16(c, 0x56));
    i_tay(r);
    LDA_ILY16(c, 0x79, v); /* terrain tile index */
    a_lda(r, v);
    a_and(r, 0x00FF);
    i_asla(r);
    i_asla(r);
    i_tay(r);
    LDA_ILY16(c, 0x7C, v); /* tile property word */
    a_lda(r, v);
    a_ora(r, RAM16(0x000B + r->x));
    a_and(r, 0x0003);
    a_cmp(r, 0x0003);
    bool blocked = r->z;
    if (!blocked) {
        i_iny(r);
        i_iny(r);
        LDA_ILY16(c, 0x7C, v);
        a_lda(r, v);
        a_and(r, 0x00F0);
        a_cmp(r, 0x0010);
        blocked = r->z;
    }
    if (!blocked) {
        r->c = 0;
        RETURN_RTS(c);
    }
    a_lda(r, dp_rd16(c, 0x70));
    a_ora(r, RAM16(0x005B + r->x));
    RAM16_SET(0x005B + r->x, r->a);
    JSR(c, 0x1701, 0xC21706); /* set_boss_object_blocked_direction */
    a_ldx(r, dp_rd16(c, 0x87));
    r->c = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC216B6, SOM_RTS, "hand", probe_boss_object_terrain_boundary, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 80, 44)
