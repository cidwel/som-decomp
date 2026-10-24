; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-icons.md.
.setcpu "65816"
.smart
.a8
.i16

jump_native_spell_item_icon_strip_api = $C06409

.segment "CODE"
.org $702F
terminate_and_publish_native_spell_item_icon_strip:
    .a8
    lda #$FF
    ldx a:$A178
    sta f:$000000,X
    .i16
    ldx #$4300
    jsl f:jump_native_spell_item_icon_strip_api
    rts
