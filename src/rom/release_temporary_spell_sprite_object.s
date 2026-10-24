; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-objects.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c12e7c = $C12E7C
routine_c12e88 = $C12E88

.segment "CODE"
.org $EE18
release_temporary_spell_sprite_object:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    stx $03
    .a16
    lda #$000A
    sta $01
    txa
    clc
    .a16
    adc #$0000
release_temporary_spell_sprite_object_d3ee38:
    sta $05
    tay
    ldx a:$0000,Y
    jsl f:routine_c12e88
    lda $05
    clc
    .a16
    adc #$0008
    dec $01
    bne release_temporary_spell_sprite_object_d3ee38
    ldx $03
    jsl f:routine_c12e7c
    plb
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
