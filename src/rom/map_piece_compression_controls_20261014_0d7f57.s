.setcpu "65816"
.segment "CODE"
.org $7F57
map_control_0d7f57:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E6 ; previous-row copy count
