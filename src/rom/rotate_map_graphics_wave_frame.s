; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

rotate_map_graphics_wave_plane = $B6BF

.segment "CODE"
.org $B6B4
rotate_map_graphics_wave_frame:
    phx
    jsr rotate_map_graphics_wave_plane
    plx
    phx
    jsr rotate_map_graphics_wave_plane
    plx
    rts
