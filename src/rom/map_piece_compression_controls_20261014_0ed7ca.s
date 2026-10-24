.setcpu "65816"
.segment "CODE"
.org $D7CA
map_control_0ed7ca:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
