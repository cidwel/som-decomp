.setcpu "65816"
.segment "CODE"
.org $9EF7
map_control_0e9ef7:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
