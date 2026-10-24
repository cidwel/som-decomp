; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

move_primary_camera_horizontal = $DBDA
move_primary_camera_vertical = $DC18
move_secondary_camera_horizontal = $DC56
move_secondary_camera_vertical = $DC99
scale_camera_motion_for_layer = $DAEB

.segment "CODE"
.org $DA81
move_primary_then_secondary_map_cameras:
    lda $84
    beq move_primary_then_secondary_map_cameras_c0da88
    jsr move_primary_camera_horizontal
move_primary_then_secondary_map_cameras_c0da88:
    sep #$30
    lda $86
    beq move_primary_then_secondary_map_cameras_c0da91
    jsr move_primary_camera_vertical
move_primary_then_secondary_map_cameras_c0da91:
    sep #$30
    lda $84
    beq move_primary_then_secondary_map_cameras_c0daa5
    .i8
    ldx #$20
    jsr scale_camera_motion_for_layer
    bcs move_primary_then_secondary_map_cameras_c0daa5
    sta $84
    jsr move_secondary_camera_horizontal
    sep #$30
move_primary_then_secondary_map_cameras_c0daa5:
    lda $86
    beq move_primary_then_secondary_map_cameras_c0dab5
    .i8
    ldx #$30
    jsr scale_camera_motion_for_layer
    bcs move_primary_then_secondary_map_cameras_c0dab5
    sta $86
    jsr move_secondary_camera_vertical
move_primary_then_secondary_map_cameras_c0dab5:
    rts
