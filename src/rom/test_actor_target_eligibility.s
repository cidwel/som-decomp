; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

read_actor_y_minus_height_x = $0343

ACTOR_ACTIVE = $0000
ACTOR_POSITION_X = $0020
ACTOR_STATUS = $0190

.segment "CODE"
.org $054A
test_actor_target_eligibility:
    lda a:ACTOR_ACTIVE,X
    .a8
    cmp #$01
    bne test_actor_target_eligibility_c1057d
    rep #$20
    phx
    tya
    cmp $01,S
    beq test_actor_target_eligibility_c10578
    plx
    lda a:ACTOR_POSITION_X,X
    .a16
    cmp #$0100
    bcs test_actor_target_eligibility_c10579
    jsr read_actor_y_minus_height_x
    .a16
    cmp #$00E0
    bcs test_actor_target_eligibility_c10579
    lda a:ACTOR_STATUS,X
    .a16
    and #$8460
    bne test_actor_target_eligibility_c10579
    sep #$20
    .a8
    and #$00
    bra test_actor_target_eligibility_c1057d
test_actor_target_eligibility_c10578:
    plx
test_actor_target_eligibility_c10579:
    sep #$20
    .a8
    ora #$FF
test_actor_target_eligibility_c1057d:
    rts
