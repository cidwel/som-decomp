.setcpu "65816"
.segment "CODE"
.org $FD32
map_control_0efd32:
    .byte $EC ; backreference distance high bits
    .byte $0A ; distance low bit/count
