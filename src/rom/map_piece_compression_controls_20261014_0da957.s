.setcpu "65816"
.segment "CODE"
.org $A957
map_control_0da957:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
