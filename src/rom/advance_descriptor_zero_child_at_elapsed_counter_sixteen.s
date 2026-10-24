; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero-child.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3E5A
advance_descriptor_zero_child_at_elapsed_counter_sixteen:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0010
    bcc advance_descriptor_zero_child_at_elapsed_counter_sixteen_c23e67
    inc a:$0094,X
advance_descriptor_zero_child_at_elapsed_counter_sixteen_c23e67:
    clc
    rts
