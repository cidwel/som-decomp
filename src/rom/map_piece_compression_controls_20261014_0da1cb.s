.setcpu "65816"
.segment "CODE"
.org $A1CB
map_control_0da1cb:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
