.setcpu "65816"
.segment "CODE"
.org $2CC2
map_control_0e2cc2:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
