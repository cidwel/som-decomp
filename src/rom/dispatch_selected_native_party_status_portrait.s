; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6AD2
dispatch_selected_native_party_status_portrait:
    .a8
    lda #$00
    xba
    lda f:$0019FE
    asl
    tax
    jsr ($6BDD,X)
    rts
