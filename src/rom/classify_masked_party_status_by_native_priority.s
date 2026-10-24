; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-target-status-queries.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $09D6
classify_masked_party_status_by_native_priority:
    sty $95
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0190,X
    beq classify_masked_party_status_by_native_priority_c20a21
    and $95
    sta $95
    .a16
    bit #$8000
    beq classify_masked_party_status_by_native_priority_c209f4
    .a16
    lda #$0000
    rts
classify_masked_party_status_by_native_priority_c209f4:
    .a16
    bit #$0200
    beq classify_masked_party_status_by_native_priority_c209fd
    .a16
    lda #$0001
    rts
classify_masked_party_status_by_native_priority_c209fd:
    .a16
    bit #$007F
    beq classify_masked_party_status_by_native_priority_c20a06
    .a16
    lda #$0002
    rts
classify_masked_party_status_by_native_priority_c20a06:
    .a16
    bit #$0180
    beq classify_masked_party_status_by_native_priority_c20a0f
    .a16
    lda #$0003
    rts
classify_masked_party_status_by_native_priority_c20a0f:
    .a16
    bit #$1C00
    beq classify_masked_party_status_by_native_priority_c20a18
    .a16
    lda #$0004
    rts
classify_masked_party_status_by_native_priority_c20a18:
    .a16
    bit #$6000
    beq classify_masked_party_status_by_native_priority_c20a21
    .a16
    lda #$0005
    rts
classify_masked_party_status_by_native_priority_c20a21:
    .a16
    lda #$FFFF
    rts
