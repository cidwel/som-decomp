.setcpu "65816"
.segment "CODE"
.org $18F3
map_control_0e18f3:
    .byte $DC ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
