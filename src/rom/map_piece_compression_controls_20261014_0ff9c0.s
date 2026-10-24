.setcpu "65816"
.segment "CODE"
.org $F9C0
map_control_0ff9c0:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
