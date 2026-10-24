; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-fallback-lifecycle.md.
.setcpu "65816"
.smart
.a8
.i16

release_spell_entity_heap_bank_long = $C12E7C
release_spell_sprite_instance_long = $C12E88

.segment "CODE"
.org $FE3D
release_random_fallback_object:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    stx $03
    txy
    .a16
    lda #$0014
    sta $01
release_random_fallback_object_d3fe50:
    ldx a:$0000,Y
    phy
    jsl f:release_spell_sprite_instance_long
    pla
    clc
    .a16
    adc #$0010
    tay
    dec $01
    bne release_random_fallback_object_d3fe50
    ldx $03
    jsl f:release_spell_entity_heap_bank_long
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
