; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-terminal.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $EFBE
release_selected_party_control_without_palette_or_music:
    ldx $87
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    .a8
    lda #$01
    sta a:$01B4,Y
    .a8
    lda #$7F
    and a:$000E,Y
    sta a:$000E,Y
    rep #$20
    rts
