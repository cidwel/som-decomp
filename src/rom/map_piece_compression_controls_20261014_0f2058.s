.setcpu "65816"
.segment "CODE"
.org $2058
map_control_0f2058:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E7 ; previous-row copy count
