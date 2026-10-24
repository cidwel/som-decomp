; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B0E8
clear_heap_units_by_task:
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
    xba
    .a8
    lda #$00
    sta $01
    xba
    .i16
    ldx #$0100
    txy
clear_heap_units_by_task_b104:
    dex
    cmp a:$01C4,X
    bne clear_heap_units_by_task_b111
    stz a:$00C4,X
    stz a:$01C4,X
    txy
clear_heap_units_by_task_b111:
    dec $01
    bne clear_heap_units_by_task_b104
    .i16
    cpy #$0100
    beq clear_heap_units_by_task_b123
    tya
    cmp a:$00C2
    bcs clear_heap_units_by_task_b123
    sta a:$00C2
clear_heap_units_by_task_b123:
    plb
    pla
    pla
    plp
    pld
    rts
