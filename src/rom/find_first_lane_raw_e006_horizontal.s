; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
calculate_actor_direction_codes = $0404
reject_ineligible_or_nonmonster_actor = $058B

.segment "CODE"
.org $079D
find_first_lane_raw_e006_horizontal:
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
    ldx #$E006
find_first_lane_raw_e006_horizontal_c107ad:
    jsr reject_ineligible_or_nonmonster_actor
    bcs find_first_lane_raw_e006_horizontal_c107ba
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$FC
    beq find_first_lane_raw_e006_horizontal_c107cc
find_first_lane_raw_e006_horizontal_c107ba:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_lane_raw_e006_horizontal_c107ad
    .a8
    lda #$FF
    bra find_first_lane_raw_e006_horizontal_c107cf
find_first_lane_raw_e006_horizontal_c107cc:
    jsr actor_slot_from_address_high_byte
find_first_lane_raw_e006_horizontal_c107cf:
    sta $01,S
    pla
    plp
    pld
    rts
