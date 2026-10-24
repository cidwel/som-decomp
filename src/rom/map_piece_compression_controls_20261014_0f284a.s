.setcpu "65816"
.segment "CODE"
.org $284A
map_control_0f284a:
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
