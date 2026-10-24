; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-page.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c76309 = $6309

.segment "CODE"
.org $62FD
select_native_spell_page_description_and_enter_common_constructor:
    .a8
    lda #$06
    sta a:$A20F
    bra routine_c76309
