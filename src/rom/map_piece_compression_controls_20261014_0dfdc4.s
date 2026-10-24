.setcpu "65816"
.segment "CODE"
.org $FDC4
map_control_0dfdc4:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
