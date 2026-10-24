.setcpu "65816"
.segment "CODE"
.org $F497
map_control_0ef497:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
