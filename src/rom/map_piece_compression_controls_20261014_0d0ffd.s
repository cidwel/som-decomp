.setcpu "65816"
.segment "CODE"
.org $0FFD
map_control_0d0ffd:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
