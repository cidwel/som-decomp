.setcpu "65816"
.segment "CODE"
.org $2B68
map_control_0d2b68:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
