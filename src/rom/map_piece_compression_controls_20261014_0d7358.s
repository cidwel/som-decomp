.setcpu "65816"
.segment "CODE"
.org $7358
map_control_0d7358:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
