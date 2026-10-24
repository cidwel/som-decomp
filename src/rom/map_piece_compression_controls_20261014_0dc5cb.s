.setcpu "65816"
.segment "CODE"
.org $C5CB
map_control_0dc5cb:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
