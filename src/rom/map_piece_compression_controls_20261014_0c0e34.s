.setcpu "65816"
.segment "CODE"
.org $0E34
map_control_0c0e34:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $D1 ; row-distance/count
