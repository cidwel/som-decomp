; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_PC = $0144
ACTOR_SCRIPT_ROM_BASE = $D04F15

.segment "CODE"
.org $0245
jump_actor_script_relative_operand:
    phd
    php
    rep #$20
    phx
    tsc
    tcd
    lda f:ACTOR_SCRIPT_ROM_BASE,X
    sep #$20
    .a8
    bit #$80
    beq jump_actor_script_relative_operand_c10266
    .a8
    bit #$40
    bne jump_actor_script_relative_operand_c10261
    .a8
    and #$7F
    xba
    .a8
    lda #$00
    bra jump_actor_script_relative_operand_c1026d
jump_actor_script_relative_operand_c10261:
    xba
    .a8
    lda #$FF
    bra jump_actor_script_relative_operand_c1026d
jump_actor_script_relative_operand_c10266:
    inx
    .a8
    bit #$40
    beq jump_actor_script_relative_operand_c1026d
    .a8
    ora #$80
jump_actor_script_relative_operand_c1026d:
    xba
    rep #$20
    inc
    stx $01
    clc
    adc $01
    sta a:ACTOR_PROGRAM_PC,Y
    .a16
    lda #$FFFF
    sep #$20
    sta $02,S
    pla
    pla
    plp
    pld
    rts
