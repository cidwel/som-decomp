; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

set_actor_program_long = $C10020

.segment "CODE"
.org $BDA4
release_actor_controller_and_initialize_program:
    sep #$20
    .a8
    lda #$00
    sta f:$7EE02C,X
    sta f:$7EE08C,X
    sep #$20
    lda f:$7EE180,X
    jsl f:set_actor_program_long
    rts
