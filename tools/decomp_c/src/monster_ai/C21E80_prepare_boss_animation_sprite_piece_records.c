#include "som_c.h"
#include "som_hand_b.h"

/* C21E80 prepare_boss_animation_sprite_piece_records   [class B, 105 bytes, 51 instructions]
 * Source: src/rom/prepare_boss_animation_sprite_piece_records.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: YV.
 */
static void prepare_boss_animation_sprite_piece_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t a = RAM16(0x028D);
    bool short_form = (a & 0x8000) == 0;
    bool overflow = r->v;
    r->xf = 1; /* SEP #$30 happens in both loops before the first call */
    r->mf = 1;
    if (!short_form) {
        a = 0x0010;
        RAM16_SET(0x0270, a);
    }
    r->x &= 0xFF;
    r->y &= 0xFF;
    for (;;) {
        if (short_form) {
            r->y = 3;
            uint8_t flags = BUS8(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + 3);
            uint8_t sel = (flags >> 5) & 1; /* ASL x3 then ROL leaves bit 5 */
            r->x = sel;
            uint8_t colour = BUS8(c, 0xC21EE9 + sel);
            a = (a & 0xFF00) | colour;
            RAM8(0x0270) = colour;
        }
        r->a = a;
        if (short_form) {
            JSR_CHK(c, 0x1E9C, 0xC21EEB); /* prepare_boss_animation_piece_horizontal_offset */
            JSR_CHK(c, 0x1E9F, 0xC21F07); /* prepare_boss_animation_piece_vertical_offset */
            JSR_CHK(c, 0x1EA2, 0xC21F25); /* prepare_boss_animation_piece_tile_attributes */
        } else {
            JSR_CHK(c, 0x1EC7, 0xC21EEB);
            JSR_CHK(c, 0x1ECA, 0xC21F07);
            JSR_CHK(c, 0x1ECD, 0xC21F25);
        }
        r->mf = 0; /* REP #$30 */
        r->xf = 0;
        uint16_t p79 = RAM16(0x0279);
        RAM16_SET(0x0279, (uint16_t)(p79 + 4));
        uint16_t p7c = RAM16(0x027C);
        uint16_t sum = (uint16_t)(p7c + 4);
        RAM16_SET(0x027C, sum);
        overflow = (((p7c ^ sum) & (4 ^ sum)) & 0x8000) != 0;
        RAM16_SET(0x0266, (uint16_t)(RAM16(0x0266) + 1));
        a = RAM16(0x0266);
        if (!(a < RAM16(0x0285))) break;
        r->mf = 1; /* SEP #$30 at the top of the next pass clears the index high bytes */
        r->xf = 1;
        r->x &= 0xFF;
        r->y &= 0xFF;
    }
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21E80, SOM_RTS, "hand", prepare_boss_animation_sprite_piece_records, 0, L_Y | L_V, 1, 0, 0, 105, 51)
