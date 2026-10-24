.setcpu "65816"
.segment "CODE"
.org $19F6
map_control_0e19f6:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
