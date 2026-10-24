.setcpu "65816"
.segment "CODE"
.org $42A9
map_control_0e42a9:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
