.setcpu "65816"
.segment "CODE"
.org $2029
map_control_0c2029:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
