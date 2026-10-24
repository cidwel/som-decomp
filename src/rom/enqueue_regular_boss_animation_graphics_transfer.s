; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1B93
enqueue_regular_boss_animation_graphics_transfer:
    ldx $68
    sta a:$0ED5,X
    tax
    lda $68
    sta a:$0F55,X
    stx $6A
    lda $CA
    .a8
    cmp #$16
    bcs enqueue_regular_boss_animation_graphics_transfer_c21be3
    asl
    asl
    tax
    stx $68
    inc $CA
    lda $6A
    inc
    sta a:$0FA8
    rep #$20
    lda $6C
    asl
    asl
    asl
    asl
    asl
    .a16
    cmp #$2000
    bcc enqueue_regular_boss_animation_graphics_transfer_c21bc5
    clc
    .a16
    adc #$2000
enqueue_regular_boss_animation_graphics_transfer_c21bc5:
    clc
    .a16
    adc #$2000
    sta a:$0E7D,X
    lda $6A
    asl
    tax
    lda f:$D97F35,X
    asl
    asl
    asl
    asl
    clc
    .a16
    adc #$6000
    ldx $68
    sta a:$0E7F,X
    clc
    rts
enqueue_regular_boss_animation_graphics_transfer_c21be3:
    sec
    rts
