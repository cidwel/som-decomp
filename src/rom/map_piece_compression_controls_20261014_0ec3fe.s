.setcpu "65816"
.segment "CODE"
.org $C3FE
map_control_0ec3fe:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
