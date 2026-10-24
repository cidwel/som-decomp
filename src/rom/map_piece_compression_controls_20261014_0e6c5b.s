.setcpu "65816"
.segment "CODE"
.org $6C5B
map_control_0e6c5b:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
