; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
calculate_actor_direction_codes = $0404
reject_ineligible_or_nonmonster_actor = $058B

.segment "CODE"
.org $0755
find_first_lane_raw_e006_vertical:
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
find_first_lane_raw_e006_vertical_c10765:
    jsr reject_ineligible_or_nonmonster_actor
    bcs find_first_lane_raw_e006_vertical_c10772
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$F3
    beq find_first_lane_raw_e006_vertical_c10784
find_first_lane_raw_e006_vertical_c10772:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_lane_raw_e006_vertical_c10765
    .a8
    lda #$FF
    bra find_first_lane_raw_e006_vertical_c10787
find_first_lane_raw_e006_vertical_c10784:
    jsr actor_slot_from_address_high_byte
find_first_lane_raw_e006_vertical_c10787:
    sta $01,S
    pla
    plp
    pld
    rts
