.setcpu "65816"
.segment "CODE"
.org $B6B5
map_control_0fb6b5:
    .byte $E0 ; previous-row copy escape
    .byte $52 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
