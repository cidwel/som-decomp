.setcpu "65816"
.segment "CODE"
.org $B0B8
map_control_0fb0b8:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
