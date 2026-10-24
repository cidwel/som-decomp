.setcpu "65816"
.segment "CODE"
.org $BBC8
map_control_0dbbc8:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
