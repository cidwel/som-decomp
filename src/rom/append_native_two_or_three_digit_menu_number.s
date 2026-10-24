; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_menu_digit_with_leading_zero_suppression = $D7FD
divide_and_append_native_menu_digit = $D7F9

.segment "CODE"
.org $D7B8
append_native_two_or_three_digit_menu_number:
    tay
    sep #$20
    .a8
    lda #$10
    tsb a:$1802
    lda a:$1809
    .a8
    cmp #$01
    beq append_native_two_or_three_digit_menu_number_d0d7d1
    .a8
    lda #$10
    trb a:$1802
    .a8
    lda #$64
    jsr divide_and_append_native_menu_digit
append_native_two_or_three_digit_menu_number_d0d7d1:
    sep #$20
    .a8
    lda #$0A
    jsr divide_and_append_native_menu_digit
    .a8
    lda #$10
    tsb a:$1802
    lda a:$4216
    bra append_native_menu_digit_with_leading_zero_suppression
