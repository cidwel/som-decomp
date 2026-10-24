; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-objects.md.
.setcpu "65816"
.smart
.a8
.i16

advance_spell_entity_burst_child = $EC44

.segment "CODE"
.org $ED0D
update_spell_entity_burst_sprite_object:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0007
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    stx $04
    txy
    .a8
    lda #$05
    sta $01
    stz $02
update_spell_entity_burst_sprite_object_d3ed28:
    sty $06
    ldx $04
    jsr advance_spell_entity_burst_child
    .a8
    cmp #$00
    beq update_spell_entity_burst_sprite_object_d3ed35
    inc $02
update_spell_entity_burst_sprite_object_d3ed35:
    ldy $06
    clc
    rep #$20
    tya
    .a16
    adc #$0010
    tay
    sep #$20
    dec $01
    bne update_spell_entity_burst_sprite_object_d3ed28
    ldx $04
    lda a:$0054,X
    ora $02
    beq update_spell_entity_burst_sprite_object_d3ed50
    .a8
    lda #$FF
update_spell_entity_burst_sprite_object_d3ed50:
    plb
    rep #$20
    sta $06,S
    tsc
    clc
    .a16
    adc #$0005
    tcs
    pla
    plp
    pld
    rts
