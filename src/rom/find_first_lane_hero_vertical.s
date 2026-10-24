; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
calculate_actor_direction_codes = $0404
test_actor_target_eligibility = $054A

.segment "CODE"
.org $06C5
find_first_lane_hero_vertical:
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
    ldx #$E000
find_first_lane_hero_vertical_c106d5:
    jsr test_actor_target_eligibility
    bne find_first_lane_hero_vertical_c106e2
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$F3
    beq find_first_lane_hero_vertical_c106f4
find_first_lane_hero_vertical_c106e2:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_lane_hero_vertical_c106d5
    .a8
    lda #$FF
    bra find_first_lane_hero_vertical_c106f7
find_first_lane_hero_vertical_c106f4:
    jsr actor_slot_from_address_high_byte
find_first_lane_hero_vertical_c106f7:
    sta $01,S
    pla
    plp
    pld
    rts
