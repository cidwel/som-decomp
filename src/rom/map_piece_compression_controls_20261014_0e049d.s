.setcpu "65816"
.segment "CODE"
.org $049D
map_control_0e049d:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
