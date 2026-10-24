; Recovered Secret of Mana USA routine; behaviour documented in docs/map-tile-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_map_tiles_preserving_cpu_context = $803D

.segment "CODE"
.org $8012
refresh_map_tiles_public_jump:
    jmp refresh_map_tiles_preserving_cpu_context
