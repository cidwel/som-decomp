.setcpu "65816"
.segment "CODE"
.org $ED13
map_control_0eed13:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
