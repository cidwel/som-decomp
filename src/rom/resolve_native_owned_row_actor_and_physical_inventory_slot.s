; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-swap.md.
.setcpu "65816"
.smart
.a8
.i16

find_native_inventory_owner_wrapper = $76C7

.segment "CODE"
.org $7866
resolve_native_owned_row_actor_and_physical_inventory_slot:
    rep #$30
    .a16
    and #$00FF
    asl
    tax
    lda a:$18A0,X
    .a16
    and #$000F
    dec
    pha
    jsr find_native_inventory_owner_wrapper
    txy
    pla
    xba
    asl
    tax
    rts
