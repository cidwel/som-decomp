.setcpu "65816"
.segment "CODE"
.org $497A
map_control_0c497a:
    .byte $C1 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
