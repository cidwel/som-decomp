; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-cast.md.
.setcpu "65816"
.smart
.a8
.i16

cast_spell_public_jump = $C0001B
routine_01800f = $1800F

.segment "CODE"
.org $82E4
cast_selected_spell_at_parent_target_and_execute_success:
    sta $97
    ldx $87
    lda a:$00B0,X
    sta $95
    tax
    sep #$20
    lda $97
    sta a:$0170,X
    .a8
    lda #$01
    sta a:$0176,X
    stz a:$0177,X
    lda a:$00A9,X
    inc
    sta a:$0178,X
    stz a:$0179,X
    stz a:$017A,X
    rep #$20
    ldx $95
    jsl f:cast_spell_public_jump
    .a16
    and #$00FF
    bne cast_selected_spell_at_parent_target_and_execute_success_c28321
    lda $95
    .a16
    and #$1FFF
    tax
    jsl f:routine_01800f
cast_selected_spell_at_parent_target_and_execute_success_c28321:
    rts
