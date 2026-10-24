; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

move_primary_camera_horizontal = $DBDA
move_primary_camera_vertical = $DC18
move_secondary_camera_horizontal = $DC56
move_secondary_camera_vertical = $DC99

.segment "CODE"
.org $DBBA
dispatch_automatic_map_camera_motion:
    .i8
    cpx #$00
    bne dispatch_automatic_map_camera_motion_c0dbc3
    sta $84
    jmp move_primary_camera_horizontal
dispatch_automatic_map_camera_motion_c0dbc3:
    .i8
    cpx #$10
    bne dispatch_automatic_map_camera_motion_c0dbcc
    sta $86
    jmp move_primary_camera_vertical
dispatch_automatic_map_camera_motion_c0dbcc:
    .i8
    cpx #$20
    bne dispatch_automatic_map_camera_motion_c0dbd5
    sta $84
    jmp move_secondary_camera_horizontal
dispatch_automatic_map_camera_motion_c0dbd5:
    sta $86
    jmp move_secondary_camera_vertical
