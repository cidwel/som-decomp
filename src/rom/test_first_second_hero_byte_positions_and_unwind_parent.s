; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-hero-link.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $F0BE
test_first_second_hero_byte_positions_and_unwind_parent:
    lda a:$E000
    beq test_first_second_hero_byte_positions_and_unwind_parent_c0f0c5
    bpl test_first_second_hero_byte_positions_and_unwind_parent_c0f0cd
test_first_second_hero_byte_positions_and_unwind_parent_c0f0c5:
    rts
    lda a:$E200
    beq test_first_second_hero_byte_positions_and_unwind_parent_c0f0df
    bmi test_first_second_hero_byte_positions_and_unwind_parent_c0f0df
test_first_second_hero_byte_positions_and_unwind_parent_c0f0cd:
    lda a:$E002
    cmp a:$E202
    bne test_first_second_hero_byte_positions_and_unwind_parent_c0f0dd
    lda a:$E004
    cmp a:$E204
    beq test_first_second_hero_byte_positions_and_unwind_parent_c0f0df
test_first_second_hero_byte_positions_and_unwind_parent_c0f0dd:
    pla
    pla
test_first_second_hero_byte_positions_and_unwind_parent_c0f0df:
    rts
