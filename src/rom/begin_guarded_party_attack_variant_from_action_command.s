; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-action-commands.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00b295 = $B295
routine_c1d9c3 = $D9C3

.segment "CODE"
.org $D9E3
begin_guarded_party_attack_variant_from_action_command:
    .i16
    cpx #$0600
    bcs routine_c1d9c3
    bit $ED
    bpl routine_c1d9c3
    lda a:$E01A,X
    ora a:$E01B,X
    bne routine_c1d9c3
    .a8
    lda #$80
    sta a:$E064,X
    sta a:$E085,X
    jml f:routine_00b295
