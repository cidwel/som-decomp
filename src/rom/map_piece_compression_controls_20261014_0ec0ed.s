.setcpu "65816"
.segment "CODE"
.org $C0ED
map_control_0ec0ed:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
