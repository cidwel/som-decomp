; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-four-child-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6CD9
compare_descriptor_four_child_height_against_96:
    lda a:$0066,X
    .a16
    cmp #$0060
    rts
