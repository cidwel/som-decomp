; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-axis-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $773E
advance_descriptor_ten_global_axis_origins_by_velocity:
    lda a:$0358
    clc
    adc a:$003C,X
    sta a:$0358
    lda a:$035C
    clc
    adc a:$0040,X
    sta a:$035C
    rts
