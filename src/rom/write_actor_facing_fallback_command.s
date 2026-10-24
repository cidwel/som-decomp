; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

read_actor_facing_direction_code = $0502

ACTOR_COMMAND = $0140
ACTOR_COMMAND_DIRECTION = $0141
ACTOR_COMMAND_ARGUMENT_2 = $0142
ACTOR_COMMAND_ARGUMENT_3 = $0143

.segment "CODE"
.org $2534
write_actor_facing_fallback_command:
    phd
    php
    rep #$20
    sep #$20
    .a8
    lda #$C1
    sta a:ACTOR_COMMAND,Y
    jsr read_actor_facing_direction_code
    sta a:ACTOR_COMMAND_DIRECTION,Y
    .a8
    lda #$00
    sta a:ACTOR_COMMAND_ARGUMENT_2,Y
    .a8
    lda #$05
    sta a:ACTOR_COMMAND_ARGUMENT_3,Y
    plp
    pld
    rts
