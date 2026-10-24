; Recovered Secret of Mana USA routine; behaviour documented in docs/latent-dialogue-ring.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FFCE
clear_latent_dialogue_ring_line:
    ldx a:$A18F
    .a8
    lda #$40
clear_latent_dialogue_ring_line_c9ffd3:
    stz a:$9400,X
    inx
    dec
    bne clear_latent_dialogue_ring_line_c9ffd3
    rts
