; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

receive_with_supplied_delay = $ABE7
release_vertical_irq_use = $A241

.segment "CODE"
.org $A8BE
idle_until_tasks_complete:
    rep #$20
idle_until_tasks_complete_a8c0:
    .i16
    ldx #$0000
    jsr receive_with_supplied_delay
    lda a:$009A
    bne idle_until_tasks_complete_a8c0
    lda a:$0098
    tcs
    jsr release_vertical_irq_use
    plb
    plp
    pld
    rts
