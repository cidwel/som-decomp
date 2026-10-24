; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_and_fill_spell_entity_bytes_long = $C12E78
allocate_spell_entity_sprite_pointer_group_long = $C12EB5
position_spell_entity_from_actor_long = $C12EB1

.segment "CODE"
.org $F9B1
construct_spell_family_two_object:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0002
    tcd
    tcs
    lda $03,S
    sep #$20
    sta $01
    lda a:$0018,X
    lsr
    lsr
    lsr
    lsr
    .a8
    and #$07
    sta $04
    .i16
    ldx #$0026
    .a8
    lda #$00
    jsl f:allocate_and_fill_spell_entity_bytes_long
    stx $02
    clc
    rep #$20
    txa
    .a16
    adc #$0020
    tax
    sep #$20
    lda $01
    jsl f:position_spell_entity_from_actor_long
    ldx $02
    lda $01
    .a8
    and #$01
    sta a:$0024,X
    lda $04
    xba
    .a8
    lda #$10
    jsl f:allocate_spell_entity_sprite_pointer_group_long
    ldx $02
    pla
    pla
    pla
    pla
    plp
    pld
    rts
