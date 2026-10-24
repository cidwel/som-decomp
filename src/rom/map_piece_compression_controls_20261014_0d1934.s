.setcpu "65816"
.segment "CODE"
.org $1934
map_control_0d1934:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
