.setcpu "65816"
.segment "CODE"
.org $37FD
map_control_0d37fd:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
