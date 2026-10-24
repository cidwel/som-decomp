; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_slot_from_address_high_byte = $05CF
classify_actor_squared_distance = $0358
test_actor_target_eligibility = $054A



.segment "CODE"
.org $0AA3
find_first_eligible_hero_on_screen:
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
find_first_eligible_hero_on_screen_c10ab3:
    jsr test_actor_target_eligibility
    bne find_first_eligible_hero_on_screen_c10ac1
    jsr classify_actor_squared_distance
    .a8
    cmp #$30
    beq find_first_eligible_hero_on_screen_c10ad3
    bcc find_first_eligible_hero_on_screen_c10ad3
find_first_eligible_hero_on_screen_c10ac1:
    clc
    rep #$20
    txa
    .a16
    adc #$0200
    tax
    sep #$20
    dec $01
    bne find_first_eligible_hero_on_screen_c10ab3
    .a8
    lda #$FF
    bra find_first_eligible_hero_on_screen_c10ad6
find_first_eligible_hero_on_screen_c10ad3:
    jsr actor_slot_from_address_high_byte
find_first_eligible_hero_on_screen_c10ad6:
    sta $01,S
    pla
    plp
    pld
    rts
