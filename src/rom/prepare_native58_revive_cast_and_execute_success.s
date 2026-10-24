; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-cast.md.
.setcpu "65816"
.smart
.a8
.i16

cast_spell_public_jump = $C0001B
routine_01800f = $1800F

.segment "CODE"
.org $7DB5
prepare_native58_revive_cast_and_execute_success:
    ldx $87
    sep #$20
    .a8
    lda #$21
    sta a:$0170,X
    .a8
    lda #$01
    sta a:$0176,X
    stz a:$0177,X
    lda $95
    sta a:$0178,X
    stz a:$0179,X
    stz a:$017A,X
    rep #$20
    jsl f:cast_spell_public_jump
    .a16
    and #$00FF
    bne prepare_native58_revive_cast_and_execute_success_c27de6
    lda $87
    .a16
    and #$1FFF
    tax
    jsl f:routine_01800f
prepare_native58_revive_cast_and_execute_success_c27de6:
    rts
