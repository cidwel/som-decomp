; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-sprite-motion.md.
.setcpu "65816"
.smart
.a8
.i16

advance_spell_sprite_object_motion = $EFC4
derive_spell_sprite_object_target_vectors = $F0B1

.segment "CODE"
.org $F15D
update_spell_sprite_object:
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
    lda a:$023D,X
    dec
    sta a:$023D,X
    bne update_spell_sprite_object_d3f180
    .a8
    lda #$06
    sta a:$023D,X
    jmp update_spell_sprite_object_d3f215
update_spell_sprite_object_d3f180:
    .a8
    cmp #$02
    bne update_spell_sprite_object_d3f187
    jmp update_spell_sprite_object_d3f215
update_spell_sprite_object_d3f187:
    stx $01
    lda a:$023C,X
    bne update_spell_sprite_object_d3f1d8
    jsr derive_spell_sprite_object_target_vectors
    rep #$20
    txa
    .a16
    bit #$8000
    beq update_spell_sprite_object_d3f19d
    .a16
    eor #$FFFF
    inc
update_spell_sprite_object_d3f19d:
    sta $05
    stz $03
    tya
    .a16
    bit #$8000
    beq update_spell_sprite_object_d3f1ad
    dec $03
    .a16
    eor #$FFFF
    inc
update_spell_sprite_object_d3f1ad:
    ldx $01
    sta f:$004204
    sep #$20
    lda $06
    sta f:$004206
    rep #$20
    pha
    pla
    pha
    pla
    lda f:$004214
    .a16
    cmp #$0020
    sep #$20
    bcs update_spell_sprite_object_d3f1f0
    .a8
    lda #$20
    asl $03
    bcs update_spell_sprite_object_d3f1d5
    .a8
    eor #$FF
    inc
update_spell_sprite_object_d3f1d5:
    sta a:$023C,X
update_spell_sprite_object_d3f1d8:
    .a8
    bit #$80
    bne update_spell_sprite_object_d3f1e6
    sec
    .a8
    sbc #$08
    sta a:$023C,X
    .a8
    lda #$08
    bra update_spell_sprite_object_d3f1f8
update_spell_sprite_object_d3f1e6:
    clc
    .a8
    adc #$08
    sta a:$023C,X
    .a8
    lda #$F8
    bra update_spell_sprite_object_d3f1f8
update_spell_sprite_object_d3f1f0:
    .a8
    lda #$08
    asl $03
    bcc update_spell_sprite_object_d3f1f8
    .a8
    lda #$F8
update_spell_sprite_object_d3f1f8:
    clc
    adc a:$023A,X
    sta a:$023A,X
    rep #$20
    .i16
    ldy #$0005
    lda $05
    cmp a:$023E,X
    bcc update_spell_sprite_object_d3f20e
    .i16
    ldy #$0002
update_spell_sprite_object_d3f20e:
    sta a:$023E,X
    tya
    jsr advance_spell_sprite_object_motion
update_spell_sprite_object_d3f215:
    sep #$20
    .a8
    lda #$FF
    plb
    rep #$20
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
