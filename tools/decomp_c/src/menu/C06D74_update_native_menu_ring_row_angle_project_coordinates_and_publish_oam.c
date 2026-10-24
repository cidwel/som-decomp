#include "som_c.h"

/* C06D74 update_native_menu_ring_row_angle_project_coordinates_and_publish_oam   [class C, 281 bytes, 133 instructions]
 * Source: src/rom/update_native_menu_ring_row_angle_project_coordinates_and_publish_oam.s
 * Documented in docs/event-menu-ring-row.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: Y.
 */
/* Direct-page,X and absolute,Y accesses of the object records and the OAM buffer.  Reads of addresses the C model does not
 * reproduce (hardware registers, open bus) are outside the contract (fail = 3); writes go through the bus. */
static int load_low(SomCtx *c, uint32_t addr) { return hand_lda_abs(c, addr & 0xFFFF); }
static int store_low(SomCtx *c, uint32_t addr, uint16_t v)
{
    if (c->cpu.mf) BUS8_SET(c, addr & 0xFFFF, v & 0xFF); else BUS16_SET(c, addr & 0xFFFF, v);
    return 1;
}
static int store_low_index(SomCtx *c, uint32_t addr, uint16_t v)   /* STY / STX: the width follows the X flag */
{
    if (c->cpu.xf) BUS8_SET(c, addr & 0xFFFF, v & 0xFF); else BUS16_SET(c, addr & 0xFFFF, v);
    return 1;
}
#define DPX(off) ((uint16_t)(r->dp + (off) + r->x))
#define LOAD_DPX(off) do { if (!load_low(c, DPX(off))) return; } while (0)
#define STORE_DPX(off, v) do { if (!store_low(c, DPX(off), (v))) return; } while (0)
#define LOAD_ABS(addr) do { if (!load_low(c, (addr))) return; } while (0)
#define STORE_ABS(addr, v) do { if (!store_low(c, (addr), (v))) return; } while (0)

