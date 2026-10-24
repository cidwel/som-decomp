; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

append_menu_stat_value_and_separator = $D787
append_menu_stat_value_and_terminator = $D7A9
append_native_two_or_three_digit_menu_number = $D7B8

.segment "CODE"
.org $D66F
format_selected_equipment_current_and_candidate_stat:
    rep #$30
    .a16
    lda #$1559
    sta a:$19D4
    .i16
    ldx #$19D6
    lda a:$1803
    .a16
    and #$0080
    beq format_selected_equipment_current_and_candidate_stat_d0d693
    rep #$20
    .a16
    lda #$1359
    sta a:$19D4
    lda a:$1843
    .a16
    and #$00FF
    jsr append_native_two_or_three_digit_menu_number
format_selected_equipment_current_and_candidate_stat_d0d693:
    rep #$20
    .a16
    lda #$AAA7
    sta $00,X
    inx
    inx
    lda a:$1808
    .a16
    and #$0001
    beq format_selected_equipment_current_and_candidate_stat_d0d6b1
    lda f:$7EE386
    jsr append_menu_stat_value_and_separator
    lda f:$7EE387
    bra format_selected_equipment_current_and_candidate_stat_d0d6bc
format_selected_equipment_current_and_candidate_stat_d0d6b1:
    lda f:$7EE586
    jsr append_menu_stat_value_and_separator
    lda f:$7EE587
format_selected_equipment_current_and_candidate_stat_d0d6bc:
    jsr append_menu_stat_value_and_terminator
    rts
