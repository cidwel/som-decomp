; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-refresh.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_actor_stats_public_jump = $C00036

.segment "CODE"
.org $7A28
rebuild_native_equipped_actor_stats_and_cap_persistent_mana:
    php
    sep #$20
    phb
    .a8
    lda #$7E
    pha
    plb
    rep #$30
    phx
    jsl f:rebuild_actor_stats_public_jump
    plx
    txa
    xba
    lsr
    .a16
    and #$0003
    tay
    sep #$20
    lda a:$CC7D,Y
    cmp f:$7EE19C,X
    bcc rebuild_native_equipped_actor_stats_and_cap_persistent_mana_c07a51
    lda f:$7EE19C,X
    sta a:$CC7D,Y
rebuild_native_equipped_actor_stats_and_cap_persistent_mana_c07a51:
    plb
    plp
    rts
