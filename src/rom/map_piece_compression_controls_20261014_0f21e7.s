.setcpu "65816"
.segment "CODE"
.org $21E7
map_control_0f21e7:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E3 ; previous-row copy count
