.setcpu "65816"
.segment "CODE"
.org $B070
map_control_0fb070:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
