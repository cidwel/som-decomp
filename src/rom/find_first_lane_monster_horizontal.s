; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
calculate_actor_direction_codes = $0404
test_eligible_actor_id_at_least_83 = $0598

.segment "CODE"
.org $082D
find_first_lane_monster_horizontal:
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
find_first_lane_monster_horizontal_c1083d:
    jsr test_eligible_actor_id_at_least_83
    bcc find_first_lane_monster_horizontal_c1084a
    jsr calculate_actor_direction_codes
    xba
    .a8
    bit #$FC
    beq find_first_lane_monster_horizontal_c1085c
find_first_lane_monster_horizontal_c1084a:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_lane_monster_horizontal_c1083d
    .a8
    lda #$FF
    bra find_first_lane_monster_horizontal_c1085f
find_first_lane_monster_horizontal_c1085c:
    jsr actor_slot_from_address_high_byte
find_first_lane_monster_horizontal_c1085f:
    sta $01,S
    pla
    plp
    pld
    rts
