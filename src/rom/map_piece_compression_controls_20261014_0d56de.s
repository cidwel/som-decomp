.setcpu "65816"
.segment "CODE"
.org $56DE
map_control_0d56de:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
