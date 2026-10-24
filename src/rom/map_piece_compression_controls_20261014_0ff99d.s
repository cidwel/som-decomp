.setcpu "65816"
.segment "CODE"
.org $F99D
map_control_0ff99d:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
