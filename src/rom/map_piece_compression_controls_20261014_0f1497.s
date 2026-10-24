.setcpu "65816"
.segment "CODE"
.org $1497
map_control_0f1497:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
