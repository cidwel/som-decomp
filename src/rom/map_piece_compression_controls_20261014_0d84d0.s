.setcpu "65816"
.segment "CODE"
.org $84D0
map_control_0d84d0:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
