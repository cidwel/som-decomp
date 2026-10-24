; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-action-rows.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $794A
mark_selected_native_ring_row_and_return_owner_or_special_descriptor:
    sep #$30
    lda a:$180A
    asl
    pha
    asl
    asl
    asl
    tax
    lda a:$18C0,X
    .a8
    ora #$80
    sta a:$18C0,X
    pla
    tax
    lda a:$18A0,X
    dec
    tay
    lda a:$1880,X
    cmp f:$D8FF16
    bne mark_selected_native_ring_row_and_return_owner_or_special_descriptor_c0796f
    .i8
    ldy #$FE
mark_selected_native_ring_row_and_return_owner_or_special_descriptor_c0796f:
    tya
    rts
