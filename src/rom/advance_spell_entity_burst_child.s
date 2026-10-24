; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-burst-objects.md.
.setcpu "65816"
.smart
.a8
.i16

project_packed_spell_entity_sprite_record_long = $C12E94
routine_c12e8c = $C12E8C
seed_spell_entity_burst_child_velocity = $EA93

.segment "CODE"
.org $EC44
advance_spell_entity_burst_child:
    phd
    php
    rep #$20
    tsc
    sec
    .a16
    sbc #$0006
    tcd
    tcs
    lda a:$000E,Y
    bpl advance_spell_entity_burst_child_d3ec65
    inc
    sta a:$000E,Y
    ldx a:$0000,Y
    jsl f:routine_c12e8c
    .a16
    lda #$0000
    jmp advance_spell_entity_burst_child_d3ecfd
advance_spell_entity_burst_child_d3ec65:
    stx $03
    sty $05
    inc
    sta $01
advance_spell_entity_burst_child_d3ec6c:
    sep #$20
    lda a:$0002,Y
    clc
    adc a:$0008,Y
    sta a:$0002,Y
    rep #$20
    lda a:$0003,Y
    adc a:$0009,Y
    sta a:$0003,Y
    dec $01
    bne advance_spell_entity_burst_child_d3ec6c
    pha
    lda a:$000E,Y
    inc
    sta $01
advance_spell_entity_burst_child_d3ec8e:
    sep #$20
    lda a:$0005,Y
    clc
    adc a:$000B,Y
    sta a:$0005,Y
    rep #$20
    lda a:$0006,Y
    adc a:$000C,Y
    sta a:$0006,Y
    dec $01
    bne advance_spell_entity_burst_child_d3ec8e
    pha
    lda a:$000E,Y
    sep #$20
    xba
    lda a:$000E,Y
    rep #$20
    sta f:$004202
    pha
    pla
    lda f:$004216
    sta f:$004204
    sep #$20
    .a8
    lda #$25
    sta f:$004206
    rep #$20
    pha
    pla
    pha
    pla
    lda f:$004214
    .a16
    and #$FFFE
    clc
    .a16
    adc #$F82E
    sec
    .a16
    sbc #$F800
    tax
    jsl f:project_packed_spell_entity_sprite_record_long
    pla
    pla
    ldy $05
    lda a:$000E,Y
    inc
    sta a:$000E,Y
    .a16
    cmp #$0014
    bcc advance_spell_entity_burst_child_d3ecfa
    ldx $03
    jsr seed_spell_entity_burst_child_velocity
advance_spell_entity_burst_child_d3ecfa:
    .a16
    lda #$FFFF
advance_spell_entity_burst_child_d3ecfd:
    sta $05,S
    tsc
    clc
    .a16
    adc #$0004
    tcs
    pla
    plp
    pld
    rts
