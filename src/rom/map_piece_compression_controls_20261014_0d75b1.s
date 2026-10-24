.setcpu "65816"
.segment "CODE"
.org $75B1
map_control_0d75b1:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
