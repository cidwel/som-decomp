.setcpu "65816"
.segment "CODE"
.org $31F0
map_control_0d31f0:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
