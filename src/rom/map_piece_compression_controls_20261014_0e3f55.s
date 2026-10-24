.setcpu "65816"
.segment "CODE"
.org $3F55
map_control_0e3f55:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5A ; row-distance/count
