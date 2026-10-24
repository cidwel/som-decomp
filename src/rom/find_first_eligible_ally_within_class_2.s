; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
classify_actor_squared_distance = $0358
reject_ineligible_or_nonmonster_actor = $058B

.segment "CODE"
.org $0C08
find_first_eligible_ally_within_class_2:
    phd
    php
    rep #$20
    phb
    tsc
    tcd
    sep #$20
    .a8
    lda #$03
    sta $01
    .i16
    ldx #$E600
find_first_eligible_ally_within_class_2_c10c18:
    jsr reject_ineligible_or_nonmonster_actor
    bcs find_first_eligible_ally_within_class_2_c10c26
    jsr classify_actor_squared_distance
    .a8
    cmp #$02
    beq find_first_eligible_ally_within_class_2_c10c38
    bcc find_first_eligible_ally_within_class_2_c10c38
find_first_eligible_ally_within_class_2_c10c26:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_eligible_ally_within_class_2_c10c18
    .a8
    lda #$FF
    bra find_first_eligible_ally_within_class_2_c10c3b
find_first_eligible_ally_within_class_2_c10c38:
    jsr actor_slot_from_address_high_byte
find_first_eligible_ally_within_class_2_c10c3b:
    sta $01,S
    pla
    plp
    pld
    rts
