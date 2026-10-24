.setcpu "65816"
.segment "CODE"
.org $9CF3
map_control_0e9cf3:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E3 ; previous-row copy count
