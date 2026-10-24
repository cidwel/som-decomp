; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_seven_boss_lifecycle_states = $34FC

.segment "CODE"
.org $34D8
dispatch_boss_parent_or_custom_terminal_state:
    lda a:$0094,X
    .a16
    cmp #$0004
    bcc dispatch_seven_boss_lifecycle_states
    lda a:$004C,X
    beq dispatch_seven_boss_lifecycle_states
    sta $0C
    .a16
    lda #$00C2
    sta $0E
    lda a:$0094,X
    sec
    .a16
    sbc #$0004
    asl
    tay
    lda [$0C],Y
    sta $0C
    jmp ($020C)
