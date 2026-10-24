; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C0C2
count_ppu_queue_entries:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .i16
    ldx #$0000
    .i16
    ldy #$02DA
count_ppu_queue_entries_c0d5:
    lda a:$0001,Y
    .a16
    and #$00FF
    beq count_ppu_queue_entries_c0e5
    clc
    adc a:$02D6
    tay
    inx
    bra count_ppu_queue_entries_c0d5
count_ppu_queue_entries_c0e5:
    .i16
    ldy #$02DE
count_ppu_queue_entries_c0e8:
    lda a:$0001,Y
    .a16
    and #$00FF
    beq count_ppu_queue_entries_c0f8
    clc
    adc a:$02D6
    tay
    inx
    bra count_ppu_queue_entries_c0e8
count_ppu_queue_entries_c0f8:
    txa
    plb
    plp
    pld
    rts
