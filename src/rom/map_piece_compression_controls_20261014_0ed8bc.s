.setcpu "65816"
.segment "CODE"
.org $D8BC
map_control_0ed8bc:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
