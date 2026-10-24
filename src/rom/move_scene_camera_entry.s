; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

move_primary_then_secondary_map_cameras = $DA81

.segment "CODE"
.org $D1F9
move_scene_camera_entry:
    sep #$30
    jmp move_primary_then_secondary_map_cameras
