; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D9BF
read_consumable_inventory_record:
    sep #$30
    .a8
    and #$0F
    tax
    lda f:$7ECC48,X
    rep #$30
    .a16
    and #$00FF
    rts
