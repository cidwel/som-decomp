; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3D1C
expire_combat_low_status_group_timer:
    lda a:$E190,X
    .a8
    bit #$7E
    beq expire_combat_low_status_group_timer_c03d30
    dec a:$E1B2,X
    bne expire_combat_low_status_group_timer_c03d30
    lda a:$E190,X
    .a8
    and #$83
    sta a:$E190,X
expire_combat_low_status_group_timer_c03d30:
    rts
