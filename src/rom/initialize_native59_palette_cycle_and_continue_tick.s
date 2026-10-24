; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $8A9D
initialize_native59_palette_cycle_and_continue_tick:
    ldx $87
    .a16
    lda #$00C0
    sta a:$002B,X
    .a16
    lda #$00C0
    sta a:$0032,X
    inc a:$0094,X
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$0173
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$00B0,X
    .a16
    lda #$0008
    sta a:$0070,X
    stz a:$0022,X
