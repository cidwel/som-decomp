; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
classify_actor_squared_distance = $0358
test_eligible_actor_id_at_least_83 = $0598

.segment "CODE"
.org $0E4F
find_first_eligible_monster_class_8:
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
find_first_eligible_monster_class_8_c10e5f:
    jsr test_eligible_actor_id_at_least_83
    bcc find_first_eligible_monster_class_8_c10e6b
    jsr classify_actor_squared_distance
    .a8
    cmp #$08
    beq find_first_eligible_monster_class_8_c10e7d
find_first_eligible_monster_class_8_c10e6b:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_eligible_monster_class_8_c10e5f
    .a8
    lda #$FF
    bra find_first_eligible_monster_class_8_c10e80
find_first_eligible_monster_class_8_c10e7d:
    jsr actor_slot_from_address_high_byte
find_first_eligible_monster_class_8_c10e80:
    sta $01,S
    pla
    plp
    pld
    rts
