; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-geometry.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_native_ring_quarter_wave_by_radius = $FC74

.segment "CODE"
.org $FC5C
project_native_ring_complementary_quarter_wave_component:
    tya
    .a16
    ora #$0000
    beq project_native_ring_complementary_quarter_wave_component_d9fc6c
    .a16
    eor #$FFFF
    inc
    .a16
    and #$00FF
    tax
    bra multiply_native_ring_quarter_wave_by_radius
project_native_ring_complementary_quarter_wave_component_d9fc6c:
    lda a:$186E
    .a16
    and #$00FF
    rts
