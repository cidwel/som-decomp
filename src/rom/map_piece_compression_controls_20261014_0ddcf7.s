.setcpu "65816"
.segment "CODE"
.org $DCF7
map_control_0ddcf7:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
