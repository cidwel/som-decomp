; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

enqueue_actor_buff_expiration_notice = $C058B9

.segment "CODE"
.org $3D91
expire_four_combat_buff_pairs_and_enqueue_notice:
    lda a:$E1B0,X
    php
    .a8
    bit #$03
    beq expire_four_combat_buff_pairs_and_enqueue_notice_c03da3
    dec a:$E1BC,X
    bne expire_four_combat_buff_pairs_and_enqueue_notice_c03da3
    .a8
    and #$FC
    sta a:$E1B0,X
expire_four_combat_buff_pairs_and_enqueue_notice_c03da3:
    .a8
    bit #$0C
    beq expire_four_combat_buff_pairs_and_enqueue_notice_c03db1
    dec a:$E1BB,X
    bne expire_four_combat_buff_pairs_and_enqueue_notice_c03db1
    .a8
    and #$F3
    sta a:$E1B0,X
expire_four_combat_buff_pairs_and_enqueue_notice_c03db1:
    .a8
    bit #$30
    beq expire_four_combat_buff_pairs_and_enqueue_notice_c03dbf
    dec a:$E1BA,X
    bne expire_four_combat_buff_pairs_and_enqueue_notice_c03dbf
    .a8
    and #$CF
    sta a:$E1B0,X
expire_four_combat_buff_pairs_and_enqueue_notice_c03dbf:
    .a8
    bit #$C0
    beq expire_four_combat_buff_pairs_and_enqueue_notice_c03dcd
    dec a:$E1B7,X
    bne expire_four_combat_buff_pairs_and_enqueue_notice_c03dcd
    .a8
    and #$3F
    sta a:$E1B0,X
expire_four_combat_buff_pairs_and_enqueue_notice_c03dcd:
    plp
    beq expire_four_combat_buff_pairs_and_enqueue_notice_c03ddb
    lda a:$E1B0,X
    bne expire_four_combat_buff_pairs_and_enqueue_notice_c03ddb
    jsl f:enqueue_actor_buff_expiration_notice
    ldx $85
expire_four_combat_buff_pairs_and_enqueue_notice_c03ddb:
    rts
