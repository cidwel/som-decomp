.setcpu "65816"
.segment "CODE"
.org $1A3C
map_control_0c1a3c:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
