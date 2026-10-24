.setcpu "65816"
.segment "CODE"
.org $59C6
map_control_0c59c6:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
