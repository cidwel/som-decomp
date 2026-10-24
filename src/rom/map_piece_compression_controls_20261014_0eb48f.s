.setcpu "65816"
.segment "CODE"
.org $B48F
map_control_0eb48f:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
