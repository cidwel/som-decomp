; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-objects.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_heap_bank_long = $C12E7C
routine_c12e88 = $C12E88

.segment "CODE"
.org $EC03
release_spell_entity_burst_sprite_object:
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
    txy
    .a16
    lda #$0005
    sta $01
release_spell_entity_burst_sprite_object_d3ec1f:
    sty $05
    ldx a:$0000,Y
    jsl f:routine_c12e88
    ldy $05
    clc
    tya
    .a16
    adc #$0010
    tay
    dec $01
    bne release_spell_entity_burst_sprite_object_d3ec1f
    ldx $03
    jsl f:release_spell_entity_heap_bank_long
    plb
    tsc
    clc
    .a16
    adc #$0006
    tcs
    plp
    pld
    rts
