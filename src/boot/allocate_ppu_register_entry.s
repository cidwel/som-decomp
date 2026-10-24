; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C030
allocate_ppu_register_entry:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    ldx a:$02D8
    beq allocate_ppu_register_entry_c073
    php
    sei
    .a16
    and #$00FF
    pha
    lda a:$0000,X
    sta a:$02D8
    pla
    sta a:$0000,X
    txy
    tax
    lda f:$7E603E,X
    .a16
    and #$00FF
    beq allocate_ppu_register_entry_c065
    .a16
    cmp #$0001
    beq allocate_ppu_register_entry_c065
    tax
allocate_ppu_register_entry_c065:
    txa
    clc
    adc a:$02E2
    tax
    lda a:$0000,X
    sta a:$0002,Y
    tyx
    plp
allocate_ppu_register_entry_c073:
    plb
    plp
    pld
    rts
