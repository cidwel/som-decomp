.setcpu "65816"
.segment "CODE"
.org $07FD
map_control_0f07fd:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
