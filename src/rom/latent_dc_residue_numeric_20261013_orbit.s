; Numeric placement/transfer metadata, no pixel or tile bodies.
.setcpu "65816"
.segment "RODATA"
.org $FC42
latent_dc_residue_numeric_20261013_orbit:
.macro packed_sprite_control tile_code, orientation, field2_nibble, field4_nibble
    .byte tile_code | (orientation << 6), (field2_nibble << 4) | field4_nibble
.endmacro
latent_dc_residue_numeric_20261013_orbit_phase_00:
    packed_sprite_control $00, 0, 5, 6 ; record 0
    packed_sprite_control $20, 0, 9, 6 ; record 1
    packed_sprite_control $3F, 3, 15, 15 ; record 2 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 3 (lowFF hide sentinel; upper byte retained)
latent_dc_residue_numeric_20261013_orbit_phase_01:
    packed_sprite_control $04, 0, 5, 5 ; record 0
    packed_sprite_control $06, 0, 5, 9 ; record 1
    packed_sprite_control $24, 0, 9, 5 ; record 2
    packed_sprite_control $26, 0, 9, 9 ; record 3
latent_dc_residue_numeric_20261013_orbit_phase_02:
    packed_sprite_control $08, 0, 5, 5 ; record 0
    packed_sprite_control $0A, 0, 5, 9 ; record 1
    packed_sprite_control $28, 0, 9, 5 ; record 2
    packed_sprite_control $2A, 0, 9, 9 ; record 3
latent_dc_residue_numeric_20261013_orbit_phase_03:
    packed_sprite_control $0C, 0, 5, 5 ; record 0
    packed_sprite_control $0E, 0, 5, 9 ; record 1
    packed_sprite_control $2C, 0, 9, 5 ; record 2
    packed_sprite_control $2E, 0, 9, 9 ; record 3
latent_dc_residue_numeric_20261013_orbit_phase_04:
    packed_sprite_control $3F, 3, 15, 15 ; record 0 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 1 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 2 (lowFF hide sentinel; upper byte retained)
    packed_sprite_control $3F, 3, 15, 15 ; record 3 (lowFF hide sentinel; upper byte retained)
