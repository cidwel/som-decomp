.setcpu "65816"
.segment "CODE"
.org $9FC1
map_control_0d9fc1:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
