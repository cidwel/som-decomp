.setcpu "65816"
.segment "CODE"
.org $5562
map_control_0d5562:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
