; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-charge-hero-link.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0f0c6 = $F0C6
routine_c0f0e8 = $F0E8
routine_c0f10a = $F10A
test_first_second_hero_byte_positions_and_unwind_parent = $F0BE
test_first_third_hero_byte_positions_and_unwind_parent = $F0E0
test_second_third_hero_byte_positions_and_unwind_parent = $F102

.segment "CODE"
.org $F025
synchronize_linked_hero_fields_unless_native_byte_positions_differ:
    stz a:$E067
    stz a:$E267
    stz a:$E467
    lda $D5
    bne synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f04e
    bit $F1
    bmi synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f03b
    lda a:$E22C
    bne synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f03e
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f03b:
    jsr routine_c0f0c6
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f03e:
    bit $F1
    bmi synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f047
    lda a:$E42C
    bne synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f04a
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f047:
    jsr routine_c0f0e8
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f04a:
    stz $4E
    bra synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f088
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f04e:
    .a8
    cmp #$02
    bne synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f06e
    bit $F1
    bmi synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f05b
    lda a:$E02C
    bne synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f05e
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f05b:
    jsr test_first_second_hero_byte_positions_and_unwind_parent
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f05e:
    bit $F1
    bmi synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f067
    lda a:$E42C
    bne synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f06a
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f067:
    jsr routine_c0f10a
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f06a:
    stz $4E
    bra synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f088
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f06e:
    bit $F1
    bmi synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f077
    lda a:$E02C
    bne synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f07a
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f077:
    jsr test_first_third_hero_byte_positions_and_unwind_parent
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f07a:
    bit $F1
    bmi synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f083
    lda a:$E22C
    bne synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f086
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f083:
    jsr test_second_third_hero_byte_positions_and_unwind_parent
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f086:
    stz $4E
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f088:
    ldx $D4
    lda a:$E010,X
    sta a:$E010
    sta a:$E210
    sta a:$E410
    lda a:$E00B,X
    sta a:$E00B
    sta a:$E20B
    sta a:$E40B
    lda a:$E08E,X
    sta a:$E08E
    sta a:$E28E
    sta a:$E48E
    lda $FF
    bne synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f0bd
    rep #$20
    stz a:$E406
    stz a:$E206
    stz a:$E006
synchronize_linked_hero_fields_unless_native_byte_positions_differ_c0f0bd:
    rts
