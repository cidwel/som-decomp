.setcpu "65816"
.segment "CODE"
.org $DD96
map_control_0fdd96:
    .byte $E9 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
