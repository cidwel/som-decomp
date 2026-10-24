.setcpu "65816"
.segment "CODE"
.org $7643
map_control_0f7643:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
