.setcpu "65816"
.segment "CODE"
.org $DBF0
map_control_0fdbf0:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
