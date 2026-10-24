; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-detail.md.
.setcpu "65816"
.smart
.a8
.i16

compose_native_selected_item_detail_tokens = $6411
compose_native_selected_spell_class_detail_tokens = $649E

.segment "CODE"
.org $6401
dispatch_native_spell_or_item_detail_publication:
    lda a:$A202
    .a8
    cmp #$08
    bne dispatch_native_spell_or_item_detail_publication_c7640d
    jsr compose_native_selected_spell_class_detail_tokens
    bra dispatch_native_spell_or_item_detail_publication_c76410
dispatch_native_spell_or_item_detail_publication_c7640d:
    jsr compose_native_selected_item_detail_tokens
dispatch_native_spell_or_item_detail_publication_c76410:
    rtl
