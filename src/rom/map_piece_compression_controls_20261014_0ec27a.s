.setcpu "65816"
.segment "CODE"
.org $C27A
map_control_0ec27a:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $62 ; distance low bit/count
