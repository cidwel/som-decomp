.setcpu "65816"
.segment "CODE"
.org $1CF2
map_control_0d1cf2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
