.setcpu "65816"
.segment "CODE"
.org $DEF7
map_control_0edef7:
    .byte $EA ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
