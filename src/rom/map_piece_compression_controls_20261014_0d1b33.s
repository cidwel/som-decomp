.setcpu "65816"
.segment "CODE"
.org $1B33
map_control_0d1b33:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
