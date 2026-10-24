.setcpu "65816"
.segment "CODE"
.org $9977
map_control_0f9977:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $77 ; distance low bit/count
