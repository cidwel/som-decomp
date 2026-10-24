.setcpu "65816"
.segment "CODE"
.org $E8FF
map_control_0de8ff:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E2 ; previous-row copy count
