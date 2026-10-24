.setcpu "65816"
.segment "CODE"
.org $1D76
map_control_0e1d76:
    .byte $E0 ; previous-row copy escape
    .byte $61 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
