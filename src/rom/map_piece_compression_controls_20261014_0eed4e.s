.setcpu "65816"
.segment "CODE"
.org $ED4E
map_control_0eed4e:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
