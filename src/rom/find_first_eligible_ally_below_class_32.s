; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
classify_actor_squared_distance = $0358
reject_ineligible_or_nonmonster_actor = $058B



.segment "CODE"
.org $0CE3
find_first_eligible_ally_below_class_32:
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
find_first_eligible_ally_below_class_32_c10cf3:
    jsr reject_ineligible_or_nonmonster_actor
    bcs find_first_eligible_ally_below_class_32_c10d05
    jsr classify_actor_squared_distance
    .a8
    cmp #$20
    bmi find_first_eligible_ally_below_class_32_c10d03
    bvs find_first_eligible_ally_below_class_32_c10d17
    bra find_first_eligible_ally_below_class_32_c10d05
find_first_eligible_ally_below_class_32_c10d03:
    bvc find_first_eligible_ally_below_class_32_c10d17
find_first_eligible_ally_below_class_32_c10d05:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_eligible_ally_below_class_32_c10cf3
    .a8
    lda #$FF
    bra find_first_eligible_ally_below_class_32_c10d1a
find_first_eligible_ally_below_class_32_c10d17:
    jsr actor_slot_from_address_high_byte
find_first_eligible_ally_below_class_32_c10d1a:
    sta $01,S
    pla
    plp
    pld
    rts
