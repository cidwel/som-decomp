; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
classify_actor_squared_distance = $0358
test_eligible_actor_id_at_least_83 = $0598

.segment "CODE"
.org $0D7A
find_first_eligible_monster_class_1:
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
find_first_eligible_monster_class_1_c10d8a:
    jsr test_eligible_actor_id_at_least_83
    bcc find_first_eligible_monster_class_1_c10d96
    jsr classify_actor_squared_distance
    .a8
    cmp #$01
    beq find_first_eligible_monster_class_1_c10da8
find_first_eligible_monster_class_1_c10d96:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_eligible_monster_class_1_c10d8a
    .a8
    lda #$FF
    bra find_first_eligible_monster_class_1_c10dab
find_first_eligible_monster_class_1_c10da8:
    jsr actor_slot_from_address_high_byte
find_first_eligible_monster_class_1_c10dab:
    sta $01,S
    pla
    plp
    pld
    rts
