; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4A53
reorder_actor_attribute_bit_pairs:
    lda a:$E193,X
    sta $A6
    sta a:$E1A3,X
    lda a:$E192,X
    stz a:$E1A2,X
    lda $A6
    asl
    .a8
    and #$2A
    sta $A4
    lda $A6
    lsr
    .a8
    and #$15
    ora $A4
    .a8
    and #$3F
    sta a:$E1A1,X
    rts
