; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

scan_three_party_collision_targets_for_boss = $05BF

.segment "CODE"
.org $058F
mark_boss_secondary_contact_in_party_and_boss_masks:
    jsr scan_three_party_collision_targets_for_boss
    bcc mark_boss_secondary_contact_in_party_and_boss_masks_c205be
    ldx $8B
    lda $24
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    lda f:$C205F0,X
    ora a:$0059,Y
    sta a:$0059,Y
    ldx $24
    ldy $87
    lda f:$C205F0,X
    ora a:$005A,Y
    sta a:$005A,Y
    rep #$20
    ldx $87
    sec
mark_boss_secondary_contact_in_party_and_boss_masks_c205be:
    rts
