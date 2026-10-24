.setcpu "65816"
.segment "CODE"
.org $452F
map_control_0f452f:
    .byte $C3 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
