.setcpu "65816"
.segment "CODE"
.org $ED1B
map_control_0eed1b:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
