.setcpu "65816"
.segment "CODE"
.org $66BD
map_control_0e66bd:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
    .byte $E1 ; previous-row copy count
