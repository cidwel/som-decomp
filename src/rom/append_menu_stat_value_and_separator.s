; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_two_or_three_digit_menu_number = $D7B8

.segment "CODE"
.org $D787
append_menu_stat_value_and_separator:
    rep #$20
    .a16
    and #$00FF
    jsr append_native_two_or_three_digit_menu_number
    sep #$20
    lda a:$1809
    .a8
    cmp #$01
    bne append_menu_stat_value_and_separator_d0d7a0
    .a8
    lda #$C1
    sta $00,X
    inx
    rep #$20
    rts
append_menu_stat_value_and_separator_d0d7a0:
    rep #$20
    .a16
    lda #$00D0
    sta $00,X
    inx
    rts
