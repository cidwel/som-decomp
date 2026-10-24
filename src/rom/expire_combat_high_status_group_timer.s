; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3D4D
expire_combat_high_status_group_timer:
    lda a:$E191,X
    .a8
    bit #$18
    beq expire_combat_high_status_group_timer_c03d5e
    dec a:$E1B5,X
    bne expire_combat_high_status_group_timer_c03d5e
    .a8
    and #$E7
    sta a:$E191,X
expire_combat_high_status_group_timer_c03d5e:
    rts
