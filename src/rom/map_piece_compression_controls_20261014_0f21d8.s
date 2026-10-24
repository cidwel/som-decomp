.setcpu "65816"
.segment "CODE"
.org $21D8
map_control_0f21d8:
    .byte $C2 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
