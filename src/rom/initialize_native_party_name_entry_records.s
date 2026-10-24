; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-name-helpers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $51C2
initialize_native_party_name_entry_records:
    phb
    .a8
    lda #$7E
    pha
    plb
    .i16
    ldx #$0000
    .i16
    ldy #$0180
initialize_native_party_name_entry_records_c751cd:
    stz a:$E180,X
    stz a:$E380,X
    stz a:$E580,X
    inx
    dey
    bne initialize_native_party_name_entry_records_c751cd
    .a8
    lda #$80
    sta a:$E180
    sta a:$E1E7
    inc
    sta a:$E380
    sta a:$E3E7
    inc
    sta a:$E580
    sta a:$E5E7
    stz a:$CC6A
    stz a:$CC6B
    stz a:$CC6C
    stz a:$CC70
    .a8
    lda #$75
    sta a:$A25A
    stz a:$A25B
    .a8
    lda #$0F
    sta a:$A257
    sta a:$A258
    sta a:$A259
    stz $EE
    stz $EF
    stz $F0
    plb
    rts
