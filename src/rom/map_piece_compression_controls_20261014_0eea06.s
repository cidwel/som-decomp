.setcpu "65816"
.segment "CODE"
.org $EA06
map_control_0eea06:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
