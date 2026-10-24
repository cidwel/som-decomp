; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

select_next_task = $A948

.segment "CODE"
.org $AA22
complete_current_task:
    sep #$20
    sei
    .a8
    lda #$7F
    pha
    plb
    ldx a:$009E
    .a8
    lda #$10
    sta a:$0002,X
    rep #$20
    lda a:$00A4
    sta a:$0000,X
    stx a:$00A4
    dec a:$009A
    jmp select_next_task
