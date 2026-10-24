; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3D31
expire_combat_mixed_status_group_timer:
    rep #$20
    lda a:$E190,X
    .a16
    bit #$0180
    sep #$20
    beq expire_combat_mixed_status_group_timer_c03d4c
    dec a:$E1B3,X
    bne expire_combat_mixed_status_group_timer_c03d4c
    rep #$20
    .a16
    and #$FE7F
    sta a:$E190,X
    sep #$20
expire_combat_mixed_status_group_timer_c03d4c:
    rts
