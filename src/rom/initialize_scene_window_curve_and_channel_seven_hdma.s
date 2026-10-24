; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9550
initialize_scene_window_curve_and_channel_seven_hdma:
    sep #$30
    .a8
    lda #$00
    sta $2D
    sta a:$2123
    .i8
    ldx #$00
    .i8
    ldy #$00
initialize_scene_window_curve_and_channel_seven_hdma_c0955d:
    lda a:$96E2,Y
    sta $00
    .a8
    ora #$80
    sta a:$1833,X
    .a8
    lda #$80
    sec
    sbc $00
    sta a:$1832,X
    inx
    inx
    iny
    .i8
    cpx #$20
    bcc initialize_scene_window_curve_and_channel_seven_hdma_c0955d
    .a8
    lda #$01
    sta a:$1830
    sta a:$1850
    .a8
    lda #$00
    sta a:$1831
    sta a:$1851
    .i8
    ldx #$00
initialize_scene_window_curve_and_channel_seven_hdma_c09588:
    lda a:$9594,X
    sta a:$4370,X
    inx
    .i8
    cpx #$08
    bcc initialize_scene_window_curve_and_channel_seven_hdma_c09588
    rts
