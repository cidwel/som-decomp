.setcpu "65816"
.segment "CODE"
.org $C4C6
map_control_0ec4c6:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
