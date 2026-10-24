.setcpu "65816"
.segment "CODE"
.org $DBD3
map_control_0fdbd3:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
