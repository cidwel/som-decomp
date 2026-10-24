; Sparse typed weapon resource headers; pointed graphics/frame data excluded.
.setcpu "65816"
.segment "CODE"
.org $C120
.macro weapon_resource tile_unit_index, frame_index_near_pointer
    .word tile_unit_index, frame_index_near_pointer
.endmacro
weapon_resource_selector_48:
    weapon_resource $01FF, $40E0
