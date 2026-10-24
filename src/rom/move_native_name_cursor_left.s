; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-name-callbacks.md.
.setcpu "65816"
.smart
.a8
.i16

reset_native_name_repeat_timer_on_new_direction = $324A
routine_c03230 = $3230

.segment "CODE"
.org $3210
move_native_name_cursor_left:
    jsr reset_native_name_repeat_timer_on_new_direction
    lda a:$A159
    sec
    .a8
    sbc #$08
    .a8
    cmp #$13
    bcs routine_c03230
    .a8
    lda #$DB
    bra routine_c03230
