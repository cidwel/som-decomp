; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-labels.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_selected_actor_field_offset = $66BF

.segment "CODE"
.org $6661
read_native_spell_class_availability_field:
    phx
    .i16
    ldx #$0048
    stx a:$A171
    jsr derive_native_selected_actor_field_offset
    lda a:$E180,X
    plx
    rts
