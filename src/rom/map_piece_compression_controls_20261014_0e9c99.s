.setcpu "65816"
.segment "CODE"
.org $9C99
map_control_0e9c99:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $C1 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $42 ; distance low bit/count
