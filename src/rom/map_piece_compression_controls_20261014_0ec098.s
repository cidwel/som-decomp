.setcpu "65816"
.segment "CODE"
.org $C098
map_control_0ec098:
    .byte $E5 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
