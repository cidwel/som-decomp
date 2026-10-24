.setcpu "65816"
.segment "CODE"
.org $3A17
map_control_0d3a17:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
