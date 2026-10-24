.setcpu "65816"
.segment "CODE"
.org $2481
map_control_0e2481:
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
