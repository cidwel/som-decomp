; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

assign_map_object_priority_and_terrain = $DF55
refresh_map_object_identity_graphics_and_ai = $E038
routine_01e01e = $1E01E

.segment "CODE"
.org $DF45
initialize_large_map_object_priority_palette_and_graphics:
    jsr assign_map_object_priority_and_terrain
    jsl f:routine_01e01e
    jsr refresh_map_object_identity_graphics_and_ai
    sec
    rts
