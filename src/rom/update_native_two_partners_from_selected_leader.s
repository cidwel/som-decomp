; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16

compute_native_wrapped_partner_steering_velocity = $F124
routine_01b729 = $1B729

.segment "CODE"
.org $EE8C
update_native_two_partners_from_selected_leader:
    sep #$20
    lda $4E
    beq update_native_two_partners_from_selected_leader_c0ee9e
    lda $D5
    .a8
    and #$07
    beq update_native_two_partners_from_selected_leader_c0eece
    .a8
    cmp #$02
    beq update_native_two_partners_from_selected_leader_c0eee0
    bra update_native_two_partners_from_selected_leader_c0eef2
update_native_two_partners_from_selected_leader_c0ee9e:
    lda $F1
    beq update_native_two_partners_from_selected_leader_c0eea3
    rts
update_native_two_partners_from_selected_leader_c0eea3:
    lda $D9
    .a8
    and #$0F
    beq update_native_two_partners_from_selected_leader_c0eeb1
    lsr
    bcs update_native_two_partners_from_selected_leader_c0eece
    lsr
    bcs update_native_two_partners_from_selected_leader_c0eee0
    bra update_native_two_partners_from_selected_leader_c0eef2
update_native_two_partners_from_selected_leader_c0eeb1:
    lda $DA
    .a8
    and #$0F
    beq update_native_two_partners_from_selected_leader_c0eebf
    lsr
    bcs update_native_two_partners_from_selected_leader_c0eece
    lsr
    bcs update_native_two_partners_from_selected_leader_c0eee0
    bra update_native_two_partners_from_selected_leader_c0eef2
update_native_two_partners_from_selected_leader_c0eebf:
    lda $DB
    .a8
    and #$0F
    beq update_native_two_partners_from_selected_leader_c0eecd
    lsr
    bcs update_native_two_partners_from_selected_leader_c0eece
    lsr
    bcs update_native_two_partners_from_selected_leader_c0eee0
    bra update_native_two_partners_from_selected_leader_c0eef2
update_native_two_partners_from_selected_leader_c0eecd:
    rts
update_native_two_partners_from_selected_leader_c0eece:
    rep #$30
    .i16
    ldx #$0000
    .i16
    ldy #$0200
    sty $14
    .i16
    ldy #$0400
    .a16
    lda #$0000
    bra update_native_two_partners_from_selected_leader_c0ef02
update_native_two_partners_from_selected_leader_c0eee0:
    rep #$30
    .i16
    ldx #$0200
    .i16
    ldy #$0400
    sty $14
    .i16
    ldy #$0000
    .a16
    lda #$0200
    bra update_native_two_partners_from_selected_leader_c0ef02
update_native_two_partners_from_selected_leader_c0eef2:
    rep #$30
    .i16
    ldx #$0400
    .i16
    ldy #$0200
    sty $14
    .i16
    ldy #$0000
    .a16
    lda #$0400
update_native_two_partners_from_selected_leader_c0ef02:
    sta $BA
    stx $12
    lda a:$E002,X
    sta $1C
    lda a:$E004,X
    sta $1E
    lda a:$E006,X
    .a16
    and #$7F7F
    sta $16
    lda $4E
    bne update_native_two_partners_from_selected_leader_c0ef24
    lda a:$E00B,X
    .a16
    and #$0008
    beq update_native_two_partners_from_selected_leader_c0ef2a
update_native_two_partners_from_selected_leader_c0ef24:
    stz $18
    stz $1A
    bra update_native_two_partners_from_selected_leader_c0ef51
update_native_two_partners_from_selected_leader_c0ef2a:
    .a16
    lda #$0040
    sta $18
    .a16
    lda #$0040
    sta $1A
    lda $16
    beq update_native_two_partners_from_selected_leader_c0ef51
    .a16
    and #$007F
    beq update_native_two_partners_from_selected_leader_c0ef48
    lda $16
    .a16
    and #$7F00
    bne update_native_two_partners_from_selected_leader_c0ef51
    stz $1A
    bra update_native_two_partners_from_selected_leader_c0ef51
