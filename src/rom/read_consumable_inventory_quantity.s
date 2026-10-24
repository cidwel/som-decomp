; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

read_consumable_inventory_record = $D9BF

.segment "CODE"
.org $D9B4
read_consumable_inventory_quantity:
    rep #$20
    jsr read_consumable_inventory_record
    lsr
    lsr
    lsr
    lsr
    lsr
    rts
