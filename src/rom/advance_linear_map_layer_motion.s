; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_automatic_map_camera_motion = $DBBA

.segment "CODE"
.org $DB9E
advance_linear_map_layer_motion:
    lda a:$0A84,X
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$0A86,X
    sep #$20
    sta a:$0A84,X
    lda a:$0A85,X
    bpl advance_linear_map_layer_motion_c0dbb9
    xba
    .a8
    ora #$80
    bra dispatch_automatic_map_camera_motion
advance_linear_map_layer_motion_c0dbb9:
    xba
