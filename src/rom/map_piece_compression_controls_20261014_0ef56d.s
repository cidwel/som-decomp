.setcpu "65816"
.segment "CODE"
.org $F56D
map_control_0ef56d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
