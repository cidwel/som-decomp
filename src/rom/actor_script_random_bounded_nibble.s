; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

actor_random_byte_with_preserved_bank = $26FB

ACTOR_PROGRAM_PC = $0144
ACTOR_SCRIPT_FIRST_ARGUMENT = $D04F16

.segment "CODE"
.org $16F4
actor_script_random_bounded_nibble:
    phd
    php
    rep #$20
    phb
    tsc
    tcd
    sep #$20
    phy
    ldx a:ACTOR_PROGRAM_PC,Y
    lda f:ACTOR_SCRIPT_FIRST_ARGUMENT,X
    .a8
    and #$0F
    beq actor_script_random_bounded_nibble_c11716
    sta $01
actor_script_random_bounded_nibble_c1170b:
    jsr actor_random_byte_with_preserved_bank
    .a8
    and #$0F
    cmp $01
    beq actor_script_random_bounded_nibble_c11716
    bcs actor_script_random_bounded_nibble_c1170b
actor_script_random_bounded_nibble_c11716:
    ply
    sta $01,S
    pla
    plp
    pld
    rts
