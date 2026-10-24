; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0690
test_second_collision_box_overlap:
    clc
    lda $52
    ora $54
    beq test_second_collision_box_overlap_c206c4
    lda $4E
    sec
    sbc $56
    bpl test_second_collision_box_overlap_c206a2
    .a16
    eor #$FFFF
    inc
test_second_collision_box_overlap_c206a2:
    sta $5E
    lda $52
    clc
    adc $5A
    cmp $5E
    bcc test_second_collision_box_overlap_c206c4
    lda $50
    sec
    sbc $58
    bpl test_second_collision_box_overlap_c206b8
    .a16
    eor #$FFFF
    inc
test_second_collision_box_overlap_c206b8:
    sta $5E
    lda $54
    clc
    adc $5C
    cmp $5E
    bcc test_second_collision_box_overlap_c206c4
    sec
test_second_collision_box_overlap_c206c4:
    rts
