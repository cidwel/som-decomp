; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7BAE
advance_native58_after_initial_sixty_tick_wait:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$003C
    bcc advance_native58_after_initial_sixty_tick_wait_c27bbe
    inc a:$0094,X
    stz a:$0096,X
advance_native58_after_initial_sixty_tick_wait_c27bbe:
    clc
    rts
