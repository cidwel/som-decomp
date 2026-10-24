; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


ACTOR_FACING = $0010

.segment "CODE"
.org $0502
read_actor_facing_direction_code:
    phd
    php
    rep #$20
    sep #$20
    lda a:ACTOR_FACING,Y
    beq read_actor_facing_direction_code_c10519
    .a8
    cmp #$01
    beq read_actor_facing_direction_code_c1051d
    .a8
    cmp #$02
    beq read_actor_facing_direction_code_c10521
    .a8
    lda #$02
    bra read_actor_facing_direction_code_c10523
read_actor_facing_direction_code_c10519:
    .a8
    lda #$08
    bra read_actor_facing_direction_code_c10523
read_actor_facing_direction_code_c1051d:
    .a8
    lda #$04
    bra read_actor_facing_direction_code_c10523
read_actor_facing_direction_code_c10521:
    .a8
    lda #$01
read_actor_facing_direction_code_c10523:
    plp
    pld
    rts
