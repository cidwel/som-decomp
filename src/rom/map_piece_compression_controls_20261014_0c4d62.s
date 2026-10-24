.setcpu "65816"
.segment "CODE"
.org $4D62
map_control_0c4d62:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
