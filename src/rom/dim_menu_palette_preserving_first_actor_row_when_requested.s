; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

save_and_halve_one_menu_palette_color = $CD5C

.segment "CODE"
.org $CD35
dim_menu_palette_preserving_first_actor_row_when_requested:
    rep #$30
    .i16
    ldx #$0000
    .a16
    lda #$0001
    bit a:$1803
    bne dim_menu_palette_preserving_first_actor_row_when_requested_d0cd53
    jsr save_and_halve_one_menu_palette_color
dim_menu_palette_preserving_first_actor_row_when_requested_d0cd45:
    lda a:$0600,X
    sta f:$7E8000,X
    inx
    inx
    .i16
    cpx #$0020
    bcc dim_menu_palette_preserving_first_actor_row_when_requested_d0cd45
dim_menu_palette_preserving_first_actor_row_when_requested_d0cd53:
    jsr save_and_halve_one_menu_palette_color
    .i16
    cpx #$0100
    bcc dim_menu_palette_preserving_first_actor_row_when_requested_d0cd53
    rts
