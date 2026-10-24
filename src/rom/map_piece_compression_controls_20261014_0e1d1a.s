.setcpu "65816"
.segment "CODE"
.org $1D1A
map_control_0e1d1a:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
