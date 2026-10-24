.setcpu "65816"
.segment "CODE"
.org $62A2
map_control_0d62a2:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
