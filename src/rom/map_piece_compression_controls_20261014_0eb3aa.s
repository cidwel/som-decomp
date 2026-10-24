.setcpu "65816"
.segment "CODE"
.org $B3AA
map_control_0eb3aa:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
