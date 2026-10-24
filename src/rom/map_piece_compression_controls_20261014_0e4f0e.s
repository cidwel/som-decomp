.setcpu "65816"
.segment "CODE"
.org $4F0E
map_control_0e4f0e:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
