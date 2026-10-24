; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_actor_script_opcode = $251A
mirror_confused_actor_command_direction = $24D7
preempt_hero_program_for_controller_action = $2457
restart_actor_program_on_script_error = $0100

ACTOR_COMMAND = $0140
ACTOR_PREVIOUS_COMMAND = $014D

.segment "CODE"
.org $2552
execute_actor_program_step:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    txa
    .a16
    and #$1FFF
    .a16
    ora #$E000
    tay
    .a16
    cmp #$E600
    sep #$20
    bcs execute_actor_program_step_c12578
    jsr preempt_hero_program_for_controller_action
    .a8
    cmp #$00
    beq execute_actor_program_step_c12588
execute_actor_program_step_c12578:
    stz $01
execute_actor_program_step_c1257a:
    jsr dispatch_actor_script_opcode
    .a8
    cmp #$00
    beq execute_actor_program_step_c12588
    dec $01
    bne execute_actor_program_step_c1257a
    jsr restart_actor_program_on_script_error
execute_actor_program_step_c12588:
    jsr mirror_confused_actor_command_direction
    lda a:ACTOR_COMMAND,Y
    sta a:ACTOR_PREVIOUS_COMMAND,Y
    plb
    sta $02,S
    pla
    pla
    plp
    pld
    rts
