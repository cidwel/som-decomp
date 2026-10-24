.setcpu "65816"
.segment "CODE"
.org $B57F
map_control_0db57f:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
