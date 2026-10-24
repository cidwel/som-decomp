; Recovered Secret of Mana USA routine; behaviour documented in docs/latent-dialogue-ring.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FFB7
advance_latent_dialogue_ring_cursor:
    rep #$20
    lda a:$A18F
    clc
    .a16
    adc #$0080
    .a16
    cmp #$0800
    bcc advance_latent_dialogue_ring_cursor_c9ffc8
    .a16
    lda #$0002
advance_latent_dialogue_ring_cursor_c9ffc8:
    sta a:$A18F
    sep #$20
    rts
