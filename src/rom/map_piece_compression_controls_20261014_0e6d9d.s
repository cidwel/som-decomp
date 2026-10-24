.setcpu "65816"
.segment "CODE"
.org $6D9D
map_control_0e6d9d:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
