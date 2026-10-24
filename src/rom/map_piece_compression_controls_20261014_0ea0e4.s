.setcpu "65816"
.segment "CODE"
.org $A0E4
map_control_0ea0e4:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
