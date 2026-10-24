; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_two_or_three_digit_menu_number = $D7B8
routine_d0d7a5 = $D7A5

.segment "CODE"
.org $D7A9
append_menu_stat_value_and_terminator:
    rep #$20
    .a16
    and #$00FF
    jsr append_native_two_or_three_digit_menu_number
    rep #$20
    .a16
    lda #$0000
    bra routine_d0d7a5
