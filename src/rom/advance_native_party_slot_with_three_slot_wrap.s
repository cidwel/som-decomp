; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-page-callback.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6BC7
advance_native_party_slot_with_three_slot_wrap:
    inc
    .a8
    cmp #$03
    bne advance_native_party_slot_with_three_slot_wrap_c76bce
    .a8
    lda #$00
advance_native_party_slot_with_three_slot_wrap_c76bce:
    rtl
