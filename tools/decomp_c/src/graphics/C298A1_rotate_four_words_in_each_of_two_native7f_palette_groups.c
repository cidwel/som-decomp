#include "som_c.h"

/* C298A1 rotate_four_words_in_each_of_two_native7f_palette_groups   [class A, 57 bytes, 21 instructions]
 * Source: src/rom/rotate_four_words_in_each_of_two_native7f_palette_groups.s
 * Documented in docs/boss-native7f-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void rotate_four_words_in_each_of_two_native7f_palette_groups_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RAM16_SET(0x0395, RAM16(0x07BE));
    RAM16_SET(0x07BE, RAM16(0x07BC));
    RAM16_SET(0x07BC, RAM16(0x07BA));
    RAM16_SET(0x07BA, RAM16(0x07B8));
    RAM16_SET(0x07B8, RAM16(0x0395));
    RAM16_SET(0x0395, RAM16(0x07DE));
    RAM16_SET(0x07DE, RAM16(0x07DC));
    RAM16_SET(0x07DC, RAM16(0x07DA));
    RAM16_SET(0x07DA, RAM16(0x07D8));
    RAM16_SET(0x07D8, RAM16(0x0395));
    RETURN_RTS(c);
}

/* C298A1 rotate_four_words_in_each_of_two_native7f_palette_groups   [class A, 57 bytes, 21 instructions]
 * Source: src/rom/rotate_four_words_in_each_of_two_native7f_palette_groups.s
 * Documented in docs/boss-native7f-setup.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void rotate_four_words_in_each_of_two_native7f_palette_groups_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RAM8(0x0395) = RAM8(0x07BE);
    RAM8(0x07BE) = RAM8(0x07BC);
    RAM8(0x07BC) = RAM8(0x07BA);
    RAM8(0x07BA) = RAM8(0x07B8);
    RAM8(0x07B8) = RAM8(0x0395);
    RAM8(0x0395) = RAM8(0x07DE);
    RAM8(0x07DE) = RAM8(0x07DC);
    RAM8(0x07DC) = RAM8(0x07DA);
    RAM8(0x07DA) = RAM8(0x07D8);
    RAM8(0x07D8) = RAM8(0x0395);
    RETURN_RTS(c);
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void rotate_four_words_in_each_of_two_native7f_palette_groups(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { rotate_four_words_in_each_of_two_native7f_palette_groups_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { rotate_four_words_in_each_of_two_native7f_palette_groups_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC298A1, SOM_RTS, "gen", rotate_four_words_in_each_of_two_native7f_palette_groups, 0, 0, 1, -1, -1, 57, 21)
