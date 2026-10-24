.setcpu "65816"
.segment "CODE"
.org $66FB
map_control_0e66fb:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
