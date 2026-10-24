; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DC18
move_primary_camera_vertical:
    sep #$30
    lda $86
    bmi move_primary_camera_vertical_c0dc39
    rep #$20
    .a16
    and #$000F
    pha
    clc
    adc $AA
    cmp $C2
    bcc move_primary_camera_vertical_c0dc2d
    sbc $C2
move_primary_camera_vertical_c0dc2d:
    sta $AA
    pla
    clc
    adc $B2
    .a16
    and #$01FF
    sta $B2
    rts
move_primary_camera_vertical_c0dc39:
    rep #$20
    .a16
    and #$000F
    sta $00
    lda $B2
    sec
    sbc $00
    .a16
    and #$01FF
    sta $B2
    lda $AA
    sec
    sbc $00
    bcs move_primary_camera_vertical_c0dc53
    adc $C2
move_primary_camera_vertical_c0dc53:
    sta $AA
    rts
