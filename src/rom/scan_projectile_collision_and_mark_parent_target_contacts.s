; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

scan_three_party_collision_targets_for_boss = $05BF

.segment "CODE"
.org $3CE8
scan_projectile_collision_and_mark_parent_target_contacts:
    jsr scan_three_party_collision_targets_for_boss
    bcc scan_projectile_collision_and_mark_parent_target_contacts_c23d30
    ldy a:$00B0,X
    sep #$20
    ldx $24
    lda f:$C205F0,X
    and a:$005A,Y
    bne scan_projectile_collision_and_mark_parent_target_contacts_c23d30
    lda f:$C205F0,X
    ora a:$005A,Y
    sta a:$005A,Y
    rep #$20
    lda $24
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    ldx $87
    lda a:$00B0,X
    sec
    .a16
    sbc #$E600
    lsr
    xba
    tax
    lda f:$C205F0,X
    sep #$20
    ora a:$0059,Y
    sta a:$0059,Y
    rep #$20
    ldx $87
    sec
    rts
scan_projectile_collision_and_mark_parent_target_contacts_c23d30:
    rep #$20
    clc
    rts
