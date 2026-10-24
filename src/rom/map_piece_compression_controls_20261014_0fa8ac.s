.setcpu "65816"
.segment "CODE"
.org $A8AC
map_control_0fa8ac:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $63 ; distance low bit/count
