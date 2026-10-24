.setcpu "65816"
.segment "CODE"
.org $F155
map_control_0df155:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A7 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
