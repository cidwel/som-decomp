.setcpu "65816"
.segment "CODE"
.org $3210
map_control_0c3210:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
