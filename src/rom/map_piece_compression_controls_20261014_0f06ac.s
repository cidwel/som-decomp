.setcpu "65816"
.segment "CODE"
.org $06AC
map_control_0f06ac:
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
    .byte $E3 ; previous-row copy count
