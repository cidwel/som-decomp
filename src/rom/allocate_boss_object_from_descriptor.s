; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53

.segment "CODE"
.org $3438
allocate_boss_object_from_descriptor:
    asl
    tax
    .a16
    lda #$C200
    sta $0D
    lda f:$D0BC34,X
    sta $0C
    .i16
    ldy #$0000
    lda [$0C],Y
    iny
    iny
    phy
    tay
    .i16
    ldx #$34D8
    jsr allocate_boss_object_pool_slot
    ply
    lda [$0C],Y
    sta a:$0070,X
    iny
    iny
    lda [$0C],Y
    sta a:$00B4,X
    iny
    iny
    lda [$0C],Y
    sta a:$00B6,X
    iny
    iny
    lda [$0C],Y
    sta a:$00B8,X
    iny
    iny
    lda [$0C],Y
    sta a:$00BA,X
    iny
    iny
    lda [$0C],Y
    sta a:$00BC,X
    iny
    iny
    lda [$0C],Y
    sta a:$00BE,X
    iny
    iny
    lda [$0C],Y
    sta a:$0076,X
    iny
    iny
    lda [$0C],Y
    sta a:$00A7,X
    iny
    iny
    lda [$0C],Y
    sta a:$0078,X
    iny
    iny
    lda [$0C],Y
    sta a:$0062,X
    eor $C7
    inc
    sta a:$0045,X
    iny
    iny
    lda [$0C],Y
    sta a:$004C,X
    iny
    iny
    rts
