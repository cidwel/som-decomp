.setcpu "65816"
.segment "CODE"
.org $2286
map_control_0e2286:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
