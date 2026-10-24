; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

test_actor_on_screen = $0526

ACTOR_SECOND_TARGET = $01AD

.segment "CODE"
.org $05BA
resolve_visible_second_actor_target:
    lda a:ACTOR_SECOND_TARGET,Y
    .a8
    cmp #$FF
    beq resolve_visible_second_actor_target_c105cc
    asl
    clc
    .a8
    adc #$E0
    xba
    .a8
    lda #$00
    tax
    jmp test_actor_on_screen
resolve_visible_second_actor_target_c105cc:
    .a8
    ora #$FF
    rts
