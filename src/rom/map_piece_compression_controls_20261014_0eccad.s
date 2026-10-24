.setcpu "65816"
.segment "CODE"
.org $CCAD
map_control_0eccad:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
