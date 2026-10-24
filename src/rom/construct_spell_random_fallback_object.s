; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_bytes_long = $C12E78
position_spell_entity_from_actor_long = $C12EB1
routine_c12e80 = $C12E80

.segment "CODE"
.org $FDBD
construct_spell_random_fallback_object:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0005
    tcd
    tcs
    lda $06,S
    sep #$20
    sta $03
    lda a:$0018,X
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$07
    sta $06
    .i16
    ldx #$014A
    .a8
    lda #$00
    jsl f:allocate_and_fill_spell_entity_bytes_long
    stx $04
    clc
    rep #$20
    txa
    .a16
    adc #$0140
    tax
    sep #$20
    lda $03
    jsl f:position_spell_entity_from_actor_long
    ldx $04
    stz $07
    rep #$20
    .a16
    lda #$0014
    sta $01
construct_spell_random_fallback_object_d3fe00:
    phx
    .a16
    lda #$000F
    jsl f:routine_c12e80
    lda $06
    sta a:$0001,X
    txa
    plx
    sta a:$0000,X
    .a16
    lda #$FFFF
    sta a:$000C,X
    clc
    txa
    .a16
    adc #$0010
    tax
    dec $01
    bne construct_spell_random_fallback_object_d3fe00
    ldx $04
    .a16
    lda #$0001
    sta a:$0148,X
    .a16
    lda #$0014
    sta a:$0146,X
    tsc
    clc
    .a16
    adc #$0007
    tcs
    plp
    pld
    rts
