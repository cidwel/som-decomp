; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-parent-actions.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native58_body_part_order = $7C5F

.segment "CODE"
.org $7C38
cycle_native58_living_body_parts_and_dispatch_order:
    lda a:$0190,X
    bpl cycle_native58_living_body_parts_and_dispatch_order_c27c3e
    rts
cycle_native58_living_body_parts_and_dispatch_order_c27c3e:
    inc a:$00B0,X
    lda a:$00B0,X
    .a16
    cmp #$0003
    bcc cycle_native58_living_body_parts_and_dispatch_order_c27c4c
    stz a:$00B0,X
cycle_native58_living_body_parts_and_dispatch_order_c27c4c:
    lda a:$00B0,X
    xba
    asl
    clc
    .a16
    adc #$E600
    tay
    lda a:$0190,Y
    bmi cycle_native58_living_body_parts_and_dispatch_order_c27c3e
    jsr dispatch_native58_body_part_order
    rts
