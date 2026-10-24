.setcpu "65816"
.segment "CODE"
.org $6705
map_control_0e6705:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
