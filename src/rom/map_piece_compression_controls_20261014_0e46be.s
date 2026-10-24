.setcpu "65816"
.segment "CODE"
.org $46BE
map_control_0e46be:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
