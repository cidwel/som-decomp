.setcpu "65816"
.segment "CODE"
.org $5D06
map_control_0d5d06:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
