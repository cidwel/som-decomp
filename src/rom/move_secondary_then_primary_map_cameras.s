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
.org $DAB6
move_secondary_then_primary_map_cameras:
    lda $84
    beq move_secondary_then_primary_map_cameras_c0dabd
    jsr move_secondary_camera_horizontal
move_secondary_then_primary_map_cameras_c0dabd:
    sep #$30
    lda $86
    beq move_secondary_then_primary_map_cameras_c0dac8
    jsr move_secondary_camera_vertical
    sep #$30
move_secondary_then_primary_map_cameras_c0dac8:
    lda $84
    beq move_secondary_then_primary_map_cameras_c0dada
    .i8
    ldx #$00
    jsr scale_camera_motion_for_layer
    bcs move_secondary_then_primary_map_cameras_c0dada
    sta $84
    jsr move_primary_camera_horizontal
    sep #$30
move_secondary_then_primary_map_cameras_c0dada:
    lda $86
    beq move_secondary_then_primary_map_cameras_c0daea
    .i8
    ldx #$10
    jsr scale_camera_motion_for_layer
    bcs move_secondary_then_primary_map_cameras_c0daea
    sta $86
    jsr move_primary_camera_vertical
move_secondary_then_primary_map_cameras_c0daea:
    rts
