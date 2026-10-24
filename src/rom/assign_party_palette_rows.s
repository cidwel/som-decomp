; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $DF96
assign_party_palette_rows:
    rep #$30
    .a16
    lda #$0022
    ldy $98
    beq assign_party_palette_rows_c1dfa2
    .a16
    eor #$0080
assign_party_palette_rows_c1dfa2:
    sta a:$E0F8
    clc
    .a16
    adc #$0020
    sta a:$E2F8
    clc
    .a16
    adc #$0020
    sta a:$E4F8
    .a16
    lda #$0002
    ldy $98
    beq assign_party_palette_rows_c1dfbd
    .a16
    eor #$0080
assign_party_palette_rows_c1dfbd:
    sta a:$E0FA
    clc
    .a16
    adc #$000A
    sta a:$E2FA
    clc
    .a16
    adc #$000A
    sta a:$E4FA
    rts
