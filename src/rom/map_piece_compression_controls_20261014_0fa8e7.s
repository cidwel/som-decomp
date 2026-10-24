.setcpu "65816"
.segment "CODE"
.org $A8E7
map_control_0fa8e7:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
