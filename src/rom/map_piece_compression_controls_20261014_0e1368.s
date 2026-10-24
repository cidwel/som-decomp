.setcpu "65816"
.segment "CODE"
.org $1368
map_control_0e1368:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $58 ; distance low bit/count
