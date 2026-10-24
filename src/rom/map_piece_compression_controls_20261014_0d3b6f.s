.setcpu "65816"
.segment "CODE"
.org $3B6F
map_control_0d3b6f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
