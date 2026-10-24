; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $20ED
write_normal_boss_sprite_attributes:
    .i16
    ldy #$0002
    lda ($79),Y
    sta $9B
    .a16
    ora #$2000
    sta $97
    lda $97
    sta a:$0802,X
    sep #$30
    lda $95
    .a8
    and #$03
    tax
    lda f:$C221B3,X
    tay
    lda $95
    lsr
    lsr
    tax
    tya
    and a:$0A00,X
    sta a:$0A00,X
    lda $9A
    asl
    bcc write_normal_boss_sprite_attributes_c22131
    lda $95
    .a8
    and #$03
    tax
    lda f:$D97F2D,X
    tay
    lda $95
    lsr
    lsr
    tax
    tya
    ora a:$0A00,X
    sta a:$0A00,X
write_normal_boss_sprite_attributes_c22131:
    lda $9C
    .a8
    bit #$20
    beq write_normal_boss_sprite_attributes_c2214d
    lda $95
    .a8
    and #$03
    tax
    lda f:$D97F31,X
    tay
    lda $95
    lsr
    lsr
    tax
    tya
    ora a:$0A00,X
    sta a:$0A00,X
write_normal_boss_sprite_attributes_c2214d:
    rep #$30
    rts
