.setcpu "65816"
.segment "CODE"
.org $1499
map_control_0e1499:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
