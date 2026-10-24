; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

resolve_controller_hero_actor = $04D3
restart_actor_program = $263C

ACTOR_COMMAND = $0140
ACTOR_PROGRAM_CONTROL_FLAGS = $014C
ACTOR_STATUS = $0190
ACTOR_ID = $0180
ACTOR_FIELD_11 = $0011
ACTOR_FIELD_1C = $001C

.segment "CODE"
.org $2457
preempt_hero_program_for_controller_action:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    .a16
    lda #$0003
    sta $01
    .i16
    ldx #$E000
preempt_hero_program_for_controller_action_c12466:
    lda a:ACTOR_STATUS,X
    .a16
    and #$C57B
    bne preempt_hero_program_for_controller_action_c1249d
    clc
    txa
    .a16
    adc #$0200
    tax
    dec $01
    bne preempt_hero_program_for_controller_action_c12466
    sep #$20
    .a8
    lda #$03
    sta $01
preempt_hero_program_for_controller_action_c1247e:
    .a8
    lda #$03
    sec
    sbc $01
    jsr resolve_controller_hero_actor
    .i16
    cpx #$0000
    beq preempt_hero_program_for_controller_action_c12499
    lda a:ACTOR_FIELD_11,X
    .a8
    cmp #$02
    bne preempt_hero_program_for_controller_action_c12499
    lda a:ACTOR_FIELD_1C,X
    .a8
    cmp #$00
    beq preempt_hero_program_for_controller_action_c124ab
preempt_hero_program_for_controller_action_c12499:
    dec $01
    bne preempt_hero_program_for_controller_action_c1247e
preempt_hero_program_for_controller_action_c1249d:
    sep #$20
    lda a:ACTOR_PROGRAM_CONTROL_FLAGS,Y
    .a8
    and #$FD
    sta a:ACTOR_PROGRAM_CONTROL_FLAGS,Y
    .a8
    lda #$FF
    bra preempt_hero_program_for_controller_action_c124d0
preempt_hero_program_for_controller_action_c124ab:
    lda a:ACTOR_PROGRAM_CONTROL_FLAGS,Y
    pha
    lda a:ACTOR_ID,Y
    tyx
    phy
    jsr restart_actor_program
    ply
    pla
    .a8
    bit #$02
    beq preempt_hero_program_for_controller_action_c124c1
    .a8
    lda #$01
    bra preempt_hero_program_for_controller_action_c124c3
preempt_hero_program_for_controller_action_c124c1:
    .a8
    lda #$07
preempt_hero_program_for_controller_action_c124c3:
    sta a:ACTOR_COMMAND,Y
    lda a:ACTOR_PROGRAM_CONTROL_FLAGS,Y
    .a8
    ora #$02
    sta a:ACTOR_PROGRAM_CONTROL_FLAGS,Y
    .a8
    lda #$00
preempt_hero_program_for_controller_action_c124d0:
    sta $02,S
    pla
    pla
    plp
    pld
    rts
