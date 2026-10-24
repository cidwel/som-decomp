.setcpu "65816"
.segment "CODE"
.org $0E45
map_control_0e0e45:
    .byte $C2 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
