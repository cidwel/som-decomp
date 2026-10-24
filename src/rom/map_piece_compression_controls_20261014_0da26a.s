.setcpu "65816"
.segment "CODE"
.org $A26A
map_control_0da26a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
