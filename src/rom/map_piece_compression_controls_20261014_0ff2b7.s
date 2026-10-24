.setcpu "65816"
.segment "CODE"
.org $F2B7
map_control_0ff2b7:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
