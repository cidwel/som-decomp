.setcpu "65816"
.segment "CODE"
.org $D9EC
map_control_0ed9ec:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
