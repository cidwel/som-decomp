.setcpu "65816"
.segment "CODE"
.org $63A7
map_control_0d63a7:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
