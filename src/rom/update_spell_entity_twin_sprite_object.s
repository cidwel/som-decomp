; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-twin-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

place_spell_entity_twin_sprite_group_randomly = $2DB0
publish_spell_entity_twin_sprite_group = $2D63

.segment "CODE"
.org $2E06
update_spell_entity_twin_sprite_object:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    sep #$20
    lda a:$0039,X
    beq update_spell_entity_twin_sprite_object_c12e6f
    stx $01
    lda a:$0038,X
    .a8
    eor #$FF
    sta a:$0038,X
    beq update_spell_entity_twin_sprite_object_c12e2e
    clc
    rep #$20
    txa
    .a16
    adc #$001A
    tax
    sep #$20
update_spell_entity_twin_sprite_object_c12e2e:
    stx $03
update_spell_entity_twin_sprite_object_c12e30:
    lda a:$0018,X
    bmi update_spell_entity_twin_sprite_object_c12e63
    .a8
    cmp #$0A
    bcc update_spell_entity_twin_sprite_object_c12e5e
    ldy $01
    lda a:$0039,Y
    dec
    sta a:$0039,Y
    .a8
    cmp #$02
    bcc update_spell_entity_twin_sprite_object_c12e57
    clc
    rep #$20
    tya
    .a16
    adc #$0034
    tay
    sep #$20
    jsr place_spell_entity_twin_sprite_group_randomly
    ldx $03
    bra update_spell_entity_twin_sprite_object_c12e30
update_spell_entity_twin_sprite_object_c12e57:
    .a8
    lda #$80
    sta a:$0018,X
    bra update_spell_entity_twin_sprite_object_c12e63
update_spell_entity_twin_sprite_object_c12e5e:
    jsr publish_spell_entity_twin_sprite_group
    ldx $03
update_spell_entity_twin_sprite_object_c12e63:
    inc a:$0018,X
    ldx $01
    lda a:$0039,X
    beq update_spell_entity_twin_sprite_object_c12e6f
    .a8
    lda #$FF
update_spell_entity_twin_sprite_object_c12e6f:
    sta $04,S
    pla
    pla
    pla
    pla
    plp
    pld
    rts
