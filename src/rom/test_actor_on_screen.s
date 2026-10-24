; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

read_actor_y_minus_height_x = $0343

ACTOR_ACTIVE = $0000
ACTOR_POSITION_X = $0020

.segment "CODE"
.org $0526
test_actor_on_screen:
    lda a:ACTOR_ACTIVE,X
    .a8
    cmp #$01
    bne test_actor_on_screen_c10549
    rep #$20
    lda a:ACTOR_POSITION_X,X
    .a16
    cmp #$0100
    bcs test_actor_on_screen_c10545
    jsr read_actor_y_minus_height_x
    .a16
    cmp #$00E0
    bcs test_actor_on_screen_c10545
    sep #$20
    .a8
    and #$00
    bra test_actor_on_screen_c10549
test_actor_on_screen_c10545:
    sep #$20
    .a8
    ora #$FF
test_actor_on_screen_c10549:
    rts
