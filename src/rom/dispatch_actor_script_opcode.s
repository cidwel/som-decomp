; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_PROGRAM_PC = $0144
ACTOR_SCRIPT_ROM_BASE = $D04F15
ACTOR_OPCODE_HANDLERS = $2257

.segment "CODE"
.org $251A
dispatch_actor_script_opcode:
    phd
    php
    rep #$20
    ldx a:ACTOR_PROGRAM_PC,Y
    lda f:ACTOR_SCRIPT_ROM_BASE,X
    .a16
    and #$00FF
    asl
    tax
    sep #$20
    jsr (ACTOR_OPCODE_HANDLERS,X)
    rep #$20
    plp
    pld
    rts
