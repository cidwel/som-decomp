.setcpu "65816"
.segment "CODE"
.org $5AE2
map_control_0d5ae2:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
