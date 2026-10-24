; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E2C0
actor_selected_effect_low_status_bit40:
    ldx $85
    .a8
    lda #$40
    ora a:$E190,X
    sta a:$E190,X
    rts
