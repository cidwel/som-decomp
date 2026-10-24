.setcpu "65816"
.segment "CODE"
.org $42E4
map_control_0f42e4:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
