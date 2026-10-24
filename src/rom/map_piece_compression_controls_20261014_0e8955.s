.setcpu "65816"
.segment "CODE"
.org $8955
map_control_0e8955:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
