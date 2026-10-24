.setcpu "65816"
.segment "CODE"
.org $F5B3
map_control_0ff5b3:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
