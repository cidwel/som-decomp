.setcpu "65816"
.segment "CODE"
.org $3934
map_control_0d3934:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
