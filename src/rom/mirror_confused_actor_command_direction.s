; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_COMMAND = $0140
ACTOR_COMMAND_DIRECTION = $0141
ACTOR_STATUS = $0190

.segment "CODE"
.org $24D7
mirror_confused_actor_command_direction:
    phd
    php
    rep #$20
    phb
    tsc
    tcd
    sep #$20
    lda a:ACTOR_COMMAND,Y
    .a8
    cmp #$C1
    beq mirror_confused_actor_command_direction_c124eb
    .a8
    cmp #$40
    bne mirror_confused_actor_command_direction_c12514
mirror_confused_actor_command_direction_c124eb:
    lda a:ACTOR_STATUS,Y
    .a8
    and #$80
    beq mirror_confused_actor_command_direction_c12514
    stz $01
    lda a:ACTOR_COMMAND_DIRECTION,Y
    .a8
    bit #$0C
    beq mirror_confused_actor_command_direction_c12502
    .a8
    lda #$0C
    sta $01
    lda a:ACTOR_COMMAND_DIRECTION,Y
mirror_confused_actor_command_direction_c12502:
    .a8
    bit #$03
    beq mirror_confused_actor_command_direction_c1250f
    .a8
    lda #$03
    ora $01
    sta $01
    lda a:ACTOR_COMMAND_DIRECTION,Y
mirror_confused_actor_command_direction_c1250f:
    eor $01
    sta a:ACTOR_COMMAND_DIRECTION,Y
mirror_confused_actor_command_direction_c12514:
    sta $01,S
    pla
    plp
    pld
    rts
