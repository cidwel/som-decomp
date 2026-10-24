.setcpu "65816"
.segment "CODE"
.org $60C3
map_control_0e60c3:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
