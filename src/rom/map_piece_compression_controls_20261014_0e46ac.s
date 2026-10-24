.setcpu "65816"
.segment "CODE"
.org $46AC
map_control_0e46ac:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
