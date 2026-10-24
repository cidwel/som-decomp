; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DECD
place_party_at_right_entry:
    rep #$10
    ldx $D4
    lda a:$E00B,X
    asl
    rep #$20
    lda $A8
    bcc place_party_at_right_entry_c1dedd
    lda $AC
place_party_at_right_entry_c1dedd:
    clc
    .a16
    adc #$0100
    cmp $C0
    bcc place_party_at_right_entry_c1dee7
    sbc $C0
place_party_at_right_entry_c1dee7:
    sta a:$E002
    sta a:$E202
    sta a:$E402
    .a16
    lda #$0082
