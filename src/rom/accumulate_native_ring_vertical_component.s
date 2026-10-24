; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-geometry.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FC54
accumulate_native_ring_vertical_component:
    clc
    adc a:$186A
    sta a:$186A
    rts
