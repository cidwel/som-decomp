.setcpu "65816"
.segment "CODE"
.org $DBF4
map_control_0edbf4:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
