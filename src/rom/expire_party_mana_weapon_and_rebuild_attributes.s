; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

enqueue_actor_buff_expiration_notice = $C058B9
rebuild_actor_attributes_native = $C04530
select_actor_status_attack_row_long = $C8E5FB

.segment "CODE"
.org $3C88
expire_party_mana_weapon_and_rebuild_attributes:
    lda a:$CC77
    sta a:$E1E8
    jsl f:select_actor_status_attack_row_long
    lda a:$E1FA,X
    .a8
    ora #$04
    sta a:$E1FA,X
    jsl f:rebuild_actor_attributes_native
    jsl f:enqueue_actor_buff_expiration_notice
    ldx $85
    rts
