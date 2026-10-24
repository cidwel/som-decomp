.setcpu "65816"
.segment "CODE"
.org $3051
map_control_0e3051:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E3 ; previous-row copy count
