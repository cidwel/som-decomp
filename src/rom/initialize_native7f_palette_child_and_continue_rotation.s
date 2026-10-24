; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-setup.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $9879
initialize_native7f_palette_child_and_continue_rotation:
    ldx $87
    .a16
    lda #$0128
    sta a:$002B,X
    .a16
    lda #$0190
    sta a:$0032,X
    inc a:$0094,X
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$0172
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$00B0,X
    stz a:$0022,X
