.setcpu "65816"
.segment "CODE"
.org $B0CD
map_control_0fb0cd:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
