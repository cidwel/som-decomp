; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16

select_boss_animation_and_reset_frame_cursor = $1394

.segment "CODE"
.org $8891
initialize_native59_mode7_matrix_center_and_control:
    ldx $87
    .a16
    lda #$0001
    sta a:$0000,X
    inc a:$0094,X
    .a16
    lda #$010F
    jsr select_boss_animation_and_reset_frame_cursor
    stz a:$00B0,X
    stz a:$00B2,X
    lda a:$00B8,X
    sta a:$00B4,X
    .a16
    lda #$0030
    sta a:$02D5
    .a16
    lda #$0020
    sta a:$02D7
    .a16
    lda #$0030
    sta a:$02D5
    .a16
    lda #$0020
    sta a:$02D7
    sep #$20
    .a8
    lda #$C0
    sta f:$00211A
    rep #$20
