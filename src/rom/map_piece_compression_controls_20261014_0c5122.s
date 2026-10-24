.setcpu "65816"
.segment "CODE"
.org $5122
map_control_0c5122:
    .byte $C4 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
