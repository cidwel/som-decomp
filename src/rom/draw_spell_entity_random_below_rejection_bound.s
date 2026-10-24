; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-entity-mode-two.md.
.setcpu "65816"
.smart
.a8
.i16

draw_spell_entity_random_byte = $46B0
find_highest_set_entity_flag_bit = $4720

.segment "CODE"
.org $46C3
draw_spell_entity_random_below_rejection_bound:
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
    .a16
    and #$00FF
    bne draw_spell_entity_random_below_rejection_bound_c146d9
    .a16
    lda #$0100
draw_spell_entity_random_below_rejection_bound_c146d9:
    sta $01
    dec
    beq draw_spell_entity_random_below_rejection_bound_c146fd
    tax
    jsr find_highest_set_entity_flag_bit
    sec
    .a16
    sbc #$0008
    .a16
    eor #$FFFF
    inc
    tay
    .a16
    lda #$01FF
draw_spell_entity_random_below_rejection_bound_c146ee:
    lsr
    dey
    bne draw_spell_entity_random_below_rejection_bound_c146ee
    sta $03
draw_spell_entity_random_below_rejection_bound_c146f4:
    jsr draw_spell_entity_random_byte
    and $03
    cmp $01
    bcs draw_spell_entity_random_below_rejection_bound_c146f4
draw_spell_entity_random_below_rejection_bound_c146fd:
    sep #$20
    sta $04,S
    pla
    pla
    pla
    pla
    plp
    pld
    rts
