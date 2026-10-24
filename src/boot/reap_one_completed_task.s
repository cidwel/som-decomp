; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b0d6 = $B0D6
clear_heap_units_by_task = $B0E8
clear_registrations_by_task = $CBDC
free_task_id_and_record = $AAD7
release_record_chain = $B23A
release_records_held_by_task = $B16F

.segment "CODE"
.org $A9C7
reap_one_completed_task:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    ldx a:$00A4
    beq reap_one_completed_task_aa1a
    lda a:$0000,X
    sta a:$00A4
    stx $01
    lda a:$0004,X
    jsr clear_heap_units_by_task
    ldx $01
    lda a:$0004,X
    jsr clear_registrations_by_task
    ldy $01
    ldx a:$000A,Y
    jsr release_record_chain
    ldx $01
    lda a:$0004,X
    jsr release_records_held_by_task
    ldy $01
    ldx a:$0008,Y
    beq reap_one_completed_task_aa0c
    jsr boot_b0d6
reap_one_completed_task_aa0c:
    ldx $01
    .a16
    lda #$0000
    sta a:$0002,X
    stz a:$0004,X
    jsr free_task_id_and_record
reap_one_completed_task_aa1a:
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
