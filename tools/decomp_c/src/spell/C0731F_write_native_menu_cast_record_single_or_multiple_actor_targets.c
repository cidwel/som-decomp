#include "som_c.h"

/* C0731F write_native_menu_cast_record_single_or_multiple_actor_targets   [class B, 141 bytes, 60 instructions]
 * Source: src/rom/write_native_menu_cast_record_single_or_multiple_actor_targets.s
 * Documented in docs/event-menu-cast-targets.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: YV.
 */
static void write_native_menu_cast_record_single_or_multiple_actor_targets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    i_rep(r, 0x30);
    a_lda(r, RAM16(0x1844));
    r->c = 0;
    a_adc(r, 0xFFF0);
    i_tax(r);
    i_sep(r, 0x20);
    a_lda(r, RAM8(0x1839));
    RAM8(0x0000 + r->x) = r->a;
    a_lda(r, RAM8(0x1846));
    RAM8(0x0007 + r->x) = r->a;
    a_lda(r, 0x00);
    RAM8(0x0008 + r->x) = r->a;
    RAM8(0x0009 + r->x) = r->a;
    RAM8(0x000A + r->x) = r->a;
    RAM8(0x1820) = r->a;
    i_phx(c);
    {
        uint16_t ptr = RAM16(0x1822);
        uint32_t lo, hi;
        a_ldx(r, ptr);
        ADR_DPX(r, 0x01, lo, hi);
        if (!hand_rd_ok(lo)) { c->fail = 3; return; }
        a_lda(r, som_rd(c, lo));
    }
    i_plx(c);
    a_cmp(r, 0xFF);
    if (!r->z) {
        a_and(r, 0x0E);
        i_lsra(r);
        i_inca(r);
        RAM8(0x0008 + r->x) = r->a;
        a_lda(r, 0x01);
        RAM8(0x0006 + r->x) = r->a;
        RETURN_RTS(c);
    }
    a_ldy(r, 0x0000);
    a_lda(r, RAM8(0x1842));
    if (r->n) {
        i_iny(r);
        i_iny(r);
        i_iny(r);
    }
    i_tya(r);
    i_phx(c);
    i_inca(r);
    a_ldy(r, RAM16(0x1812));
    a_cpy(r, 0x0000);
    if (!r->z) {
        RAM8(0x0008 + r->x) = r->a;
        RAM8(0x1820) = m_inc(r, RAM8(0x1820));
        i_inx(r);
    }
    i_inca(r);
    a_ldy(r, RAM16(0x1814));
    a_cpy(r, 0x0000);
    if (!r->z) {
        RAM8(0x0008 + r->x) = r->a;
        RAM8(0x1820) = m_inc(r, RAM8(0x1820));
        i_inx(r);
    }
    i_inca(r);
    a_ldy(r, RAM16(0x1816));
    a_cpy(r, 0x0000);
    if (!r->z) {
        RAM8(0x0008 + r->x) = r->a;
        RAM8(0x1820) = m_inc(r, RAM8(0x1820));
    }
    i_plx(c);
    a_lda(r, RAM8(0x1820));
    RAM8(0x0006 + r->x) = r->a;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0731F, SOM_RTS, "hand", write_native_menu_cast_record_single_or_multiple_actor_targets, 0, L_Y | L_V, 2, 0, 0, 141, 60)
