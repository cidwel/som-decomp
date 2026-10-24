; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-validation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5C74
compare_native_save_primary_and_backup_payloads:
    lda a:$A216
    pha
    phb
    .a8
    lda #$30
    pha
    plb
    .i16
    ldx #$0000
    .a8
    lda #$04
    sta f:$7EA175
compare_native_save_primary_and_backup_payloads_c75c86:
    phx
    lda f:$7EA216
    ror
    bcs compare_native_save_primary_and_backup_payloads_c75cb0
    ror
    sta f:$7EA216
    bcs compare_native_save_primary_and_backup_payloads_c75cb5
    .i16
    ldy #$02BB
compare_native_save_primary_and_backup_payloads_c75c98:
    lda a:$6000,X
    cmp a:$7000,X
    bne compare_native_save_primary_and_backup_payloads_c75cb5
    inx
    dey
    bne compare_native_save_primary_and_backup_payloads_c75c98
    lda f:$7EA215
    ror
    ror
    sta f:$7EA215
    bra compare_native_save_primary_and_backup_payloads_c75cc1
compare_native_save_primary_and_backup_payloads_c75cb0:
    ror
    sta f:$7EA216
compare_native_save_primary_and_backup_payloads_c75cb5:
    lda f:$7EA215
    sec
    ror
    sec
    ror
    sta f:$7EA215
compare_native_save_primary_and_backup_payloads_c75cc1:
    rep #$20
    pla
    clc
    .a16
    adc #$0400
    tax
    sep #$20
    lda f:$7EA175
    dec
    sta f:$7EA175
    bne compare_native_save_primary_and_backup_payloads_c75c86
    plb
    pla
    sta a:$A216
    rts
