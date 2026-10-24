; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-geometry.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FC50
negate_native_ring_component_then_accumulate_vertical_center:
    .a16
    eor #$FFFF
    inc
