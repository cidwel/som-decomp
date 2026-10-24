.setcpu "65816"
.segment "CODE"
.org $6587
map_control_0c6587:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
