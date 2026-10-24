.setcpu "65816"
.segment "CODE"
.org $523A
map_control_0d523a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
