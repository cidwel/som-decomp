; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-labels.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_selected_actor_field_offset = $66BF
format_and_append_native_saved_slot_decimal_pair = $5AFC
jump_native_spell_skill_percentage_api = $C00063

.segment "CODE"
.org $6619
append_native_spell_percentage_from_actor_skill_field:
    phx
    .i16
    ldx #$0050
    stx a:$A171
    jsr derive_native_selected_actor_field_offset
    lda a:$E180,X
    pha
    rep #$20
    lda f:$0019FE
    .a16
    and #$00FF
    xba
    asl
    tax
    lda a:$A175
    .a16
    and #$00FF
    tay
    sep #$20
    pla
    jsl f:jump_native_spell_skill_percentage_api
    rep #$20
    .a16
    and #$00FF
    tay
    sep #$20
    plx
    jsr format_and_append_native_saved_slot_decimal_pair
    rts
