.setcpu "65816"
.segment "CODE"
.org $20D8
map_control_0e20d8:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
