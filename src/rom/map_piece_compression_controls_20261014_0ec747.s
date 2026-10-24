.setcpu "65816"
.segment "CODE"
.org $C747
map_control_0ec747:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
