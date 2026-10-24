.setcpu "65816"
.segment "CODE"
.org $AFC7
map_control_0fafc7:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
