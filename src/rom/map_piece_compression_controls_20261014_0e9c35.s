.setcpu "65816"
.segment "CODE"
.org $9C35
map_control_0e9c35:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
