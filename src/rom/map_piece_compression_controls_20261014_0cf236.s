.setcpu "65816"
.segment "CODE"
.org $F236
map_control_0cf236:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
