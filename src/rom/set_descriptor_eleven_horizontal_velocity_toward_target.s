; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8D42
set_descriptor_eleven_horizontal_velocity_toward_target:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$002B,X
    cmp a:$0002,Y
    bcc set_descriptor_eleven_horizontal_velocity_toward_target_c28d5b
    .a16
    lda #$FFFE
    sta a:$003C,X
    rts
set_descriptor_eleven_horizontal_velocity_toward_target_c28d5b:
    .a16
    lda #$0002
    sta a:$003C,X
    rts
