; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C0FD
write_ppu_queue_entries:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .a16
    lda #$2100
    sta $01
    .a16
    lda #$0000
    sta $03
    .i16
    ldy #$02DA
write_ppu_queue_entries_c11e:
    lda a:$0001,Y
    .a16
    and #$00FF
    beq write_ppu_queue_entries_c14e
    clc
    adc a:$02D6
    tay
    pha
    lda a:$0000,Y
    .a16
    and #$00FF
    tax
    lda a:$0002,Y
    sep #$20
    txy
    sta [$01],Y
    lda f:$7E603E,X
    beq write_ppu_queue_entries_c149
    .a8
    cmp #$01
    bne write_ppu_queue_entries_c146
    iny
write_ppu_queue_entries_c146:
    xba
    sta [$01],Y
write_ppu_queue_entries_c149:
    ply
    rep #$20
    bra write_ppu_queue_entries_c11e
write_ppu_queue_entries_c14e:
    .i16
    ldy #$02DE
write_ppu_queue_entries_c151:
    lda a:$0001,Y
    .a16
    and #$00FF
    beq write_ppu_queue_entries_c181
    clc
    adc a:$02D6
    tay
    pha
    lda a:$0000,Y
    .a16
    and #$00FF
    tax
    lda a:$0002,Y
    sep #$20
    txy
    sta [$01],Y
    lda f:$7E603E,X
    beq write_ppu_queue_entries_c17c
    .a8
    cmp #$01
    bne write_ppu_queue_entries_c179
    iny
write_ppu_queue_entries_c179:
    xba
    sta [$01],Y
write_ppu_queue_entries_c17c:
    ply
    rep #$20
    bra write_ppu_queue_entries_c151
write_ppu_queue_entries_c181:
    plb
    sep #$20
    pla
    pla
    pla
    pla
    plp
    pld
    rts
