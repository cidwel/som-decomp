; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E2B5
actor_selected_effect_high_status_bit20:
    ldx $85
    lda a:$E191,X
    .a8
    ora #$20
    sta a:$E191,X
    rts
