.setcpu "65816"
.segment "CODE"
.org $A7FE
map_control_0ea7fe:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