static void update_native_menu_ring_row_angle_project_coordinates_and_publish_oam(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    i_sep(r, 0x20);
    LOAD_ABS(0x1812);
    if (r->z) {
        LOAD_ABS(0x1806);
        if (r->z) goto project;
        if (!r->n) goto subtract_speed;
        goto add_speed;
    } else {
        a_cmp(r, 0x03);
        if (r->c) goto add_speed;
        goto subtract_speed;
    }
subtract_speed:
    i_rep(r, 0x20);
    LOAD_DPX(0x08);
    i_tay(r);
    r->c = 1;
    a_sbc(r, RAM16(0x1824));
    goto angle_updated;
add_speed:
    i_rep(r, 0x20);
    LOAD_DPX(0x08);
    i_tay(r);
    r->c = 0;
    a_adc(r, RAM16(0x1824));
angle_updated:
    i_pha(c);
    a_and(r, 0x03FF);
    STORE_DPX(0x08, r->a);
    if (r->z) {
        i_pla(c);
        i_sep(r, 0x20);
        STORE_ABS(0x1807, 0);
    } else {
        i_pla(c);
        a_and(r, 0xFC00);
        if (r->z) goto project;
        i_tya(r);
        a_cmp(r, 0x0000);
        if (r->z) goto project;
    }
    /* the row crossed a ring position: advance the highlighted entry */
    i_sep(r, 0x20);
    LOAD_ABS(0x1806);
    r->c = 0;
    {
        uint8_t cursor = c->wram[0x180A];
        a_adc(r, cursor);
    }
    STORE_ABS(0x180A, 0);
    {
        uint8_t entries = c->wram[0x180B];
        a_cmp(r, entries);
        if (r->c) {
            if (r->n) {
                a_lda(r, entries);
                i_deca(r);
                STORE_ABS(0x180A, r->a);
            }
        } else {
            STORE_ABS(0x180A, r->a);
        }
    }
    i_sep(r, 0x20);
    LOAD_ABS(0x1812);
    if (r->z) {
        i_rep(r, 0x20);
        { const uint16_t sp_call = r->sp; JSL(c, 0x6DDE, 0xD0CF10); GUARD_JSL(c, sp_call, 0x6DDE); } /* request_native_menu_audio_29 */
    }
project:
    i_rep(r, 0x30);
    i_phx(c);
    LOAD_ABS(0x181A);
    STORE_ABS(0x186A, r->a);
    LOAD_DPX(0x08);
    i_pha(c);
    LOAD_ABS(0x1847);
    a_and(r, 0x00FF);
    i_deca(r);
    if (r->z) {
        const uint16_t slot = (uint16_t)(r->sp + 1);
        a_lda(r, (uint16_t)(c->wram[slot] | (c->wram[(uint16_t)(slot + 1)] << 8)));   /* LDA $01,S: the saved angle */
        r->c = 0;
        a_adc(r, 0x0200);
        c->wram[slot] = r->a & 0xFF;
        c->wram[(uint16_t)(slot + 1)] = r->a >> 8;
    }
    i_pla(c);
    STORE_ABS(0x1868, r->a);
    { const uint16_t sp_call = r->sp; JSL(c, 0x6E03, 0xD9FC00); GUARD_JSL(c, sp_call, 0x6E03); } /* project_native_menu_ring_angle_and_radius_to_centered_coordinates */
    HAND_REQUIRE_WIDE(c);                  /* the code below is assembled for 16-bit A and index registers */
    i_plx(c);
    STORE_DPX(0x04, r->a);
    if (!store_low_index(c, DPX(0x02), r->y)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6E0B, 0xC06E8D); GUARD_JSR(c, sp_call, 0x6E0B); HAND_REQUIRE_WIDE(c); } /* test_native_menu_ring_row_coordinates_for_visibility */
    if (r->c) {
        a_lda(r, 0x00E8);
        STORE_DPX(0x04, r->a);
    } else {
        STORE_ABS(0x180C, 0);
    }
    a_ldy(r, c->wram[0x1832] | (c->wram[0x1833] << 8));
    i_sep(r, 0x20);
    LOAD_DPX(0x00);
    if (r->n) {
        STORE_ABS(0x1822, m_inc(r, c->wram[0x1822]));
        LOAD_ABS(0x1822);
        a_cmp(r, 0x05);
        if (r->c) {
            a_cmp(r, 0x09);
            if (r->c) STORE_ABS(0x1822, 0);
            a_lda(r, 0xE8);
            STORE_DPX(0x04, r->a);
        }
    }
    LOAD_DPX(0x04);
    i_xba(r);
    LOAD_DPX(0x02);
    i_rep(r, 0x20);
    STORE_ABS(r->y, r->a);
    i_iny(r);
    i_iny(r);
    LOAD_ABS(0x1822);
    if (r->z) {
        LOAD_DPX(0x06);
    } else {
        LOAD_DPX(0x00);
        if (!r->n) {
            LOAD_DPX(0x06);
        } else {
            LOAD_DPX(0x06);
            r->c = 0;
            {
                uint16_t offset = c->wram[0x1822] | (c->wram[0x1823] << 8);
                a_adc(r, offset);
            }
        }
    }
    STORE_ABS(r->y, r->a);
    i_iny(r);
    i_iny(r);
    c->wram[0x1832] = r->y;
    c->wram[0x1833] = r->y >> 8;
    LOAD_DPX(0x0A);
    if (!r->z) {
        i_tay(r);
        i_sep(r, 0x20);
        LOAD_ABS(0x1847);
        i_deca(r);
        if (!r->z) {
            LOAD_DPX(0x04);
            a_cmp(r, 0xE8);
            if (!r->z) {
                i_xba(r);
                LOAD_DPX(0x02);
                i_rep(r, 0x20);
                r->c = 0;
                a_adc(r, 0x0505);
                STORE_ABS(r->y, r->a);
                LOAD_DPX(0x02);
                a_cmp(r, 0x00FB);
                if (!r->c) goto done;
            }
            i_sep(r, 0x20);
            a_lda(r, 0xE8);
            STORE_ABS((uint32_t)r->y + 1, r->a);
        }
    }
done:
    i_rep(r, 0x30);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06D74, SOM_RTS, "hand", update_native_menu_ring_row_angle_project_coordinates_and_publish_oam, 0, L_Y, 16, 0, 0, 281, 133)
