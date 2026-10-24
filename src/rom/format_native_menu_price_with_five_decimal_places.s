; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_menu_digit_with_leading_zero_suppression = $D7FD
emit_one_menu_price_digit_by_repeated_word_subtraction = $D8C6

.segment "CODE"
.org $D89E
format_native_menu_price_with_five_decimal_places:
    rep #$30
    tay
    sep #$20
    .a8
    lda #$10
    trb a:$1802
    rep #$20
    .a16
    lda #$2710
    jsr emit_one_menu_price_digit_by_repeated_word_subtraction
    .a16
    lda #$03E8
    jsr emit_one_menu_price_digit_by_repeated_word_subtraction
    .a16
    lda #$0064
    jsr emit_one_menu_price_digit_by_repeated_word_subtraction
    .a16
    lda #$000A
    jsr emit_one_menu_price_digit_by_repeated_word_subtraction
    tya
    jmp append_native_menu_digit_with_leading_zero_suppression
