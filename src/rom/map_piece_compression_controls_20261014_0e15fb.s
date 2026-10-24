.setcpu "65816"
.segment "CODE"
.org $15FB
map_control_0e15fb:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
