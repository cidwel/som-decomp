.setcpu "65816"
.segment "CODE"
.org $3A69
map_control_0d3a69:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
