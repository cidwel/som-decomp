; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DAEB
scale_camera_motion_for_layer:
    sta $00
    lda a:$0A80,X
    bne scale_camera_motion_for_layer_c0daf4
    sec
    rts
scale_camera_motion_for_layer_c0daf4:
    .a8
    cmp #$01
    bne scale_camera_motion_for_layer_c0db0d
    lda $00
    .a8
    and #$7F
    lsr
    bne scale_camera_motion_for_layer_c0db07
    inc a:$0A81,X
    lda a:$0A81,X
    .a8
    and #$01
scale_camera_motion_for_layer_c0db07:
    asl
    asl $00
    ror
    clc
    rts
scale_camera_motion_for_layer_c0db0d:
    .a8
    cmp #$02
    bne scale_camera_motion_for_layer_c0db15
    lda $00
    clc
    rts
scale_camera_motion_for_layer_c0db15:
    lda $00
    asl
    asl
    asl $00
    ror
    clc
    rts
