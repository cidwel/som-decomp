.setcpu "65816"
.segment "CODE"
.org $8DE0
map_control_0f8de0:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
