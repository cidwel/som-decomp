; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $950D
upload_complete_actor_frame_tiles:
    rep #$20
    sep #$10
    phd
    .a16
    lda #$4300
    tcd
    .i8
    ldx #$00
    stx $46
    stx $56
    stx $66
    stx $76
    .a16
    lda #$1801
    sta $40
    sta $50
    sta $60
    sta $70
    .i8
    ldx #$80
    stx a:$2115
    lda a:$0056
    asl
    tax
    ldy a:$00ED
    bne upload_complete_actor_frame_tiles_c1953d
    jmp ($955C,X)
upload_complete_actor_frame_tiles_c1953d:
    ldy a:$005C
    bpl upload_complete_actor_frame_tiles_c19545
    jmp ($9552,X)
upload_complete_actor_frame_tiles_c19545:
    jmp ($9548,X)
