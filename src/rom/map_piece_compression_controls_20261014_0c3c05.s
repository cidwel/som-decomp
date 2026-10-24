.setcpu "65816"
.segment "CODE"
.org $3C05
map_control_0c3c05:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
