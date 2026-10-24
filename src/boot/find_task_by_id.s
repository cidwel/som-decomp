; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AD02
find_task_by_id:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    .a16
    and #$00FF
    beq find_task_by_id_ad36
    sta $01
    .i16
    ldy #$0014
    ldx a:$009C
find_task_by_id_ad23:
    lda a:$0004,X
    .a16
    and #$00FF
    cmp $01
    beq find_task_by_id_ad39
    clc
    txa
    .a16
    adc #$0010
    tax
    dey
    bne find_task_by_id_ad23
find_task_by_id_ad36:
    .i16
    ldx #$0000
find_task_by_id_ad39:
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
