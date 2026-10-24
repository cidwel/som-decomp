; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-hero-link.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F102
test_second_third_hero_byte_positions_and_unwind_parent:
    lda a:$E200
    beq test_second_third_hero_byte_positions_and_unwind_parent_c0f109
    bpl test_second_third_hero_byte_positions_and_unwind_parent_c0f111
test_second_third_hero_byte_positions_and_unwind_parent_c0f109:
    rts
    lda a:$E400
    beq test_second_third_hero_byte_positions_and_unwind_parent_c0f123
    bmi test_second_third_hero_byte_positions_and_unwind_parent_c0f123
test_second_third_hero_byte_positions_and_unwind_parent_c0f111:
    lda a:$E202
    cmp a:$E402
    bne test_second_third_hero_byte_positions_and_unwind_parent_c0f121
    lda a:$E204
    cmp a:$E404
    beq test_second_third_hero_byte_positions_and_unwind_parent_c0f123
test_second_third_hero_byte_positions_and_unwind_parent_c0f121:
    pla
    pla
test_second_third_hero_byte_positions_and_unwind_parent_c0f123:
    rts
