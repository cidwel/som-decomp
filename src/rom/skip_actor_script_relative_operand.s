; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_PC = $0144
ACTOR_SCRIPT_ROM_BASE = $D04F15

.segment "CODE"
.org $01F7
skip_actor_script_relative_operand:
    phd
    php
    rep #$20
    sep #$20
    lda f:ACTOR_SCRIPT_ROM_BASE,X
    .a8
    bit #$80
    bne skip_actor_script_relative_operand_c10206
    inx
skip_actor_script_relative_operand_c10206:
    inx
    rep #$20
    txa
    sta a:ACTOR_PROGRAM_PC,Y
    .a16
    lda #$FFFF
    plp
    pld
    rts
