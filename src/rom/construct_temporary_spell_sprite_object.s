; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-objects.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c12e78 = $C12E78
routine_c12e80 = $C12E80
routine_c12eb1 = $C12EB1

.segment "CODE"
.org $ED5F
construct_temporary_spell_sprite_object:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0007
    tcd
    tcs
    lda $08,S
    sep #$20
    sta $01
    xba
    sta $08
    stx $02
    lda a:$0018,Y
    sta $09
    .i16
    ldx #$0240
    .a8
    lda #$F0
    jsl f:routine_c12e78
    stx $04
    lda $01
    sta a:$023A,X
    stz a:$023B,X
    stz a:$023C,X
    stz a:$0237,X
    stz a:$0234,X
    lda $02
    rep #$20
    .a16
    and #$00FF
    sta a:$0052,X
    sta a:$0238,X
    lda $03
    .a16
    and #$00FF
    sta a:$0050,X
    sta a:$0235,X
    clc
    txa
    .a16
    adc #$0230
    tax
    lda $08
    jsl f:routine_c12eb1
    .a16
    lda #$000A
    sta $06
    sep #$20
    lda $09
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$07
    sta $09
    ldy $04
construct_temporary_spell_sprite_object_d3edce:
    phy
    .a8
    lda #$03
    jsl f:routine_c12e80
    lda $09
    sta a:$0001,X
    .a8
    lda #$F0
    sta a:$0002,X
    rep #$20
    txa
    ply
    sta a:$0000,Y
    ldx $06
    dex
    sep #$20
    lda f:$DCF88F,X
    sta a:$0006,Y
    lda f:$DCF899,X
    sta a:$0007,Y
    clc
    rep #$20
    tya
    .a16
    adc #$0008
    tay
    sep #$20
    dec $06
    bne construct_temporary_spell_sprite_object_d3edce
    ldx $04
    rep #$20
    tsc
    clc
    .a16
    adc #$0009
    tcs
    plp
    pld
    rts
