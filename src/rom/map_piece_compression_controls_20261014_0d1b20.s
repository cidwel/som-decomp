.setcpu "65816"
.segment "CODE"
.org $1B20
map_control_0d1b20:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
