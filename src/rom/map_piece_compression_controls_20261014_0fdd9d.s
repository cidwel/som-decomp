.setcpu "65816"
.segment "CODE"
.org $DD9D
map_control_0fdd9d:
    .byte $E9 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
