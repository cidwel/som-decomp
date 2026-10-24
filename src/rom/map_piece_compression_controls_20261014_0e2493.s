.setcpu "65816"
.segment "CODE"
.org $2493
map_control_0e2493:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
