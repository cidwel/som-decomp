; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-navigation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $81ED
derive_complete_map_target_from_ui_coordinate_sectors:
    sep #$30
    .a8
    lda #$01
    sta $E8
    lda $FD
    .a8
    and #$0C
    sta $00
    lda $FB
    .a8
    and #$0C
    lsr
    lsr
    ora $00
    asl
    asl
    asl
    asl
    sta $00
    stz $01
    rep #$20
    sep #$30
    lda $FD
    .a8
    and #$03
    asl
    asl
    sta $02
    lda $FB
    .a8
    and #$03
    ora $02
    rep #$30
    .a16
    and #$00FF
    clc
    adc $00
    sta $00
    lda $00
    asl
    adc $00
    tax
    lda f:$C67780,X
    .a16
    and #$01FF
    sta $DC
    .a16
    ora #$8000
    sta a:$010E
    sep #$20
    lda f:$C67781,X
    lsr
    sta $DE
    lda f:$C67782,X
    sta $DF
    .a8
    lda #$E0
    sta $E0
    rts
