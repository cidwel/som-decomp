; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DBDA
move_primary_camera_horizontal:
    sep #$30
    lda $84
    bmi move_primary_camera_horizontal_c0dbfb
    rep #$20
    .a16
    and #$000F
    pha
    clc
    adc $A8
    cmp $C0
    bcc move_primary_camera_horizontal_c0dbef
    sbc $C0
move_primary_camera_horizontal_c0dbef:
    sta $A8
    pla
    clc
    adc $B0
    .a16
    and #$01FF
    sta $B0
    rts
move_primary_camera_horizontal_c0dbfb:
    rep #$20
    .a16
    and #$007F
    sta $00
    lda $B0
    sec
    sbc $00
    .a16
    and #$01FF
    sta $B0
    lda $A8
    sec
    sbc $00
    bcs move_primary_camera_horizontal_c0dc15
    adc $C0
move_primary_camera_horizontal_c0dc15:
    sta $A8
    rts