update_native_two_partners_from_selected_leader_c0ef48:
    lda $16
    .a16
    and #$7F00
    beq update_native_two_partners_from_selected_leader_c0ef51
    stz $18
update_native_two_partners_from_selected_leader_c0ef51:
    sep #$20
    lda $F1
    and $4E
    bmi update_native_two_partners_from_selected_leader_c0ef67
    lda a:$E02C,Y
    ora a:$E01C,Y
    ora a:$E060,Y
    ora a:$E067,Y
    bne update_native_two_partners_from_selected_leader_c0efc3
update_native_two_partners_from_selected_leader_c0ef67:
    lda a:$E000,Y
    beq update_native_two_partners_from_selected_leader_c0efc3
    bmi update_native_two_partners_from_selected_leader_c0efc3
    lda a:$E00A,Y
    bne update_native_two_partners_from_selected_leader_c0efc3
    rep #$20
    lda a:$E002,Y
    sta $0C
    lda a:$E004,Y
    sta $0E
    phy
    jsr compute_native_wrapped_partner_steering_velocity
    rep #$30
    ply
    lda $06
    bne update_native_two_partners_from_selected_leader_c0ef94
    sta a:$E006,Y
    sep #$20
    sta a:$E02D,Y
    bra update_native_two_partners_from_selected_leader_c0efaf
update_native_two_partners_from_selected_leader_c0ef94:
    sep #$20
    lda a:$E02D,Y
    .a8
    cmp #$06
    bcc update_native_two_partners_from_selected_leader_c0efa8
    .a8
    lda #$00
    sta a:$E02D,Y
    jsl f:routine_01b729
    bra update_native_two_partners_from_selected_leader_c0efaf
update_native_two_partners_from_selected_leader_c0efa8:
    rep #$20
    lda $06
    sta a:$E006,Y
update_native_two_partners_from_selected_leader_c0efaf:
    rep #$20
    lda $18
    beq update_native_two_partners_from_selected_leader_c0efba
    .a16
    lda #$0080
    sta $18
update_native_two_partners_from_selected_leader_c0efba:
    lda $1A
    beq update_native_two_partners_from_selected_leader_c0efc3
    .a16
    lda #$0080
    sta $1A
update_native_two_partners_from_selected_leader_c0efc3:
    rep #$30
    ldy $14
    sep #$20
    lda $F1
    and $4E
    bmi update_native_two_partners_from_selected_leader_c0efdd
    lda a:$E02C,Y
    ora a:$E01C,Y
    ora a:$E060,Y
    ora a:$E067,Y
    bne update_native_two_partners_from_selected_leader_c0f024
update_native_two_partners_from_selected_leader_c0efdd:
    lda a:$E000,Y
    beq update_native_two_partners_from_selected_leader_c0f024
    bmi update_native_two_partners_from_selected_leader_c0f024
    lda a:$E00A,Y
    bne update_native_two_partners_from_selected_leader_c0f024
    rep #$20
    lda a:$E002,Y
    sta $0C
    lda a:$E004,Y
    sta $0E
    phy
    jsr compute_native_wrapped_partner_steering_velocity
    rep #$30
    ply
    lda $06
    bne update_native_two_partners_from_selected_leader_c0f00a
    sta a:$E006,Y
    sep #$20
    sta a:$E02D,Y
    bra update_native_two_partners_from_selected_leader_c0f024
update_native_two_partners_from_selected_leader_c0f00a:
    sep #$20
    lda a:$E02D,Y
    .a8
    cmp #$06
    bcc update_native_two_partners_from_selected_leader_c0f01d
    .a8
    lda #$00
    sta a:$E02D,Y
    jsl f:routine_01b729
    rts
update_native_two_partners_from_selected_leader_c0f01d:
    rep #$20
    lda $06
    sta a:$E006,Y
update_native_two_partners_from_selected_leader_c0f024:
    rts
