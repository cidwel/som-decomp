; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-labels.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_selected_actor_field_offset = $66BF
format_and_append_native_saved_slot_decimal_pair = $5AFC

.segment "CODE"
.org $664E
append_native_spell_field_decimal_pair:
    phx
    .i16
    ldx #$0058
    stx a:$A171
    jsr derive_native_selected_actor_field_offset
    lda a:$E180,X
    tay
    plx
    jsr format_and_append_native_saved_slot_decimal_pair
    rts
