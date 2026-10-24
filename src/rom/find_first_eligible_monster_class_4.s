; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
classify_actor_squared_distance = $0358
test_eligible_actor_id_at_least_83 = $0598

.segment "CODE"
.org $0E08
find_first_eligible_monster_class_4:
    phd
    php
    rep #$20
    phb
    tsc
    tcd
    sep #$20
    .a8
    lda #$0C
    sta $01
    .i16
    ldx #$E000
find_first_eligible_monster_class_4_c10e18:
    jsr test_eligible_actor_id_at_least_83
    bcc find_first_eligible_monster_class_4_c10e24
    jsr classify_actor_squared_distance
    .a8
    cmp #$04
    beq find_first_eligible_monster_class_4_c10e36
find_first_eligible_monster_class_4_c10e24:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_eligible_monster_class_4_c10e18
    .a8
    lda #$FF
    bra find_first_eligible_monster_class_4_c10e39
find_first_eligible_monster_class_4_c10e36:
    jsr actor_slot_from_address_high_byte
find_first_eligible_monster_class_4_c10e39:
    sta $01,S
    pla
    plp
    pld
    rts
