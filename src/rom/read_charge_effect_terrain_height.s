; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-animation-special-helpers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C1D7
read_charge_effect_terrain_height:
    sep #$20
    .i16
    ldx #$B800
    stx $0A
    .i16
    ldx #$0000
    lda a:$D001,Y
    asl
    bcc read_charge_effect_terrain_height_c2c1ef
    .i16
    ldx #$BC00
    stx $0A
    .i16
    ldx #$4000
read_charge_effect_terrain_height_c2c1ef:
    stx $0C
    rep #$20
    lda a:$D002,Y
    lsr
    lsr
    lsr
    lsr
    sta $0E
    lda a:$D004,Y
    .a16
    and #$0FF0
    asl
    asl
    asl
    ora $0E
    clc
    adc $0C
    tax
    lda f:$7F0000,X
    .a16
    and #$00FF
    asl
    asl
    clc
    adc $0A
    tax
    sep #$20
    lda f:$7F0000,X
    .a8
    and #$30
    rts
