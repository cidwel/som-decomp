; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-navigation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $317E
cancel_spell_item_selection_and_request_page_rebuild:
    .a8
    lda #$40
    trb a:$A20A
    .a8
    lda #$08
    trb a:$A212
    .a8
    lda #$01
    tsb a:$A20A
    rts
