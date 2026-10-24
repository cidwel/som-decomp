; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $47BD
reset_native54_radius_and_enter_recovery:
    ldx $87
    lda a:$009E,X
    bne reset_native54_radius_and_enter_recovery_c247d0
    .a16
    lda #$000B
    sta a:$0094,X
    stz a:$001E,X
    stz a:$0096,X
reset_native54_radius_and_enter_recovery_c247d0:
    clc
    rts
