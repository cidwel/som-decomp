; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-geometry.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FC73
select_native_ring_quarter_wave_index_then_fall_through:
    tyx
