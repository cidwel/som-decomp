; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_actor_attributes_native = $C04530

.segment "CODE"
.org $3E80
rebuild_actor_stats_and_record_status_change_flags:
    sep #$20
    lda a:$E1FA,X
    .a8
    bit #$05
    beq rebuild_actor_stats_and_record_status_change_flags_c03e90
    stz a:$E19D,X
    jsl f:rebuild_actor_attributes_native
rebuild_actor_stats_and_record_status_change_flags_c03e90:
    lda a:$E1FA,X
    .a8
    bit #$02
    beq rebuild_actor_stats_and_record_status_change_flags_c03f02
    lda a:$E1FB,X
    .a8
    bit #$40
    bne rebuild_actor_stats_and_record_status_change_flags_c03f02
    rep #$20
    lda a:$E190,X
    eor a:$E19E,X
    tay
    bpl rebuild_actor_stats_and_record_status_change_flags_c03eb7
    lda a:$E1FA,X
    bpl rebuild_actor_stats_and_record_status_change_flags_c03eb7
    lda a:$E1B1,X
    .a16
    ora #$0008
    sta a:$E1B1,X
rebuild_actor_stats_and_record_status_change_flags_c03eb7:
    tya
    and a:$E190,X
    sta $AC
    .a16
    bit #$4160
    beq rebuild_actor_stats_and_record_status_change_flags_c03ecb
    lda a:$E1FB,X
    .a16
    ora #$0002
    sta a:$E1FB,X
rebuild_actor_stats_and_record_status_change_flags_c03ecb:
    lda a:$E02C,X
    .a16
    bit #$000F
    bne rebuild_actor_stats_and_record_status_change_flags_c03ee6
    lda $AC
    .a16
    bit #$5760
    beq rebuild_actor_stats_and_record_status_change_flags_c03ef7
    sep #$20
    lda a:$E1FB,X
    .a8
    ora #$08
    sta a:$E1FB,X
    bra rebuild_actor_stats_and_record_status_change_flags_c03ef7
rebuild_actor_stats_and_record_status_change_flags_c03ee6:
    lda $AC
    .a16
    bit #$4160
    beq rebuild_actor_stats_and_record_status_change_flags_c03ef7
    sep #$20
    lda a:$E1FB,X
    .a8
    ora #$08
    sta a:$E1FB,X
rebuild_actor_stats_and_record_status_change_flags_c03ef7:
    rep #$20
    lda a:$E190,X
    sta a:$E19E,X
    sep #$20
    rts
rebuild_actor_stats_and_record_status_change_flags_c03f02:
    sep #$20
    .i16
    ldy #$0000
    rts
