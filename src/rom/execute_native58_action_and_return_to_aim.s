; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-parent-actions.md.
.setcpu "65816"
.smart
.a8
.i16

cycle_native58_living_body_parts_and_dispatch_order = $7C38

.segment "CODE"
.org $7C0C
execute_native58_action_and_return_to_aim:
    sep #$20
    lda a:$0380
    .a8
    and #$7F
    sta a:$0380
    rep #$20
    ldx $87
    jsr cycle_native58_living_body_parts_and_dispatch_order
    dec a:$0094,X
    clc
    rts
