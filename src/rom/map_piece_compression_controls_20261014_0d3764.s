.setcpu "65816"
.segment "CODE"
.org $3764
map_control_0d3764:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
