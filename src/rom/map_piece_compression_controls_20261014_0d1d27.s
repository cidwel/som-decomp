.setcpu "65816"
.segment "CODE"
.org $1D27
map_control_0d1d27:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
