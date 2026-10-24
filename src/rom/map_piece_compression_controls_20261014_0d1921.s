.setcpu "65816"
.segment "CODE"
.org $1921
map_control_0d1921:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
