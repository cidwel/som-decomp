; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
calculate_actor_direction_codes = $0404
test_actor_target_eligibility = $054A

.segment "CODE"
.org $070D
find_first_lane_hero_horizontal:
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
find_first_lane_hero_horizontal_c1071d:
    jsr test_actor_target_eligibility
    bne find_first_lane_hero_horizontal_c1072a
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$FC
    beq find_first_lane_hero_horizontal_c1073c
find_first_lane_hero_horizontal_c1072a:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_lane_hero_horizontal_c1071d
    .a8
    lda #$FF
    bra find_first_lane_hero_horizontal_c1073f
find_first_lane_hero_horizontal_c1073c:
    jsr actor_slot_from_address_high_byte
find_first_lane_hero_horizontal_c1073f:
    sta $01,S
    pla
    plp
    pld
    rts
