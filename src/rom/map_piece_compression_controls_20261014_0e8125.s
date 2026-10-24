.setcpu "65816"
.segment "CODE"
.org $8125
map_control_0e8125:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
