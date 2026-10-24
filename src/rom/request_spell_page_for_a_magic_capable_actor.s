; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-navigation.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c02d61 = $2D61

.segment "CODE"
.org $2D36
request_spell_page_for_a_magic_capable_actor:
    lda f:$0019FE
    beq request_spell_page_for_a_magic_capable_actor_c02d4f
    .a8
    lda #$08
    sta a:$A210
    lda a:$A211
    sta a:$A17A
    lda a:$A17B
    sta a:$A211
    bra routine_c02d61
request_spell_page_for_a_magic_capable_actor_c02d4f:
    rts
