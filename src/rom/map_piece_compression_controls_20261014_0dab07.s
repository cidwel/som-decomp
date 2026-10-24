.setcpu "65816"
.segment "CODE"
.org $AB07
map_control_0dab07:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
