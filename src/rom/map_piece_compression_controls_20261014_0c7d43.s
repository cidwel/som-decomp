.setcpu "65816"
.segment "CODE"
.org $7D43
map_control_0c7d43:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
