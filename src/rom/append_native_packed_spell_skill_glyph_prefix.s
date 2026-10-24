; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-labels.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c76680 = $6680

.segment "CODE"
.org $6670
append_native_packed_spell_skill_glyph_prefix:
    phx
    .i16
    ldx #$0044
    stx a:$A171
    bra routine_c76680
