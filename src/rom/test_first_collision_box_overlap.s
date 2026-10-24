; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $05F8
test_first_collision_box_overlap:
    lda $4A
    ora $4C
    beq test_first_collision_box_overlap_c2062b
    lda $46
    sec
    sbc $56
    bpl test_first_collision_box_overlap_c20609
    .a16
    eor #$FFFF
    inc
test_first_collision_box_overlap_c20609:
    sta $5E
    lda $4A
    clc
    adc $5A
    cmp $5E
    bcc test_first_collision_box_overlap_c2062b
    lda $48
    sec
    sbc $58
    bpl test_first_collision_box_overlap_c2061f
    .a16
    eor #$FFFF
    inc
test_first_collision_box_overlap_c2061f:
    sta $5E
    lda $4C
    clc
    adc $5C
    cmp $5E
    bcc test_first_collision_box_overlap_c2062b
    rts
test_first_collision_box_overlap_c2062b:
    clc
    rts
