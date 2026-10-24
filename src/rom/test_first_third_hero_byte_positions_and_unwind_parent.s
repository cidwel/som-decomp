; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-hero-link.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F0E0
test_first_third_hero_byte_positions_and_unwind_parent:
    lda a:$E000
    beq test_first_third_hero_byte_positions_and_unwind_parent_c0f0e7
    bpl test_first_third_hero_byte_positions_and_unwind_parent_c0f0ef
test_first_third_hero_byte_positions_and_unwind_parent_c0f0e7:
    rts
    lda a:$E400
    beq test_first_third_hero_byte_positions_and_unwind_parent_c0f101
    bmi test_first_third_hero_byte_positions_and_unwind_parent_c0f101
test_first_third_hero_byte_positions_and_unwind_parent_c0f0ef:
    lda a:$E002
    cmp a:$E402
    bne test_first_third_hero_byte_positions_and_unwind_parent_c0f0ff
    lda a:$E004
    cmp a:$E404
    beq test_first_third_hero_byte_positions_and_unwind_parent_c0f101
test_first_third_hero_byte_positions_and_unwind_parent_c0f0ff:
    pla
    pla
test_first_third_hero_byte_positions_and_unwind_parent_c0f101:
    rts
