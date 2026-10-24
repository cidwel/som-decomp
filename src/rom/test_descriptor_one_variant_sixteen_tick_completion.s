; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-one-palette.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4467
test_descriptor_one_variant_sixteen_tick_completion:
    lda a:$0042,X
    beq test_descriptor_one_variant_sixteen_tick_completion_c24475
    lda a:$0096,X
    .a16
    cmp #$0010
    bcs test_descriptor_one_variant_sixteen_tick_completion_c24475
    rts
test_descriptor_one_variant_sixteen_tick_completion_c24475:
    sec
    rts
