.setcpu "65816"
.segment "CODE"
.org $250F
map_control_0e250f:
    .byte $CE ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
