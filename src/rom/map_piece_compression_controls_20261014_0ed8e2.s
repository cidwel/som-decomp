.setcpu "65816"
.segment "CODE"
.org $D8E2
map_control_0ed8e2:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
