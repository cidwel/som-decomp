.setcpu "65816"
.segment "CODE"
.org $9C63
map_control_0e9c63:
    .byte $EC ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
