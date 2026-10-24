.setcpu "65816"
.segment "CODE"
.org $2471
map_control_0e2471:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
