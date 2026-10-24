.setcpu "65816"
.segment "CODE"
.org $2286
map_control_0c2286:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
