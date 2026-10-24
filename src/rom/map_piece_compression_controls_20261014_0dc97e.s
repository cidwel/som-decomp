.setcpu "65816"
.segment "CODE"
.org $C97E
map_control_0dc97e:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
