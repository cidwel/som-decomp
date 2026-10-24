.setcpu "65816"
.segment "CODE"
.org $E480
map_control_0fe480:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
