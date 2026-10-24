; Numeric placement/transfer metadata, no pixel or tile bodies.
.setcpu "65816"
.segment "RODATA"
.org $F8E7
latent_dc_residue_numeric_20261013_family_two:
.macro packed_sprite_control tile_code, orientation, field2_nibble, field4_nibble
    .byte tile_code | (orientation << 6), (field2_nibble << 4) | field4_nibble
.endmacro
latent_dc_residue_numeric_20261013_family_two_phase_00:
    packed_sprite_control $00, 0, 0, 0 ; record 0
    packed_sprite_control $02, 0, 0, 4 ; record 1
    packed_sprite_control $20, 0, 4, 0 ; record 2
    packed_sprite_control $22, 0, 4, 4 ; record 3
    packed_sprite_control $04, 0, 8, 0 ; record 4
    packed_sprite_control $06, 0, 8, 4 ; record 5
    packed_sprite_control $24, 0, 12, 0 ; record 6
    packed_sprite_control $26, 0, 12, 4 ; record 7
    packed_sprite_control $00, 3, 12, 12 ; record 8
    packed_sprite_control $02, 3, 12, 8 ; record 9
    packed_sprite_control $20, 3, 8, 12 ; record 10
    packed_sprite_control $22, 3, 8, 8 ; record 11
    packed_sprite_control $04, 3, 4, 12 ; record 12
    packed_sprite_control $06, 3, 4, 8 ; record 13
    packed_sprite_control $24, 3, 0, 12 ; record 14
    packed_sprite_control $26, 3, 0, 8 ; record 15
latent_dc_residue_numeric_20261013_family_two_phase_01:
    packed_sprite_control $3F, 3, 15, 15 ; record 0 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 1 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 2 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 3 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 4 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 5 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 6 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 7 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 8 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 9 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 10 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 11 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 12 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 13 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 14 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 15 (lowFF hide sentinel; upper byte retained)
