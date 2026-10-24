; Numeric placement/transfer metadata, no pixel or tile bodies.
.setcpu "65816"
.segment "RODATA"
.org $FB3D
latent_dc_residue_numeric_20261013_twin:
.macro packed_sprite_control tile_code, orientation, field2_nibble, field4_nibble
    .byte tile_code | (orientation << 6), (field2_nibble << 4) | field4_nibble
.endmacro
latent_dc_residue_numeric_20261013_twin_phase_00:
    packed_sprite_control $30, 0, 6, 6 ; record 0
    packed_sprite_control $3F, 3, 15, 15 ; record 1 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 2 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 3 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 4 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 5 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 6 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 7 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 8 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 9 (lowFF hide sentinel; upper byte retained)
latent_dc_residue_numeric_20261013_twin_phase_01:
    packed_sprite_control $20, 0, 5, 5 ; record 0
    packed_sprite_control $20, 1, 5, 7 ; record 1
    packed_sprite_control $10, 2, 9, 5 ; record 2
    packed_sprite_control $10, 3, 9, 7 ; record 3
    packed_sprite_control $3F, 3, 15, 15 ; record 4 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 5 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 6 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 7 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 8 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 9 (lowFF hide sentinel; upper byte retained)
latent_dc_residue_numeric_20261013_twin_phase_02:
    packed_sprite_control $32, 0, 4, 4 ; record 0
    packed_sprite_control $32, 1, 4, 8 ; record 1
    packed_sprite_control $32, 2, 8, 4 ; record 2
    packed_sprite_control $32, 3, 8, 8 ; record 3
    packed_sprite_control $3F, 3, 15, 15 ; record 4 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 5 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 6 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 7 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 8 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 9 (lowFF hide sentinel; upper byte retained)
latent_dc_residue_numeric_20261013_twin_phase_03:
    packed_sprite_control $15, 0, 3, 3 ; record 0
    packed_sprite_control $16, 1, 3, 7 ; record 1
    packed_sprite_control $14, 1, 3, 11 ; record 2
    packed_sprite_control $25, 2, 7, 3 ; record 3
    packed_sprite_control $26, 3, 7, 7 ; record 4
    packed_sprite_control $24, 3, 7, 11 ; record 5
    packed_sprite_control $05, 2, 11, 3 ; record 6
    packed_sprite_control $06, 3, 11, 7 ; record 7
    packed_sprite_control $04, 3, 11, 11 ; record 8
    packed_sprite_control $3F, 3, 15, 15 ; record 9 (lowFF hide sentinel; upper byte retained)
latent_dc_residue_numeric_20261013_twin_phase_04:
    packed_sprite_control $0A, 0, 0, 4 ; record 0
    packed_sprite_control $0A, 1, 0, 8 ; record 1
    packed_sprite_control $29, 0, 4, 2 ; record 2
    packed_sprite_control $34, 0, 4, 6 ; record 3
    packed_sprite_control $29, 1, 4, 10 ; record 4
    packed_sprite_control $29, 2, 8, 2 ; record 5
    packed_sprite_control $34, 2, 8, 6 ; record 6
    packed_sprite_control $29, 3, 8, 10 ; record 7
    packed_sprite_control $0A, 2, 12, 4 ; record 8
    packed_sprite_control $0A, 3, 12, 8 ; record 9
latent_dc_residue_numeric_20261013_twin_phase_05:
    packed_sprite_control $1D, 0, 3, 3 ; record 0
    packed_sprite_control $1E, 1, 3, 7 ; record 1
    packed_sprite_control $1C, 1, 3, 11 ; record 2
    packed_sprite_control $2D, 2, 7, 3 ; record 3
    packed_sprite_control $2E, 3, 7, 7 ; record 4
    packed_sprite_control $2C, 3, 7, 11 ; record 5
    packed_sprite_control $0D, 2, 11, 3 ; record 6
    packed_sprite_control $0E, 3, 11, 7 ; record 7
    packed_sprite_control $0C, 3, 11, 11 ; record 8
    packed_sprite_control $3F, 3, 15, 15 ; record 9 (lowFF hide sentinel; upper byte retained)
latent_dc_residue_numeric_20261013_twin_phase_06:
    packed_sprite_control $36, 0, 4, 4 ; record 0
    packed_sprite_control $36, 1, 4, 8 ; record 1
    packed_sprite_control $36, 2, 8, 4 ; record 2
    packed_sprite_control $36, 3, 8, 8 ; record 3
    packed_sprite_control $3F, 3, 15, 15 ; record 4 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 5 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 6 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 7 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 8 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 9 (lowFF hide sentinel; upper byte retained)
latent_dc_residue_numeric_20261013_twin_phase_07:
    packed_sprite_control $22, 0, 5, 5 ; record 0
    packed_sprite_control $22, 1, 5, 7 ; record 1
    packed_sprite_control $12, 2, 9, 5 ; record 2
    packed_sprite_control $12, 3, 9, 7 ; record 3
    packed_sprite_control $3F, 3, 15, 15 ; record 4 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 5 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 6 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 7 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 8 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 9 (lowFF hide sentinel; upper byte retained)
latent_dc_residue_numeric_20261013_twin_phase_08:
    packed_sprite_control $38, 0, 4, 6 ; record 0
    packed_sprite_control $38, 2, 8, 6 ; record 1
    packed_sprite_control $3F, 3, 15, 15 ; record 2 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 3 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 4 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 5 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 6 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 7 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 8 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 9 (lowFF hide sentinel; upper byte retained)
latent_dc_residue_numeric_20261013_twin_phase_09:
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
