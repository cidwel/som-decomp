; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-child.md.
.setcpu "65816"
.smart
.a8
.i16

construct_linked_child_six_piece_strip_records = $5F60

.segment "CODE"
.org $59F7
initialize_linked_child_strip_storage_and_piece_records:
    stz a:$009E,X
    stz a:$0083,X
    stz a:$00BC,X
    stz a:$00BE,X
    stz a:$00C0,X
    stz a:$00C2,X
    stz a:$00B8,X
    stz a:$00BA,X
    stz a:$00B6,X
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$5CC8
    sta a:$008E,X
    .i16
    ldy #$0080
    lda a:$007A,X
    xba
    asl
    tax
    .a16
    lda #$0000
initialize_linked_child_strip_storage_and_piece_records_c25a2a:
    sta a:$F500,X
    inx
    inx
    dey
    bne initialize_linked_child_strip_storage_and_piece_records_c25a2a
    ldx $87
    jsr construct_linked_child_six_piece_strip_records
    clc
    rts
